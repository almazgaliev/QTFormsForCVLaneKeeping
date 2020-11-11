#include "mainwindow.h"
//#include "AVL.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //avl::Image i;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
