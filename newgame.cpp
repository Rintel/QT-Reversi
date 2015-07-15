#include "newgame.h"
#include "ui_newgame.h"

#include "openglgame.h"

/**
 * Konstruktor fuer ein newGame-Widget.
 *
 * @param parent Die Angabe des Parentwidgets.
 * @param theSites Die Angabe der zu erreichenden Widgets.
 */
newGame::newGame(QWidget *parent, QStackedWidget *theSites) :
    QWidget(parent),
    ui(new Ui::newGame)
{
    ui->setupUi(this);
    sites = theSites;
}

/**
 * Destruktor der newGame Klasse.
 */
newGame::~newGame()
{
    delete ui;
}

/**
 * Wenn der Button geclickt wird, wird zurueck zum Hauptmenue navigiert.
 */
void newGame::on_backButton_clicked()
{
    sites->setCurrentIndex(2);
}

/**
 * Startet das Reversi-Spiel. Uebergibt die Namen der Spieler und welcher Spieler schwarz ist
 * und erstellt ein neues OpenGLGame-Widget, zu welchem es dann navigiert.
 */
void newGame::on_startButton_clicked()
{
    QString spieler1 = ui->nameSp1->toPlainText();
    QString spieler2 = ui->nameSp2->toPlainText();
    bool spieler1black = ui->backButton->isChecked();
    bool isBlue = ui->blau->isChecked();
    sites->addWidget(new OpenGLGame(this, liefereStackedWidget(), spieler1, spieler2, spieler1black, isBlue)); //Index 6 für das spiel in diesem moment?
    sites->setCurrentIndex(6);
}

/**
 * Liefert alle Widgets, zu welchen navigiert werden kann.
 *
 * @return Alle Widgets, zu welchen navigiert werden kann.
 */
QStackedWidget* newGame::liefereStackedWidget()
{
    return sites;
}
