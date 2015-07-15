#ifndef SPIELLADEN_H
#define SPIELLADEN_H

#include <QWidget>
#include <qstackedwidget.h>

namespace Ui {
class SpielLaden;
}

/**Das Widget SpielLaden stellt das UserInterface zum Laden eines Spiel bereit.*/
class SpielLaden : public QWidget
{
    Q_OBJECT
private:
    /**Die zu erreichenden Widgets.*/
    QStackedWidget* sites;

public:
    explicit SpielLaden(QWidget *parent = 0, QStackedWidget* theSites = 0);
    ~SpielLaden();

private slots:
    void on_backButton_clicked();

private:
    Ui::SpielLaden *ui;
};

#endif // SPIELLADEN_H
