#include "loginpanel.h"
#include "ui_loginpanel.h"
#include "mainwindow.h"
loginPanel::loginPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPanel)
{
    ui->setupUi(this);

}

loginPanel::~loginPanel()
{
    delete ui;
}


void loginPanel::on_pushButton_2_clicked()
{
    this->hide();
}

void loginPanel::on_pushButton_clicked()
{
    MainWindow *w=(MainWindow*)(this->parent());
    w->login(ui->username->text(),ui->password->text());
    this->hide();
}
