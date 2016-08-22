#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createIconGroupBox();
    //iconLabel->setMinimumWidth(durationLabel->sizeHint().width());
    createMessageGroupBox();
    createActions();
    createTrayIcon();
    connect(this->showMessageButton,SIGNAL(clicked()),this,SLOT(showMessage()));
    connect(this->showIconCheckBox,SIGNAL(toggled(bool)),SLOT(setVisible(bool)));
    connect(this->iconComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setIcon(int)));
    connect(this->trayIcon,SIGNAL(messageClicked()),this,SLOT(messageClicked()));
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    iconComboBox->setCurrentIndex(1);
    trayIcon->show();
    //
    QVBoxLayout *mainLayout=new QVBoxLayout();
    mainLayout->addWidget(this->iconGroupBox);
    mainLayout->addWidget(this->messageGroupBox);
    setLayout(mainLayout);
    setWindowTitle(tr("Systray"));
    setMinimumSize(160,160);
    //resize(400,300)
}
void MainWindow::setVisible(bool visible){
    miniAction->setEnabled(visible);
    maxAction->setEnabled(!this->isMinimized());
    restoreAction->setEnabled(this->isMaximized()||!visible);
    QWidget::setVisible(visible);
}

void MainWindow::closeEvent(QCloseEvent *event){
    if(trayIcon->isVisible()){
        QMessageBox::information(this,tr("Systray"),tr("The program will keep running in the "
                                                       "system tray.To terminate the program,"
                                                       "choose <b>Quit</b> in the context menu"
                                                       "that ops up when clicking this program's "
                                                       "entry in the system tray."));
        hide();
        event->ignore();
    }

}

//
void MainWindow::setIcon(int index){
    QIcon icon=this->iconComboBox->itemIcon(index);
    trayIcon->setIcon(icon);;
    setWindowIcon(icon);
    trayIcon->setToolTip(iconComboBox->itemText(index));
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason){
    switch(reason){
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
            iconComboBox->setCurrentIndex((iconComboBox->currentIndex()+1)%this->iconComboBox->count());
            break;
        case QSystemTrayIcon::MiddleClick:
            showMessage();
            break;
        default:
            break;

    }
}

void MainWindow::showMessage(){
    //enum MessageIcon { NoIcon, Information, Warning, Critical };
    QSystemTrayIcon::MessageIcon icon=QSystemTrayIcon::MessageIcon(this->typeComboBox->itemData(this->typeComboBox->currentIndex()).toInt());
    qDebug()<<tr("type:")<<icon;
    trayIcon->showMessage(this->titleEdit->text(),bodyEdit->toPlainText(),icon,this->durationsSpinBox->value()*1000);
}

void MainWindow::messageClicked(){
    QMessageBox::information(0,tr("Systray"),
                             tr("Sorry, I already gave what help I could\n"
                                "May be you shold try asking a human?"));

}

//
void MainWindow::createIconGroupBox(){
    /*QGroupBox *iconGroupBox;
QLabel *iconLabel;
QComboBox *iconComboBox;
QCheckBox *sowIconCheckBox;*/
    iconGroupBox=new QGroupBox(tr("Tray Icon"));
    iconLabel=new QLabel(tr("Icon:"));
    iconComboBox=new QComboBox(this);
    //iconLabel->setBuddy(iconComboBox);
    showIconCheckBox=new QCheckBox(tr("Show Icon"));
    //
    QString suffix=tr(".svg");
    iconComboBox->addItem(QIcon(":/icons/bad"+suffix),tr("bad"));
    iconComboBox->addItem(QIcon(":/icons/heart"+suffix),tr("heart"));
    iconComboBox->addItem(QIcon(":/icons/trash"+suffix),tr("trash"));
    showIconCheckBox->setChecked(true);
    //
    QHBoxLayout *layout=new QHBoxLayout();
    layout->addWidget(iconLabel);
    layout->addWidget(iconComboBox);
    layout->addStretch();
    layout->addWidget(showIconCheckBox);
    iconGroupBox->setLayout(layout);
    //



}

