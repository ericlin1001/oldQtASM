#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include <QLibrary>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    loginP(this)
{
    ui->setupUi(this);
    serverIP="172.18.157.121";
    serverPort=6789;
    c.setReceiveFun(receiveFun);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
QString serverIP,username,pass;
unsigned int ;
*/
void MainWindow::receiveMess(const char *a,const char *b){
    qDebug(a);
    qDebug(b);
    QString str=a;
    str+=b;
    ui->receiveTextBox->setText(str);
}

void MainWindow::login(QString user,QString pass){
    username=user;
    this->pass=pass;

    c.init(serverIP.toStdString().c_str(),serverPort);
    c.start();
    c.login(username.toStdString().c_str(),this->pass.toStdString().c_str());

    //receiveMess("adfasdf","adsfadfasdf");
}

void MainWindow::on_sendButton_clicked(){
    unsigned int id=-1;

    QString sendTo=ui->sendToLineEdit->text();
    c.getUserDetail(sendTo.toStdString().c_str(),id);

    QString str=ui->sendTextBox->toPlainText();
    const char *p=str.toStdString().c_str();
    char *pp=const_cast<char*>(p);
    c.sendStr(pp,id);
}

void MainWindow::on_actionLogin_triggered()
{

    loginP.show();
}


void MainWindow::on_updateUserListButton_clicked()
{
    vector<const char *>users=c.getUserList();
    QString usersStr="";
    for(int i=0;i<users.size();i++){
        usersStr+=users[i];
        usersStr+='\n';
    }
ui->userListTextBox->setText(usersStr);
}
MainWindow*MainWindow::w;
