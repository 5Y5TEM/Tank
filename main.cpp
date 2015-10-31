#include "mainwindow.h"
#include <QApplication>
#define W 500
#define H 500

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
