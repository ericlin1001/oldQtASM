#include <QtGui/QApplication>
#include "textfinder.h"

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(textfinder);
    QApplication a(argc, argv);
    TextFinder w;
    w.show();

    return a.exec();
}
