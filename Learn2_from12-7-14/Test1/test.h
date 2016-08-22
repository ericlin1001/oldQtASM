#ifndef TEST_H
#define TEST_H

#include <QtGui/QWidget>
#include<QPushButton>
#include<QTextDocument>
class Test : public QWidget
{
    Q_OBJECT

public slots:
    void printDoc();
    void click(int);
public:
    Test(QWidget *parent = 0);
    ~Test();
    QWidget * init();
private:
    QPushButton *printBtn;
    QTextDocument *doc;
};

#endif // TEST_H
