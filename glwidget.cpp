#include "glwidget.h"
//#include <GL/glut.h>
//#include <GL/glext.h>
#include <QTimer>
//#include <glm/glm.hpp>
#include <vector>
#include "DEFINE.h"
#include "reversi.h"
#include <iostream>
#include "gewinner.h"
#include <qlabel.h>
#include <QHBoxLayout>


using namespace std;

/**
 * Konstruiert ein GL-Widget, indem das komplette Reversispiel dargestellt wird.
 *
 * @param parent Die Angabe des Eltern-Widgets.
 */
GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    clearColor = Qt::black;

    frageSpielzug = true;
    winkel = 180;
    timer = new QTimer(this);
    animationSetting = true;
    animation = false;
    blue = true;
    spielfeld = NULL;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    spiel = new Reversi("Spieler1", "Spieler2");
    verbindeSpiel(spiel);

}

/**
 * Initialisiert das GL-Widget, mit einer schwarzen Hintergrundfarbe und laed die Textur des Spielbretts.
 */
void GLWidget::initializeGL()
{
    qglClearColor(clearColor);
    glEnable(GL_DEPTH_TEST);
    ladeTexturen();
    spielfeldLayout = makeSpielbrett();
}

/**
 * Laed die 2D-Texturen des Spielbretts, welche als PNG-Datei im Verzeichnis vorhanden sein muss.
 */
void GLWidget::ladeTexturen()
{
    QImage zwsp1;
    QImage zwsp2;
    if(blue)
        zwsp1.load("boardBlue.png");
    else
        zwsp1.load("boardYellow.png");
    zwsp2 = QGLWidget::convertToGLFormat(zwsp1);
    glGenTextures(1, &texturen[0]);
    glBindTexture(GL_TEXTURE_2D, texturen[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, zwsp2.width(), zwsp2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, zwsp2.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

/**
 * Setzt die Farbe des Boards auf blau oder gelb.
 *
 * @param angabeObBlau Angabe ob das Spielfeld blau sein soll.
 */
void GLWidget::setzeBoard(bool angabeObBlau)
{
    blue = angabeObBlau;
    ladeTexturen();
}

/**
 * Bindet die geladene 2D-Textur an einen weissen Quader, welcher das Spielfeld darstellt.
 *
 * @return GLunit Liste welche das fertige Spielbrett enthaelt.
 */
GLuint GLWidget::makeSpielbrett()
{
    GLuint liste = glGenLists(1);
    glNewList(liste, GL_COMPILE);
    glEnable(GL_TEXTURE_2D);
    qglColor(Qt::white);
    glBindTexture(GL_TEXTURE_2D, texturen[0]);
    glBegin(GL_QUADS);
    glTexCoord2d(0,1);
    glVertex3f(0.0f,0.0f, 0.0f);
    glTexCoord2d(0,0);
    glVertex3f(0.0f, 100.0f, 0.0f);
    glTexCoord2d(1,0);
    glVertex3f(100.0f, 100.0f, 0.0f);
    glTexCoord2d(1,1);
    glVertex3f(100.0f,0.0f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEndList();

    return liste;
}

/**
 * Zeichnet das aktuelle Bild in das GL-Widget.
 */
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-50.0);
    glCallList(spielfeldLayout);
    zeichneSpielsteinLayout();
}

/**
 * Zeichent die Spielsteine auf das Spielbrett und fuehrt die Drehungen dieser durch, wenn sich deren Farbe aendert.
 */
void GLWidget::zeichneSpielsteinLayout()
{
    GLUquadricObj *quadrat = gluNewQuadric();
    gluQuadricDrawStyle(quadrat, GLU_FILL);
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            FeldEigenschaft eigenschaft = spielfeld->liefereFeldeigenschaft(x, y);
            if(eigenschaft == belegt)
            {
                glPushMatrix();
                glTranslatef(breiteSeite + x * breiteQuadrat + radiusSpielstein, breiteSeite + y * breiteQuadrat + radiusSpielstein, 5.0f); //wo
                if(spielfeld->liefereFarbe(x, y) == white)
                {
                    glRotatef(180, 0.0f, 1.0f, 0.0f);
                }
                if(spielfeld->liefereDrehung(x, y))
                {
                    glRotatef(winkel, 0.0f, 1.0f, 0.0f);
                }
                zeichneSpielstein(quadrat);
            }
        }
    }
    gluDeleteQuadric(quadrat);
}

