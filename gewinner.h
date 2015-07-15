#ifndef GEWINNER_H
#define GEWINNER_H

#include <QWidget>

namespace Ui {
class gewinner;
}

/**
 * Die Widget-Klasse gewinner, hat die Aufgabe zum Anzeigen eines Gewinners.
 */
class gewinner : public QWidget
{
    Q_OBJECT

public:
    explicit gewinner(QWidget *parent = 0, QString gewinner = "?");
    ~gewinner();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::gewinner *ui;
};

#endif // GEWINNER_H
