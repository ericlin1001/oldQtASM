#include <QtGui/QApplication>
#include "encryption.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Encryption w;
    w.show();

    return a.exec();
}
