#include <QApplication>
#include "addressbook.h"
#include<QLabel>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* QLabel label("hello world");
    label.show();
    QPushButton button("hello");
    button.resize(100,200);
    button.move(400,400);

    label.setParent(&button);
    button.dumpObjectTree();
    button.show();*/
    //
    AdressBook addressBook;
    addressBook.show();
    //button.mouse
    //MainWindow w;
   // w.show();

    return a.exec();
}
