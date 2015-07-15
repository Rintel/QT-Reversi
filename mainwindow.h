#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qstackedwidget.h>

namespace Ui {
class MainWindow;
}

/**Die Main-Windows Klasse stellt das Hauptfenster bereit, indem die Applikation dargestellt wird.*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStackedWidget* liefereNavigation();
};

#endif // MAINWINDOW_H
