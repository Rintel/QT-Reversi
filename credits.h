#ifndef CREDITS_H
#define CREDITS_H

#include <QWidget>
#include <qstackedwidget.h>

namespace Ui {
class Credits;
}

/**
 * Das Credit-Widget hat die Funktion zum anzeigen der Programminformationen.
 */
class Credits : public QWidget
{
    Q_OBJECT
private:
    /**Widgets zu denen navigiert werden kann.*/
    QStackedWidget* sites;

public:
    explicit Credits(QWidget *parent = 0, QStackedWidget* theSites = 0);
    ~Credits();

private slots:
    void on_backButton_clicked();

private:
    Ui::Credits *ui;
};

#endif // CREDITS_H
