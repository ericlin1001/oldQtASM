#include "test.h"
#include <QTextEdit>
#include<QGridLayout>
#include<QTextCursor>
#include<QTextDocument>
#include<QtGui>
Test::Test(QWidget *parent)
    : QWidget(parent)
{
    QTextEdit *editor=new QTextEdit();
    QTextEdit *newEditor=new QTextEdit();
    printBtn=new QPushButton(tr("&Print"));
    editor->setHtml("<h1>QStringContainningHTMLtext</h1><p>what  ...</p><div><b>xx</b>x </div>");
    editor->show();
    doc=editor->document();
    newEditor->setDocument(doc);
    QTextCursor cursor=editor->textCursor();
    cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.movePosition(QTextCursor::EndOfBlock,QTextCursor::KeepAnchor);
    editor->setTextCursor(cursor);
    //
    QTextCursor newCursor(doc);
    QTextCharFormat colorFormat;
    QBrush brush;
    brush.setColor(Qt::red);
    colorFormat.setBackground(brush);
    colorFormat.setFontItalic(true);
    QString searchStr="what";
    while(!newCursor.isNull() && !newCursor.atEnd()){
        newCursor=doc->find(searchStr,newCursor);
        if(!newCursor.isNull()){
            newCursor.movePosition(QTextCursor::WordRight,QTextCursor::KeepAnchor);
            newCursor.mergeCharFormat(colorFormat);

        }
    }
    QWidget * w=init();
    //editor->setTextCursor(newCursor);
    //
    connect(printBtn,SIGNAL(clicked()),this,SLOT(printDoc()));
    QGridLayout *mainLayout=new QGridLayout();
    mainLayout->addWidget(editor,0,0);
    mainLayout->addWidget(newEditor,1,0);
    mainLayout->addWidget(printBtn,2,0);
    mainLayout->addWidget(w,0,1,2,1);
    setLayout(mainLayout);
}

Test::~Test()
{

}
#include<QPrinter>
#include<QPrintDialog>
#include<QtUiTools/QtUiTools>
QWidget * Test::init(){
    QUiLoader loader;
    QFile file("form.ui");
    if(!file.open(QFile::ReadOnly))qDebug()<<"open fail.";
    QWidget *w=loader.load(&file,this);
    QLayout* layout=w->findChild<QLayout*>(tr("buttonLayout"));
    QButtonGroup *buttonGroup=new QButtonGroup();
    for(int i=0;i<3;i++)
        buttonGroup->addButton(const_cast<QAbstractButton*>(static_cast<const QAbstractButton*>(layout->children().at(i))),i);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(click(int)));
    return w;
}
void Test::click(int k){
    qDebug()<<tr("You click button %1").arg(k);
}

void Test::printDoc(){
    QPrinter printer;
    QPrintDialog *dlg=new QPrintDialog(&printer,this);
    if(dlg->exec()!=QDialog::Accepted){
        return ;
    }
    doc->print(&printer);
}