/**
 * Veraendert ein Quadrat zu einem ovalfoermigen Spielstein mit einer schwarzen und weissen seite und Zeichnet diesen in das GL-Widget.
 *
 * @param quadrat Angbae eines GLQuadrats, welches zu einem Spielstein transformiert werden soll.
 */
void GLWidget::zeichneSpielstein(GLUquadricObj *quadrat)
{
    glPushMatrix();
    qglColor(Qt::black);
    gluCylinder(quadrat, 4.5, 4.5, 1, 20, 20);
    glTranslatef(0.0, 0.0, 1.0f);
    gluDisk(quadrat, 0, 4.5, 20, 20);
    glPopMatrix();
    qglColor(Qt::white);
    glTranslatef(0.0, 0.0, -1.0);
    gluCylinder(quadrat, 4.5, 4.5, 1, 20, 20);
    gluDisk(quadrat, 0, 4.5, 20, 20);
    glPopMatrix();
}

/**
 * Standart-Methode eines GLWidgets zum Anpassen der groesse dessen in einem Fenster.
 *
 * @param breite Die Angabe der Breite des Fensters.
 * @param hoehe Die Angabe der Hoehe des Fensters.
 */
void GLWidget::resizeGL(int breite, int hoehe)
{
    int seite = qMin(breite, hoehe);
    glViewport((breite - seite) / 2, (hoehe - seite) / 2, seite, seite);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 100, 0, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * Event zum erfassen der Koordinaten eines Clicks. Wenn sich der Mausclick auf dem Spielfeld ereignet,
 * wird das spielFeldClicked Signal ausgefuehrt.
 *
 * @param event Ein QMouseEvent.
 */
void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if(frageSpielzug)
    {
        int xQuadrat;
        int yQuadrat;
        int xClick = event->x();
        int yClick = event->y();
        int breiteWidget = width();
        int hoeheWidget = height();
        int breiteSpielfeld = breiteWidget;
        if(hoeheWidget < breiteWidget)
        {
            breiteSpielfeld = hoeheWidget;
        }
        int breiteGrenze = breiteSpielfeld / (2.0 + (8.0 * breiteQuadrat / breiteSeite));
        int breiteDesQuadrats = (breiteSpielfeld - (2 * breiteGrenze)) / 8.0;
        if(breiteWidget > hoeheWidget)
        {
            xQuadrat = (xClick - ((breiteWidget-hoeheWidget) / 2.0) - breiteGrenze) / (breiteDesQuadrats);
            yQuadrat = (yClick - breiteGrenze) / (breiteDesQuadrats);
        }
        else if(breiteWidget < hoeheWidget)
        {
            xQuadrat = (xClick - breiteGrenze) / (breiteDesQuadrats);
            yQuadrat = (yClick - ((hoeheWidget-breiteWidget)/2.0) - breiteGrenze) / (breiteDesQuadrats);
        }
        else
        {
            xQuadrat = (xClick - breiteGrenze) / breiteDesQuadrats;
            yQuadrat = (yClick - breiteGrenze) / breiteDesQuadrats;
        }
        if(xQuadrat >= 0 && yQuadrat >= 0 && xQuadrat < 8 && yQuadrat < 8)
        {
            emit spielfeldClicked(xQuadrat, yQuadrat);
        }
    }
}

/**
 * Fuehrt alle Aenderungen an den Spielsteinen aus, und dreht diese um 180 Grad, wenn sich deren Farbe aendert.
 */
void GLWidget::updateGame()
{
    if(animationSetting == false)
    {
        spielfeld->entferneAlleDrehungen();
    }
    if(spielfeld->liefereAnimation() == true && liefereAnimation() == false)
    {
        timer->start(18);
        setzeAnimation(true);
    }
    if(animation == true)
    {
        winkel -= animationSpeed;
        if(winkel <= 0 )
        {
            winkel = 180;
            setzeAnimation(false);
            spielfeld->entferneAlleDrehungen();
            timer->stop();
            emit animationDone();
        }
    }
    repaint();
    if(animationSetting == false)
    {
        emit animationDone();
    }

}

/**
 * Liefert die Mindestgroesse des GL-Widgets, welche 600 * 600 betraegt.
 *
 * @return Die Mindestgroesse des GL-Widgets.
 */
QSize GLWidget::mindestGroesse()
{
    return QSize(600, 600);
}

/**
 * Liefert die Mindestgroesse des Spielfeldes, welches 500 * 500 betraegt.
 *
 * @return Die Mindestgroesse des Spielfeldes.
 */
QSize GLWidget::spielfeldGroesse()
{
    return QSize(500, 500);
}

