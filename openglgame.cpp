#include "openglgame.h"
#include "ui_openglgame.h"
#include "glwidget.h"
#include <iostream>

/**
 * Konstruktor fuer ein OpenGlGame-Widget.
 * Gibt die Spielernamen und welcher Spieler startet an das GLWidget weiter.
 *
 * @param parent Die Angabe vom ElternWidget.
 * @param theSites Alle Widgets, zu welchen navigiert werden kann.
 * @param spielername1 Die Angabe des Spielernamens.
 * @param spielername2 Die Angabe des Spielernamens.
 * @param spieler1black Die Angabe welcher Spieler die schwarzen Spielsteine besitzt.
 */
OpenGLGame::OpenGLGame(QWidget *parent, QStackedWidget *theSites, QString spielername1, QString spielername2, bool spieler1black, bool isBlue) :
    QWidget(parent),
    ui(new Ui::OpenGLGame)
{
    ui->setupUi(this);
    sites = theSites;
    ui->widget->legeSpielerfest(spielername1, spielername2, spieler1black);
    ui->widget->setzeBoard(isBlue);
}

/**
 * Destruktor des OpenGLGame-Objekts.
 */
OpenGLGame::~OpenGLGame()
{
    delete ui;
}
