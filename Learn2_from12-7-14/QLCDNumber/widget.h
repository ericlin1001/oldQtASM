#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>

class Widget : public QWidget
{
    Q_OBJECT
private slots:
    void showDigit(int num);
    void btn0Click();
    void btn1Click();
    void btn2Click();
    void btn3Click();

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *quitBtn;
    QSlider *slider;
    QLCDNumber *lcd;
    QLabel *label;
    QTextEdit *editor;
};

#endif // WIDGET_H
