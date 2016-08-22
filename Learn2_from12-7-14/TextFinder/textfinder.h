#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include<QtGui>
class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);

private slots:
    void on_findButton_clicked();
private:
    QWidget *loadUiFile();
    void loadTextFile();
    //
    QPushButton *ui_findButton;
    QTextEdit *ui_textEdit;
    QLineEdit *ui_lineEdit;
    bool needRestore;
};

#endif // TEXTFINDER_H
