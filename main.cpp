#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    w.showMaximized();
    // QLabel widget("Hello");
    // widget.show();
    return a.exec();
}
