#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *mainLayout=new QGridLayout();

    mainLayout->addWidget(createFirstExclusiveGroup(),0,0);
    mainLayout->addWidget(createSecondExclusiveGroup(),1,0);
    mainLayout->addWidget(createNonExclusiveGroup(),0,1);
    mainLayout->addWidget(createButtonGroup(),1,1);

    setLayout(mainLayout);
    setWindowTitle("Group Boxes");

}
QGroupBox* MainWindow::createFirstExclusiveGroup(){
    QGroupBox *group=new QGroupBox(tr("Exclusive Radio Buttons"));
    QVBoxLayout *layout=new QVBoxLayout();
    QRadioButton *radios[3];
    for(int i=0;i<3;i++){
        radios[i]=new QRadioButton(tr("Radio button %1").arg(i+1));
        layout->addWidget(radios[i]);
    }
    radios[0]->setChecked(true);
    //
    layout->addStretch();
    group->setLayout(layout);
    return group;
}

QGroupBox* MainWindow::createSecondExclusiveGroup(){
    QGroupBox *group=new QGroupBox(tr("Exclusive Radio Buttons"));
    group->setCheckable(true);
    group->setChecked(false);

    QVBoxLayout *layout=new QVBoxLayout();
    QRadioButton *radios[3];
    for(int i=0;i<3;i++){
        radios[i]=new QRadioButton(tr("Radio button %1").arg(i+1));
        layout->addWidget(radios[i]);
    }
    radios[0]->setChecked(true);
    QCheckBox *box=new QCheckBox();
    box->setCheckable(true);
    box->setChecked(true);
    layout->addWidget(box);
    //
    layout->addStretch();
    group->setLayout(layout);
    return group;
}

QGroupBox* MainWindow::createNonExclusiveGroup(){
    QGroupBox *group=new QGroupBox(tr("Non-Exclusive Radio Buttons"));
    group->setFlat(true);

    QVBoxLayout *layout=new QVBoxLayout();
    QCheckBox *boxes[2];
    for(int i=0;i<2;i++){
        boxes[i]=new QCheckBox(tr("Checkbox button %1").arg(i+1));
        layout->addWidget(boxes[i]);
    }
    boxes[1]->setChecked(true);

    QCheckBox *box=new QCheckBox();
    box->setTristate(true);
    box->setCheckState(Qt::PartiallyChecked);
    layout->addWidget(box);
    //
    layout->addStretch();
    group->setLayout(layout);
    return group;

}

QGroupBox* MainWindow::createButtonGroup(){
    QGroupBox *group=new QGroupBox(tr("&Push Buttons"));
    group->setCheckable(true);
    group->setChecked(true);

    QVBoxLayout *layout=new QVBoxLayout();
    QPushButton *buttons[4];
    for(int i=0;i<4;i++){
        buttons[i]=new QPushButton();
        layout->addWidget(buttons[i]);
    }
    buttons[0]->setText(tr("&Normal Button"));
    buttons[1]->setText(tr("&Toggle Button"));
    buttons[1]->setCheckable(true);
    buttons[1]->setChecked(true);
    buttons[2]->setText(tr("&Flat Button"));
    buttons[2]->setFlat(true);
    //
    QMenu *menu=new QMenu;
    menu->addAction(tr("menu1"));
    menu->addAction(tr("menu2"));
    menu->addAction(tr("menu3"));
    menu->addAction(tr("menu4"));
    QAction *subMenuAction=menu->addAction(tr("subMenu"));
    QMenu *subMenu=new QMenu();
    subMenu->addAction(tr("submenu1"));
    connect(subMenu->addAction(tr("submenu1")),SIGNAL(triggered()),this,SLOT(testSlot()));
    subMenuAction->setMenu(subMenu);
    buttons[3]->setText(tr("Pop&up Button"));
    buttons[3]->setMenu(menu);

    //
    layout->addStretch();
    group->setLayout(layout);
    return group;

}

MainWindow::~MainWindow()
{

}
