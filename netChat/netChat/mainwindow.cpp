#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    QString sendStr=ui->sendTextBox->toPlainText();
    ui->sendTextBox->clear();
    ui->receiveTextBox->setText(sendStr);
}


void MainWindow::on_actionConnect_triggered()
{

}

void MainWindow::on_actionLogin_triggered()
{

}

void MainWindow::on_actionLogoff_triggered()
{

}

void MainWindow::on_actionAbout_triggered()
{

}
