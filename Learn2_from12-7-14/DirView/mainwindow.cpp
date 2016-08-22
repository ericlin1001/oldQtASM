#include "mainwindow.h"
/* void createMenu();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();
    //
    enum{NumGridRows=3,NumButtons=4};
    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton buttons[NumButtons];
    QDialogButtonBox *buttonBox;
    QMenu *fileMenu;
    QAction *exitAction;*/
MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    createMenu();
    createHorizontalGroupBox();
    createGridGroupBox();
    createFormGroupBox();
    bigEditor=new QTextEdit();
    bigEditor->setPlainText(tr("This widget take supall the remaining space "
                               "in the top-level layout."));
    buttonBox=new QDialogButtonBox(QDialogButtonBox::Ok |QDialogButtonBox::Cancel);
    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));
    //
    QVBoxLayout *main=new QVBoxLayout();
    main->setMenuBar(menuBar);
    main->addWidget(this->horizontalGroupBox);
    main->addWidget(this->gridGroupBox);
    main->addWidget(this->formGroupBox);
    main->addWidget(bigEditor);
    main->addWidget(buttonBox);
    setLayout(main);
    setWindowTitle("Basic Layouts");
}
void MainWindow::createMenu(){
    menuBar=new QMenuBar();
    fileMenu=new QMenu(tr("&File"),this);
    exitAction=fileMenu->addAction(tr("E&xit"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(accept()));

}
void MainWindow::createHorizontalGroupBox(){
    horizontalGroupBox=new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout=new QHBoxLayout();
    for(int i=0;i<NumButtons;i++){
        buttons[i]=new QPushButton(tr("Button %1").arg(i+1));
        layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}

void MainWindow::createGridGroupBox(){
    gridGroupBox=new QGroupBox(tr("Grid layout"));
    QGridLayout *layout=new QGridLayout();
    for(int i=0;i<NumGridRows;i++){
        labels[i]=new QLabel(tr("Line %1").arg(i+1));
        lineEdits[i]=new QLineEdit();
        layout->addWidget(labels[i],i+1,0);
        layout->addWidget(lineEdits[i],i+1,1);

    }
    smallEditor=new QTextEdit;
    smallEditor->setPlainText(tr("This widget takes up aboout two thirds of the grid layout."));
    layout->addWidget(smallEditor,0,2,4,1);
    //layout->setColumnStretch(1,10);
    layout->setColumnStretch(2,50);
    gridGroupBox->setLayout(layout);
}

void MainWindow::createFormGroupBox(){
    formGroupBox=new QGroupBox(tr("Form group box"));
}

MainWindow::~MainWindow()
{

}
