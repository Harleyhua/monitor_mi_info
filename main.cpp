#include "mainwindow.h"
#include <QApplication>


#define VERSION "软件版本1.01"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.showMaximized();
    w.setWindowTitle("老化房产品信息录入系统" VERSION);

    w.show();
    return a.exec();
}
