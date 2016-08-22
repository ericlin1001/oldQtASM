#include "textfinder.h"
#include<QtUiTools/QtUiTools>

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent)
{
    qDebug()<<"start";
    QWidget *formWidget=loadUiFile();
    qDebug()<<"loadSuccess";
    ui_findButton=qFindChild<QPushButton*>(this,"findButton");
    ui_textEdit=qFindChild<QTextEdit*>(this,"textEdit");
    ui_lineEdit=qFindChild<QLineEdit*>(this,"lineEdit");
    QMetaObject::connectSlotsByName(this);
    //
    loadTextFile();
    qDebug()<<"load input file Success";
    QVBoxLayout*layout=new QVBoxLayout();
    layout->addWidget(formWidget);
    setLayout(layout);
    setWindowTitle(tr("Text Finder"));
    resize(480,480);
    needRestore=false;
    qDebug()<<"end";
}
QWidget *TextFinder::loadUiFile(){
    QUiLoader loader;
    QFile file(tr(":/textfinder.ui"));
    if(!file.open(QFile::ReadOnly))QMessageBox::information(this,tr("Open Fial"),tr("Can't open %1").arg("textfinder.ui"));
    QWidget *form=loader.load(&file,this);
    file.close();
    return form;
}

void TextFinder::loadTextFile(){
    QFile file(tr(":/input.txt"));
    if(!file.open(QFile::ReadOnly))QMessageBox::information(this,tr("Open Fial"),tr("Can't open %1").arg("input.txt"));
    QTextStream in(&file);
    QString text=in.readAll();
    file.close();
    ui_textEdit->append(text);
    ui_textEdit->setUndoRedoEnabled(true);
}
void TextFinder::on_findButton_clicked()
{
    QString searchStr=ui_lineEdit->text();
    QTextDocument *doc=ui_textEdit->document();
    qDebug()<<searchStr;
    bool found=false;
    if(needRestore){
        doc->undo();
    }
    if(searchStr==""){
        QMessageBox::information(this,tr("Empty Search Field"),tr("The search field is empty.Please enter a word and click Find."));
    }else{
        QTextCursor hlCursor(doc);
        QTextCursor cursor(doc);
        cursor.beginEditBlock();
        QTextCharFormat plainFormat=hlCursor.charFormat();
        QTextCharFormat colorFormat=plainFormat;
        colorFormat.setForeground(Qt::red);
        while(!hlCursor.isNull() && !hlCursor.atEnd()){
            hlCursor=doc->find(searchStr,hlCursor,QTextDocument::FindWholeWords);
            if(!hlCursor.isNull()&& !hlCursor.atEnd()){
                found=true;
                hlCursor.movePosition(QTextCursor::WordRight,QTextCursor::KeepAnchor);
                hlCursor.setCharFormat(colorFormat);
                qDebug()<<"found";
            }
        }
        cursor.endEditBlock();

        if(!found){
            QMessageBox::information(this,tr("Word Not Found"),"Sorry,the word can't be found.");
            needRestore=false;
        }else{
            needRestore=true;
        }
    }
}
