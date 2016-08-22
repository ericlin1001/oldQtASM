#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <QDialog>

namespace Ui {
    class loginPanel;
}

class loginPanel : public QDialog
{
    Q_OBJECT

public:
    explicit loginPanel(QWidget *parent = 0);
    ~loginPanel();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::loginPanel *ui;
};

#endif // LOGINPANEL_H