void MainWindow::createMessageGroupBox(){

    messageGroupBox=new QGroupBox(tr("Balloon Message"));
    messageGroupBox->setAlignment(Qt::AlignLeft);
    typeLabel=new QLabel(tr("Type:"));
    durationLabel=new QLabel(tr("Duration:"));
    durationWarningLabel=new QLabel(tr("(Icon)some systems might ignore this hint)"));
    titleLabel=new QLabel(tr("Title:"));
    bodyLabel=new QLabel(tr("Body:"));
//
    typeComboBox=new QComboBox();
    durationsSpinBox=new QSpinBox();
    titleEdit=new QLineEdit(tr("Cann't connect to network"));
    bodyEdit=new QTextEdit(tr("Don't believe me.Honestly,I don't have a clue."
                              "\nclick this balloon for details."));
    showMessageButton =new QPushButton(tr("Show Message"));
    //
    typeComboBox->addItem(tr("None"),QSystemTrayIcon::NoIcon);
    /*SP_MessageBoxInformation,
        SP_MessageBoxWarning,
        SP_MessageBoxCritical,
        SP_MessageBoxQuestion,*/
    typeComboBox->addItem(style()->standardIcon(QStyle::SP_MessageBoxInformation),tr("Information"),QSystemTrayIcon::Information);
    typeComboBox->addItem(style()->standardIcon(QStyle::SP_MessageBoxWarning),tr("Warning"),QSystemTrayIcon::Warning);
    typeComboBox->addItem(style()->standardIcon(QStyle::SP_MessageBoxCritical),tr("Critical"),QSystemTrayIcon::Critical);
    typeComboBox->setCurrentIndex(1);
    //
    durationsSpinBox->setRange(5,60);
    durationsSpinBox->setSuffix(tr(" s"));
    durationsSpinBox->setValue(15);
    //
    durationWarningLabel->setIndent(10);
    showMessageButton->setDefault(true);
    //
    QGridLayout *layout=new QGridLayout();
    layout->addWidget(typeLabel,0,0);layout->addWidget(typeComboBox,0,1,1,2);
    layout->addWidget(durationLabel,1,0);layout->addWidget(durationsSpinBox,1,1);layout->addWidget(durationWarningLabel,1,2,1,3);
    layout->addWidget(titleLabel,2,0);layout->addWidget(titleEdit,2,1,1,4);
    layout->addWidget(bodyLabel,3,0);layout->addWidget(bodyEdit,3,1,2,4);
    layout->addWidget(showMessageButton,5,4);
    layout->setColumnStretch(3,1);
    layout->setRowStretch(4,1);
   //
    messageGroupBox->setLayout(layout);
}
/*    QAction *restoreAction;
    QAction *quitAction;*/
void MainWindow::createActions(){
    this->miniAction=new QAction (tr("Mi&nimize"),this);
    this->maxAction=new QAction (tr("Ma&ximize"),this);
    this->restoreAction=new QAction (tr("$Restore"),this);
    this->quitAction=new QAction (tr("&Quit"),this);
    connect(this->miniAction,SIGNAL(triggered()),this,SLOT(hide()));
    connect(this->maxAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    connect(this->restoreAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    connect(this->quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));


}

void MainWindow::createTrayIcon(){
    this->trayIcon=new QSystemTrayIcon(this);
    this->trayIconMenu=new QMenu(this);
    trayIconMenu->addAction(this->miniAction);
    trayIconMenu->addAction(this->maxAction);
    trayIconMenu->addAction(this->restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(this->quitAction);
    this->trayIcon->setContextMenu(this->trayIconMenu);
}

/*
QGroupBox *iconGroupBox;
QLabel *iconLabel;
QComboBox *iconComboBox;
QCheckBox *sowIconCheckBox;
//
QGroupBox *messageGroupBox;
QLabel *typeLabComboBox;
QSpinBox *durationsSpinBox;
QLineEdit *titleEdit;
QTextEdit *bodyEdit;
QPushButton *showMessageButton;
Qction *miniAction;
QAction *maxAction;
QAction *restoreAction;
QAction *quitAction;*/
MainWindow::~MainWindow()
{

}
