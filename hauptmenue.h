#ifndef HAUPTMENUE_H
#define HAUPTMENUE_H

#include <QWidget>
#include <qstackedwidget.h>


namespace Ui {
class Hauptmenue;
}

/**Die Hauptmenue-Widget Klasse bietet die Funktionen zum Navigieren durch das Programm.*/
class Hauptmenue : public QWidget
{
    Q_OBJECT
private:
    /**Die zu erreichenden Widgets.*/
    QStackedWidget* sites;

public:
    explicit Hauptmenue(QWidget *parent = 0, QStackedWidget* theSites = 0);
    ~Hauptmenue();

private slots:
    void on_endButton_clicked();

    void on_newGameButton_clicked();

    void on_creditsButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::Hauptmenue *ui;
};

#endif // HAUPTMENUE_H
