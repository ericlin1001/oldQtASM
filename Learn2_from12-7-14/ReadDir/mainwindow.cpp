#include "mainwindow.h"

#include<QDir>
#include<QComboBox>
#include<QGridLayout>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    dirs=new QTextEdit();
    QComboBox *dirComboBox=new QComboBox;
    dirComboBox->addItem(QDir::currentPath());
    QDir dir(dirComboBox->currentText());
    for(int i=0;i<dir.count();i++){
        dirs->append(dir[i]);
    }

    QGridLayout *mainLayout=new QGridLayout();
    mainLayout->addWidget(dirComboBox,0,0);
    mainLayout->addWidget(dirs,1,0);
    setLayout(mainLayout);
    setWindowTitle("ReadDir");
}

MainWindow::~MainWindow()
{

}
