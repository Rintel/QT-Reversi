#include "spielladen.h"
#include "ui_spielladen.h"

/**
 * Konstruktor fuer die Spielladen-UI.
 *
 * @param parent Das Elternwidget.
 * @param theSites Alle zu erreichenden Widgets.
 */
SpielLaden::SpielLaden(QWidget *parent, QStackedWidget *theSites) :
    QWidget(parent),
    ui(new Ui::SpielLaden)
{
    ui->setupUi(this);

    sites = theSites;
}

/**
 * Destruktor.
 */
SpielLaden::~SpielLaden()
{
    delete ui;
}

/**
 * Navigation zum Hauptmenue wenn den Button geclickt wird.
 */
void SpielLaden::on_backButton_clicked()
{
    sites->setCurrentIndex(2);
}
