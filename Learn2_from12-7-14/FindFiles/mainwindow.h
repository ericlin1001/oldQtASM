#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
class QComboBox;
class QTableWidget;
class QLabel;
class QDir;
class MainWindow : public QDialog
{
    Q_OBJECT
private slots:
    void browse();
    void find();
private:
    QStringList findFiles(const QDir &dir,const QStringList &files,const QString &text);
    void showFiles(const QDir &dir,const QStringList &files);
    QPushButton *createButton(const QString &text,const char *member);
    void createFilesTable();
    QComboBox *createComboBox(const QString &text=QString());
    //
    QComboBox *fileComboBox,*textComboBox,*dircomboBox;
    QLabel *fileLabel,*textLabel,*dirLabel,*filesFoundLabel;
    QPushButton *browseButton,*findButton;
    QTableWidget *filesTable;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
