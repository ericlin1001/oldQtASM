#include <QtGui/QApplication>
#include "test.h"
#include<QDebug>
#include<QFile>
int main(int argc, char *argv[])
{
    QString str1;
    QStringList list;
    str1="adfadsfasdf";
    list<<str1<<","<<"test";
    QFile file;

            qWarning("cant");
            qDebug()<<"sdfsdfsd";
    //***********************************
    QApplication a(argc, argv);
    Test w;
    w.show();

    return a.exec();
}
