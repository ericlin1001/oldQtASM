#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget.h>
#include<QTextEdit>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTextEdit *dirs;
};

#endif // MAINWINDOW_H
