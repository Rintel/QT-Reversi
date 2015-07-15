#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qstackedwidget.h>
#include "credits.h"
#include "hauptmenue.h"
#include "newgame.h"
#include "spielladen.h"

/**
 * Konstruktor fuer ein MainWindow-Objekt. In diesem Objekt werden alle weiteren Widgets geladen.
 *
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->stackedWidget->addWidget(new Hauptmenue(this, liefereNavigation())); //Index 2 fuer das Hauptmenue
    ui->stackedWidget->addWidget(new Credits(this, liefereNavigation())); //Index 3 fuer die Credits
    ui->stackedWidget->addWidget(new newGame(this, liefereNavigation())); //Index 4 fuer ein neues Spiel
    ui->stackedWidget->addWidget(new SpielLaden(this, liefereNavigation())); //Index 5 fuer Spiel laden

    ui->stackedWidget->setCurrentIndex(2);
}

/**
 * Destructor der MainWindow Klasse.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Liefert das StackedWidget aus dem Main-Site, in welchem alle anderen Widgets geladen werden.
 *
 * @return Das StackedWidget aus der Main-Site.
 */
QStackedWidget* MainWindow::liefereNavigation()
{
    return ui->stackedWidget;
}
