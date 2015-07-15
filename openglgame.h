#ifndef OPENGLGAME_H
#define OPENGLGAME_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class OpenGLGame;
}

/**Die OpenGLGame Widget Klasse, stellt das Fenster fuer ein Reversi-GLWidget bereit.*/
class OpenGLGame : public QWidget
{
    Q_OBJECT
private:
    /**Die zu erreichenden Widgets.*/
    QStackedWidget* sites;

public:
    explicit OpenGLGame(QWidget *parent = 0, QStackedWidget* theSites = 0, QString spielername1 = "Spieler 1", QString spielername2 = "Spieler 2", bool spieler1black = true, bool isBlue = true);
    ~OpenGLGame();

private:
    Ui::OpenGLGame *ui;
};

#endif // OPENGLGAME_H
