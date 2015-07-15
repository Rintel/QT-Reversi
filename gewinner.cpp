#include "gewinner.h"
#include "ui_gewinner.h"
#include <QSound>

/**
 * Konstruiert das Gewinner-Widget, mit der Hilfe der Angabe des "Gewinner-Namens".
 *
 * @param parent Die Angabe des Eltern-Widgets.
 * @param gewinner Die Angabe des Namens des Gewinners.
 */
gewinner::gewinner(QWidget *parent, QString gewinner) :
    QWidget(parent),
    ui(new Ui::gewinner)
{
    ui->setupUi(this);
    ui->siegerName->setText(gewinner);
    QSound *sound = new QSound("winner.wav");
    sound->play();
}

/**
 * Destruktor des Gewinner-Widgets.
 */
gewinner::~gewinner()
{
    delete ui;
}

/**
 * Beendet die Applikation, wenn der pushButton geclickt wird.
 */
void gewinner::on_pushButton_2_clicked()
{
    qApp->quit();
}
