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

#include "CBasicClient.h"

void MainWindow::on_sendButton_clicked()
{
    CClientTest c;
   /* char serverIP[20]="172.18.157.121";
    unsigned short port=6789;
            if( c.init(serverIP,port)!=MYSUCCESS){cerr<<"Can't find server."<<endl;return;}
                            cout<<"Connect successfully!"<<endl;
                            c.start();*/
                           // cout<<"user:";getStr(cin,user,MAX_LEN_USERNAME);
                           // cout<<"password:";getStr(cin,pass,MAX_LEN_PASS);
                           // c.login(user,pass);
}
