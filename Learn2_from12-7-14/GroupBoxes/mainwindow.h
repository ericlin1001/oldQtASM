#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QGroupBox* createFirstExclusiveGroup();
    QGroupBox* createSecondExclusiveGroup();
    QGroupBox* createNonExclusiveGroup();
    QGroupBox* createButtonGroup();
private slots:
    void testSlot(){
        qDebug()<<"test";
    }

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
