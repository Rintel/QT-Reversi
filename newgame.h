#ifndef NEWGAME_H
#define NEWGAME_H

#include <QWidget>
#include <qstackedwidget.h>

namespace Ui {
class newGame;
}

/**Die NewGame-Klasse ist ein Widget, welches das UserInterface zum erstellen eines neuen Reversispiels bereitstellt.*/
class newGame : public QWidget
{
    Q_OBJECT
private:
    /**Die zu erreichenden Widgets.*/
    QStackedWidget* sites;

public:
    explicit newGame(QWidget *parent = 0, QStackedWidget *theSites = 0);
    ~newGame();

private slots:
    void on_backButton_clicked();

    void on_startButton_clicked();

private:
    Ui::newGame *ui;

    QStackedWidget* liefereStackedWidget();
};

#endif // NEWGAME_H
