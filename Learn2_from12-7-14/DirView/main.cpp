#include <QtGui/QApplication>
#include "mainwindow.h"
#include<QtGui>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*QDirModel *model=new QDirModel();
    QTreeView *tree=new QTreeView();
    tree->setModel(model);
    tree->setWindowTitle("Dir View");
    tree->resize(640,480);
    tree->show();*/
    return a.exec();
}
