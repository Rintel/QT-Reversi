#include "mainwindow.h"
#include <QApplication>
//#include <GL/glew.h>
//#include <GL/glut.h>


/**
 * Main-Klasse des Reversi-Spiels. Ruft das Main-Windows auf, in welchem der restliche Programmablauf stattfindet.
 *
 * @param argc Die Anzahl der uebergebenen Programmparameter.
 * @param argv Die uebergebenen Programmparameter.
 * @return 0 | 1
 */
int main(int argc, char *argv[])
{
    //glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
