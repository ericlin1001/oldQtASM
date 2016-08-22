#include "encryption.h"
#include "ui_encryption.h"

Encryption::Encryption(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Encryption)
{
    ui->setupUi(this);

}

Encryption::~Encryption()
{
    delete ui;
}

void Encryption::on_pushButton_2_clicked()
{
    ui->lineEdit_2->setText(ui->lineEdit->text());
}
