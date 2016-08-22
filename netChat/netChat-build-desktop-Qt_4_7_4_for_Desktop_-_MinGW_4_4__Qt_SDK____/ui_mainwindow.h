/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Mar 7 08:59:33 2013
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
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
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
    QPlainTextEdit *sendTextBox;
    QTextEdit *receiveTextBox;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QMenu *menuNetChat;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(289, 420);
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
        sendTextBox = new QPlainTextEdit(centralWidget);
        sendTextBox->setObjectName(QString::fromUtf8("sendTextBox"));
        sendTextBox->setGeometry(QRect(0, 230, 291, 101));
        receiveTextBox = new QTextEdit(centralWidget);
        receiveTextBox->setObjectName(QString::fromUtf8("receiveTextBox"));
        receiveTextBox->setGeometry(QRect(0, 0, 291, 221));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(200, 340, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 289, 17));
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
        menuNetChat->setTitle(QApplication::translate("MainWindow", "function", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
