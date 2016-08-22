/********************************************************************************
** Form generated from reading UI file 'addressbook.ui'
**
** Created: Sun Jul 15 19:07:25 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOOK_H
#define UI_ADDRESSBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddressBook
{
public:

    void setupUi(QWidget *AddressBook)
    {
        if (AddressBook->objectName().isEmpty())
            AddressBook->setObjectName(QString::fromUtf8("AddressBook"));
        AddressBook->resize(400, 300);

        retranslateUi(AddressBook);

        QMetaObject::connectSlotsByName(AddressBook);
    } // setupUi

    void retranslateUi(QWidget *AddressBook)
    {
        AddressBook->setWindowTitle(QApplication::translate("AddressBook", "AddressBook", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddressBook: public Ui_AddressBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOK_H
