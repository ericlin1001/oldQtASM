#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtGui>
#include<QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSystemTrayIcon *tray=new QSystemTrayIcon(this);
    QMenu *menu=new QMenu();
    tray->setContextMenu(menu);
    tray->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
