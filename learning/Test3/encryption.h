#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QMainWindow>

namespace Ui {
    class Encryption;
}

class Encryption : public QMainWindow
{
    Q_OBJECT

public:
    explicit Encryption(QWidget *parent = 0);
    ~Encryption();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Encryption *ui;
};

#endif // ENCRYPTION_H
