/********************************************************************************
** Form generated from reading UI file 'loginpanel.ui'
**
** Created: Sat Mar 9 13:13:40 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPANEL_H
#define UI_LOGINPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginPanel
{
public:
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *loginPanel)
    {
        if (loginPanel->objectName().isEmpty())
            loginPanel->setObjectName(QString::fromUtf8("loginPanel"));
        loginPanel->resize(330, 204);
        username = new QLineEdit(loginPanel);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(90, 60, 113, 20));
        password = new QLineEdit(loginPanel);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(90, 100, 113, 20));
        pushButton = new QPushButton(loginPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 140, 75, 23));
        pushButton_2 = new QPushButton(loginPanel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 140, 75, 23));
        label = new QLabel(loginPanel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 60, 54, 12));
        label_2 = new QLabel(loginPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 100, 54, 12));

        retranslateUi(loginPanel);

        QMetaObject::connectSlotsByName(loginPanel);
    } // setupUi

    void retranslateUi(QDialog *loginPanel)
    {
        loginPanel->setWindowTitle(QApplication::translate("loginPanel", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("loginPanel", "Login", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("loginPanel", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("loginPanel", "UserName:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("loginPanel", "Password:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loginPanel: public Ui_loginPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPANEL_H
