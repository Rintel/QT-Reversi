#include "credits.h"
#include "ui_credits.h"

/**
 * Konstruiert das Credits-Widget.
 *
 * @param parent Die Angabe des Eltern-Widgets.
 * @param theSites Die Angabe der zu erreichenden Widgets.
 */
Credits::Credits(QWidget *parent, QStackedWidget *theSites) :
    QWidget(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);

    sites = theSites;
}

/**
 * Destruktor des Credits-Widgets.
 */
Credits::~Credits()
{
    delete ui;
}

/**
 * Navigiert zurueck zum Hauptmenue, wenn der backButton geclickt wird.
 */
void Credits::on_backButton_clicked()
{
    sites->setCurrentIndex(2);
}
