#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void setVisible(bool visible);
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void setIcon(int index);
    void iconActivated(QSystemTrayIcon::ActivationReason reson);
    void showMessage();
    void messageClicked();
private:
    void createIconGroupBox();
    void createMessageGroupBox();
    void createActions();
    void createTrayIcon();
    //
    QGroupBox *iconGroupBox;
    QLabel *iconLabel;
    QComboBox *iconComboBox;
    QCheckBox *showIconCheckBox;
    //
    QGroupBox *messageGroupBox;
    QLabel *typeLabel,*durationLabel,*durationWarningLabel,*titleLabel,*bodyLabel;
    QComboBox *typeComboBox;
    QSpinBox *durationsSpinBox;
    QLineEdit *titleEdit;
    QTextEdit *bodyEdit;
    QPushButton *showMessageButton;
    QAction *miniAction;
    QAction *maxAction;
    QAction *restoreAction;
    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
};

#endif // MAINWINDOW_H
