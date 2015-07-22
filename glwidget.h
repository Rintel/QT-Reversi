#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "spielbrett.h"
#include <qtimer.h>
#include "spieler.h"
#include "spielzug.h"
#include <QMouseEvent>
#include "reversi.h"

using namespace std;

/**
 * Die Klasse GL-Widget hat die Funktion zum anzeigen des OpenGL-Kontents des Reversi-Spiels.
 */
class GLWidget : public QGLWidget
{
    Q_OBJECT
private:
    /**Das Spielbrett-Objekt mit der Spielbrettlogik.*/
    Spielbrett *spielfeld;
    /**Ein Reversi-Spiel mit der Spiellogik.*/
    Reversi *spiel;
    /**Drehungswinkel der Spielsteine.*/
    int winkel;
    /**Ein QTimer.*/
    QTimer *timer;
    /**Die Texturen des Spielfeldes.*/
    GLuint texturen[1];
    /**Layout des Spielfeldes.*/
    GLuint spielfeldLayout;
    /**Initialisierungsfarbe des GL-Widgets.*/
    QColor clearColor;
    /**Variable zum erfragen eines Spielzuges.*/
    bool frageSpielzug;
    /**Boolsche Variable fuer die AnnimationSettings.*/
    bool animationSetting;
    /**Boolsche Variable fuer die Annimation.*/
    bool animation;
    /**Blue Farbe des Spielbretts.*/
    bool blue;

public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int breite, int hoehe);
    void zeichneSpielstein(GLUquadricObj *quadrat);
    void zeichneSpielsteinLayout();
    void mousePressEvent(QMouseEvent *event);
    QSize mindestGroesse();
    QSize spielfeldGroesse();
    void setzeFrageSpielzug(bool angabeMoeglich);
    bool liefereFrageSpielzug();
    bool liefereAnimation();
    bool liefereAnimationSettings();
    void setzeAnimation(bool angabeBool);
    void setzeAnimationSettings(bool angabeBool);
    void verbindeSpiel(Reversi *spiel);
    void legeSpielerfest(QString spieler1Name, QString spieler2Name, bool spieler1Black, bool spieler2KI);
    void setzeBoard(bool angabeObBlau);

private:
    void ladeTexturen();
    GLuint makeSpielbrett();
    void setzeSpielfeld(Spielbrett *angabeSpielfeld);

signals:
    /**Signal, dass das Spielfeld geclickt wurde.*/
    void spielfeldClicked(int, int);
    /**Signal, dass alle Animationen beendet sind.*/
    void animationDone();

public slots:
    void updateGame();
    void setzeFrageSpielzeugTrue();
    void spielEnde(QString gewinnerName);



};

#endif // GLWIDGET_H
