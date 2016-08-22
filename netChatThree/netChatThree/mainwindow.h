#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginpanel.h"
namespace Ui {
    class MainWindow;
}
#include "CBasicClient.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void login(QString user,QString pass);
    static void receiveFun(const char *a,const char *b){
        w->receiveMess(a,b);

    }
     void receiveMess(const char *a,const char *b);


    static MainWindow*w;
private slots:
    void on_sendButton_clicked();
    void on_actionLogin_triggered();

    void on_updateUserListButton_clicked();

private:
    CClientTest c;
    QString serverIP,username,pass;
    unsigned int serverPort;
    loginPanel loginP;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
