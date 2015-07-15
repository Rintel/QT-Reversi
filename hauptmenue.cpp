#include "hauptmenue.h"
#include "ui_hauptmenue.h"

#include <qstackedwidget.h>

/**
 * Konstruktor fuer das Hauptmenue-Widget.
 *
 * @param parent Das Elternwidget.
 * @param theSites Die Angabe der zu navigierbaren Widgets.
 */
Hauptmenue::Hauptmenue(QWidget *parent, QStackedWidget *theSites) :
    QWidget(parent),
    ui(new Ui::Hauptmenue)
{
    ui->setupUi(this);

    sites = theSites;
}

/**
 * Destructor fuer das Hauptmenue-Widget.
 */
Hauptmenue::~Hauptmenue()
{
    delete ui;
}

/**
 * Beendet die App wenn der endButton geclickt wird.
 */
void Hauptmenue::on_endButton_clicked()
{
    qApp->quit();
}

/**
 * Navigiert zum NewGame-Widget, wenn newGameButton geclickt wird.
 */
void Hauptmenue::on_newGameButton_clicked()
{
    sites->setCurrentIndex(4);
}

/**
 * Navigiert zu den Game-Credits, wenn creditsButton geclickt wird.
 */
void Hauptmenue::on_creditsButton_clicked()
{
    sites->setCurrentIndex(3);
}

/**
 * Navigiert zum SpielLaden-Widget, wenn loadButton geclickt wird.
 */
void Hauptmenue::on_loadButton_clicked()
{
    sites->setCurrentIndex(5);
}
