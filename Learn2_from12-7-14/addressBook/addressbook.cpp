#include "addressbook.h"
#include "ui_addressbook.h"

AddressBook::AddressBook(QWidget *parent) :
    QWidget(parent)
{

}

AddressBook::~AddressBook()
{
    delete ui;
}
