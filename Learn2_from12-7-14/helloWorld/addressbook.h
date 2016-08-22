#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushButton>
#include<QDialog>
class FindDialog:public QDialog{

    Q_OBJECT
public:
    FindDialog(QWidget *parent=0);
    QString getFindText();
public slots:
    void findClicked();

private:
    QPushButton *findBtn;
    QLineEdit *findEdit;
    QString findText;
};

class AdressBook:public QWidget{
    Q_OBJECT
public:
    AdressBook(QWidget *parent=0);
    //
    enum Mode{NavigationMode,AddingMode,EditingMode};
public slots:
    void addContact();
    void submitContact();
    void cancel();
    void next();
    void previous();
    //
    void editContact();
    void removeContact();
private slots:
    void findContact();
    void saveToFile();
    void loadFromFile();
private:
    void log(const QString &a,const QString& b);

    QLineEdit *nameLine;
    QTextEdit *addressText;
    //
    QPushButton *addBtn,*submitBtn,*cancelBtn;
    //
    QMap<QString,QString>contacts;
    QString oldname;
    QString oldAddress;
//
    QPushButton *nextBtn,*previousBtn;
    //
    QPushButton* editBtn,*removeBtn;
    //
    Mode currentMode;
    void updateMode(Mode mode);
    //
    QPushButton* findBtn;
    FindDialog *findDialog;
    //
    QPushButton *loadBtn,*saveBtn;
};

/*
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
*/
#endif // MAINWINDOW_H
