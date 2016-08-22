/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Mar 9 13:13:40 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionLogin;
    QAction *actionLogoff;
    QAction *actionAbout;
    QWidget *centralWidget;
    QTextEdit *sendTextBox;
    QTextEdit *receiveTextBox;
    QPushButton *sendButton;
    QLineEdit *sendToLineEdit;
    QLabel *label;
    QTextEdit *userListTextBox;
    QLabel *label_2;
    QPushButton *updateUserListButton;
    QMenuBar *menuBar;
    QMenu *menuNetChat;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(440, 422);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        actionLogoff = new QAction(MainWindow);
        actionLogoff->setObjectName(QString::fromUtf8("actionLogoff"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sendTextBox = new QTextEdit(centralWidget);
        sendTextBox->setObjectName(QString::fromUtf8("sendTextBox"));
        sendTextBox->setGeometry(QRect(120, 230, 291, 111));
        receiveTextBox = new QTextEdit(centralWidget);
        receiveTextBox->setObjectName(QString::fromUtf8("receiveTextBox"));
        receiveTextBox->setGeometry(QRect(120, 30, 291, 191));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(340, 350, 75, 23));
        sendToLineEdit = new QLineEdit(centralWidget);
        sendToLineEdit->setObjectName(QString::fromUtf8("sendToLineEdit"));
        sendToLineEdit->setGeometry(QRect(120, 0, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 54, 12));
        userListTextBox = new QTextEdit(centralWidget);
        userListTextBox->setObjectName(QString::fromUtf8("userListTextBox"));
        userListTextBox->setGeometry(QRect(0, 70, 101, 251));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 54, 12));
        updateUserListButton = new QPushButton(centralWidget);
        updateUserListButton->setObjectName(QString::fromUtf8("updateUserListButton"));
        updateUserListButton->setGeometry(QRect(0, 320, 101, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 440, 17));
        menuNetChat = new QMenu(menuBar);
        menuNetChat->setObjectName(QString::fromUtf8("menuNetChat"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuNetChat->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuNetChat->addAction(actionConnect);
        menuNetChat->addAction(actionLogin);
        menuNetChat->addAction(actionLogoff);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("MainWindow", "connect", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "connect To server", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLogin->setText(QApplication::translate("MainWindow", "login", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLogin->setToolTip(QApplication::translate("MainWindow", "login with you username and password.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLogoff->setText(QApplication::translate("MainWindow", "logoff", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("MainWindow", "send", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "sendTo:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "userList:", 0, QApplication::UnicodeUTF8));
        updateUserListButton->setText(QApplication::translate("MainWindow", "updateUserList", 0, QApplication::UnicodeUTF8));
        menuNetChat->setTitle(QApplication::translate("MainWindow", "function", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
