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
#include <iostream>
using namespace std;
QString getPrimg(int n){
    QString str;
    QString stri;
    for(int i=2;i<n*n;i++){
        stri.setNum(i);
        str+=stri;
      cout<<i<<endl;
    }
    return str;
}

void MainWindow::on_TestButton_clicked()
{

}

void MainWindow::on_TestButton_pressed()
{
    ui->MyText->setText(getPrimg(10));
  // ui->MyText->setText("abc");
}

void MainWindow::on_changeLCD_clicked()
{
    static int k=0;
    k++;
    //ui->lcdNumber->intValue();
    ui->lcdNumber->startTimer(1);
}
#include <windows.h>
#include<stdlib.h>
#include<io.h>
#include <windowsx.h>
using namespace std;
void MainWindow::on_pushButton_clicked()
{
   /* QPainter p;
    QGraphicsItem g;
    QStyleOptionGraphicsItem i;
    QPaintDevice d;
    p.begin(&d);
    QGraphicsRectItem *rect=new QGraphicsRectItem();

    ui->graphicsView->drawItems(&p,1,rect,&i);
    HDC hdc=ui->graphicsView->getDC();
    HPEN pen=CreatePen(1,1,RGB(255,0,0));
    HPEN oldpen=(HPEN)SelectObject(hdc,pen);
    LineTo(hdc,100,100);
    LineTo(hdc,100,50);
    SelectObject(hdc,oldpen);*/
   // ui->graphicsView->
}
