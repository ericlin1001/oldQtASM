#include "widget.h"
#include<QtGui>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    quitBtn=new QPushButton(tr("&Quit"));
    slider=new QSlider(Qt::Horizontal);
    lcd=new QLCDNumber();
    label=new QLabel();
    lcd->setNumDigits(3);
    lcd->display(3);
    slider->setRange(0,10000);
    slider->setValue(5);
    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(showDigit(int)));
    connect(quitBtn,SIGNAL(clicked()),qApp,SLOT(quit()));
    //
    QLayout *layout[10];int pL;
    QGroupBox *boxes[10];
#define Layout layout[pL]
    pL=1;
    Layout;
    Layout=new QVBoxLayout();
    Layout->addWidget(lcd);
    Layout->addWidget(slider);
    Layout->addWidget(label);
    Layout->addWidget(quitBtn);
    //
    pL=2;
    Layout=new QVBoxLayout();
    QPushButton *buttons[10];
    buttons[0]=new QPushButton(tr("test %0").arg(0));
    Layout->addWidget(buttons[0]);
    connect(buttons[0],SIGNAL(clicked()),this,SLOT(btn0Click()));
    buttons[1]=new QPushButton(tr("&test %0").arg(1));
    Layout->addWidget(buttons[1]);
    connect(buttons[1],SIGNAL(clicked()),this,SLOT(btn1Click()));
    //
    pL=3;
    Layout=new QVBoxLayout();
    editor=new QTextEdit();
    Layout->addWidget(editor);
    QTextTable *offersTable=editor->textCursor().insertTable(2,3);
    QTextCursor cursor=offersTable->cellAt(0,0).firstCursorPosition();
    QTextCharFormat plainFormat(cursor.charFormat());
    QTextCharFormat italicFormat=plainFormat;italicFormat.setFontItalic(true);
    QTextCharFormat boldFormat=plainFormat;boldFormat.setFontWeight(QFont::Bold);
    cursor.insertText(tr("I want to receive more information about you "),plainFormat);
    cursor=offersTable->cellAt(0,1).firstCursorPosition();
    cursor.insertText(tr("adfasdfasdf"),italicFormat);
    cursor=offersTable->cellAt(1,1).firstCursorPosition();
    cursor.insertHtml(tr("<a href=\"www.baidu.com\">gotoBaidu</a><br><b>bold</b><br><i>italic</i><br>"));
    //
    layout[0]=new QHBoxLayout();
    pL=1;
    boxes[pL]=new QGroupBox;
    boxes[pL]->setLayout(layout[pL]);
    layout[0]->addWidget(boxes[pL]);
    pL=2;
    boxes[pL]=new QGroupBox;
    boxes[pL]->setLayout(layout[pL]);
    layout[0]->addWidget(boxes[pL]);
    pL=3;
    boxes[pL]=new QGroupBox;
    boxes[pL]->setLayout(layout[pL]);
    layout[0]->addWidget(boxes[pL]);
   // Layout->addWidget(layout[3]);
    setLayout(layout[0]);
}
void Widget::btn0Click(){
    editor->textCursor().insertText(QApplication::clipboard()->text());
}
void Widget::btn1Click(){
    QTextCursor cursor=editor->textCursor();
    QStringList list;

    qDebug()<<cursor.atBlockStart()<<cursor.atBlockEnd()<<cursor.atStart()<<cursor.atEnd();
    qDebug()<<cursor.selection().toPlainText();
   // <<list;
}
void Widget::btn2Click(){

}
void Widget::btn3Click(){

}
void Widget::showDigit(int num){
    lcd->display(num);
    /*char buffer[10];
    itoa(num,buffer,10);*/
    label->setText(tr("%0").arg(num));

}

Widget::~Widget()
{

}