/**
 * Liefert das frageSpielzug Attribut.
 *
 * @return Das frageSpielzug Attribut.
 */
bool GLWidget::liefereFrageSpielzug()
{
    return frageSpielzug;
}

/**
 * Setzt das frageSpielzug Attribut.
 *
 * @param angabeMoeglich Angabe als boolscher Wert.
 */
void GLWidget::setzeFrageSpielzug(bool angabeMoeglich)
{
    frageSpielzug = angabeMoeglich;
}

/**
 * Liefert den boolschen Wert der Animation.
 *
 * @return Den boolschen Wert der Animation.
 */
bool GLWidget::liefereAnimation()
{
    return animation;
}

/**
 * Liefert den boolschen Wert der AnimationSettings.
 *
 * @return Den boolschen Wert der AnimationSettings.
 */
bool GLWidget::liefereAnimationSettings()
{
    return animationSetting;
}

/**
 * Setzt das animations Attribut.
 *
 * @param angabeBool Angabe als boolscher Wert.
 */
void GLWidget::setzeAnimation(bool angabeBool)
{
    animation = angabeBool;
}

/**
 * Setzt das animationSettings Attribut.
 *
 * @param angabeBool Angabe als boolscher Wert.
 */
void GLWidget::setzeAnimationSettings(bool angabeBool)
{
    animationSetting = angabeBool;
}

/**
 * Verbindet das GL-Widget mit einem Reversi-Objekt.
 * Ueber Signals und Slots werden ereignisse ausgetauscht, wie z.B.
 * das setzen eines Spielsteins oder wechsel des aktuellen Spielers etc..
 *
 * (Verbindet GL-Widget mit der Reversi-Logik)
 *
 * @param spiel Die Angabe des Reversi-Spiel Objekts.
 */
void GLWidget::verbindeSpiel(Reversi *spiel)
{
    connect(this, SIGNAL(spielfeldClicked(int, int)), spiel, SLOT(setzeSpielstein(int,int)));
    connect(spiel, SIGNAL(localMove()), this, SLOT(setzeFrageSpielzeugTrue()));
    connect(this, SIGNAL(animationDone()), spiel, SLOT(nextTurn()));
    connect(spiel, SIGNAL(spielVeraenderung()), this, SLOT(updateGame()));
    connect(spiel, SIGNAL(spielEnde(QString)), this, SLOT(spielEnde(QString)));
    setzeSpielfeld(spiel->liefereSpielbrett());
}

/**
 * Setzt das spielFeld Objekt.
 *
 * @param angabeSpielfeld Angabe eines Spielfeld-Objekts.
 */
void GLWidget::setzeSpielfeld(Spielbrett *angabeSpielfeld)
{
    spielfeld = angabeSpielfeld;
}

/**
 * Setzt das frageSpielzug Attribut auf True.
 */
void GLWidget::setzeFrageSpielzeugTrue()
{
    frageSpielzug = true;
}

/**
 * Zeigt das Gewinner-Widget an.
 *
 * @param gewinnerName Der Name des Gewinners.
 */
void GLWidget::spielEnde(QString gewinnerName)
{
    gewinner *x = new gewinner(0, gewinnerName);
    x->show();
}

/**
 * Legt fest welcher Spieler welchen Namen hat und welcher Spieler welche farbe besitzt.
 *
 * @param spieler1Name Die Angabe des Namens von Spieler 1.
 * @param spieler2Name Die Angabe des Namens von Spieler 2.
 * @param spieler1Black Die Angabe welcher Spieler der schwarze ist. (und damit beginnt)
 */
void GLWidget::legeSpielerfest(QString spieler1Name, QString spieler2Name, bool spieler1Black, bool spieler2KI)
{
    QString spieler1;
    QString spieler2;
    bool Xspieler1KI = false;
    bool Xspieler2KI = false;
    if(spieler1Black == true && spieler2KI == true)
    {
        spieler1 = spieler1Name;
        spieler2 = spieler2Name;
        Xspieler2KI = true;
    }
    else if(spieler1Black == true && spieler2KI == false)
    {
        spieler1 = spieler1Name;
        spieler2 = spieler2Name;
    }
    else if(spieler1Black == false && spieler2KI == true)
    {
        spieler1 = spieler2Name;
        spieler2 = spieler1Name;
        Xspieler1KI = true;
    }
    else if(spieler1Black == false && spieler2KI == false)
    {
        spieler1 = spieler2Name;
        spieler2 = spieler1Name;
    }
    spiel->aendereSpielerNamen(spieler1, spieler2, Xspieler1KI, Xspieler2KI);
}
























