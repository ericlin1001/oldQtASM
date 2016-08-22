/********************************************************************************
** Form generated from reading UI file 'encryption.ui'
**
** Created: Thu Dec 22 21:48:47 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTION_H
#define UI_ENCRYPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Encryption
{
public:
    QAction *actionCc;
    QAction *actionOk;
    QAction *actionOk_2;
    QAction *actionNwe_test;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QMenu *menuNew;
    QMenu *menuA_new_one;
    QMenu *menuCopy;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Encryption)
    {
        if (Encryption->objectName().isEmpty())
            Encryption->setObjectName(QString::fromUtf8("Encryption"));
        Encryption->resize(671, 454);
        actionCc = new QAction(Encryption);
        actionCc->setObjectName(QString::fromUtf8("actionCc"));
        actionOk = new QAction(Encryption);
        actionOk->setObjectName(QString::fromUtf8("actionOk"));
        actionOk_2 = new QAction(Encryption);
        actionOk_2->setObjectName(QString::fromUtf8("actionOk_2"));
        actionNwe_test = new QAction(Encryption);
        actionNwe_test->setObjectName(QString::fromUtf8("actionNwe_test"));
        centralWidget = new QWidget(Encryption);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 50, 75, 23));
        pushButton->setAutoDefault(false);
        pushButton->setDefault(false);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 30, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(10, 160, 231, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setCursor(QCursor(Qt::ClosedHandCursor));
        lineEdit->setMouseTracking(true);
        lineEdit->setFocusPolicy(Qt::StrongFocus);
        lineEdit->setAutoFillBackground(true);
        lineEdit->setFrame(false);
        lineEdit->setEchoMode(QLineEdit::Normal);
        lineEdit->setCursorPosition(2);
        lineEdit->setDragEnabled(true);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 160, 281, 81));
        lineEdit_2->setEchoMode(QLineEdit::NoEcho);
        Encryption->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Encryption);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 23));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuA_new_one = new QMenu(menuNew);
        menuA_new_one->setObjectName(QString::fromUtf8("menuA_new_one"));
        menuCopy = new QMenu(menuBar);
        menuCopy->setObjectName(QString::fromUtf8("menuCopy"));
        Encryption->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Encryption);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Encryption->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Encryption);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Encryption->setStatusBar(statusBar);

        menuBar->addAction(menuNew->menuAction());
        menuBar->addAction(menuCopy->menuAction());
        menuNew->addAction(menuA_new_one->menuAction());
        menuNew->addSeparator();
        menuNew->addAction(actionCc);
        menuNew->addSeparator();
        menuNew->addAction(actionOk);
        menuNew->addAction(actionOk_2);
        menuA_new_one->addAction(actionNwe_test);

        retranslateUi(Encryption);

        QMetaObject::connectSlotsByName(Encryption);
    } // setupUi

    void retranslateUi(QMainWindow *Encryption)
    {
        Encryption->setWindowTitle(QApplication::translate("Encryption", "Encryption", 0, QApplication::UnicodeUTF8));
        actionCc->setText(QApplication::translate("Encryption", "cc", 0, QApplication::UnicodeUTF8));
        actionCc->setShortcut(QApplication::translate("Encryption", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionOk->setText(QApplication::translate("Encryption", "ok", 0, QApplication::UnicodeUTF8));
        actionOk_2->setText(QApplication::translate("Encryption", "ok", 0, QApplication::UnicodeUTF8));
        actionNwe_test->setText(QApplication::translate("Encryption", "nwe test", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Encryption", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Encryption", "PushButton", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Encryption", "tooltip", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("Encryption", "statutip", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("Encryption", "nothing but a test", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        lineEdit->setAccessibleName(QApplication::translate("Encryption", "abc", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        lineEdit->setText(QApplication::translate("Encryption", "261", 0, QApplication::UnicodeUTF8));
        menuNew->setTitle(QApplication::translate("Encryption", "new", 0, QApplication::UnicodeUTF8));
        menuA_new_one->setTitle(QApplication::translate("Encryption", "a new one", 0, QApplication::UnicodeUTF8));
        menuCopy->setTitle(QApplication::translate("Encryption", "copy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Encryption: public Ui_Encryption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTION_H
