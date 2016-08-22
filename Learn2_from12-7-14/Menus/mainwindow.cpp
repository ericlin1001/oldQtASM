#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *w=new QWidget();
    setCentralWidget(w);
    QWidget *topFiller=new QWidget();
    topFiller->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    infoLabel=new QLabel(tr("<i>Choose a menu option,or right-click to "
                "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel|QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);
    //
    QWidget *bottomFiller=new QWidget();
    bottomFiller->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QVBoxLayout *layout=new QVBoxLayout();
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    w->setLayout(layout);
    createActions();
    createMenus();
    QString message=tr("A context menu is available by right-clicking ");
    statusBar()->showMessage(message);
    setWindowTitle(tr("Menus"));
    setMinimumSize(160,160);
    resize(480,320);
}
void MainWindow::contextMenuEvent(QContextMenuEvent *event){
    QMenu menu(this);
    menu.addAction(this->cutAct);
    menu.addAction(this->copyAct);
    menu.addAction(this->pasteAct);
    menu.exec(event->globalPos());
}

void MainWindow::createActions(){
    this->newFileAct=new QAction("&newFile",this);
    this->newFileAct->setShortcut(tr("Ctrl+N"));
    this->newFileAct->setStatusTip(tr("Create a new file"));
    connect(this->newFileAct,SIGNAL(triggered()),this,SLOT(newFile()));

    //
#define REGISTER_CREATE_ACTION(m) m##Act=new QAction("&"#m,this);                 \
                        m##Act->setStatusTip(tr("Status:"#m));                     \
                        connect(m##Act,SIGNAL(triggered()),this,SLOT(m()));
#ifdef MACRO_REGISTRE
#undef MACRO_REGISTRE
#endif
#define MACRO_REGISTRE(m) REGISTER_CREATE_ACTION(m)
   //MACRO_REGISTRE(newFile)
    MACRO_REGISTRE(open)
    MACRO_REGISTRE(save)
    MACRO_REGISTRE(print)
    MACRO_REGISTRE(exit)
    MACRO_REGISTRE(undo)
    MACRO_REGISTRE(redo)
    MACRO_REGISTRE(cut)
    MACRO_REGISTRE(copy)
    MACRO_REGISTRE(paste)
    MACRO_REGISTRE(bold)
    MACRO_REGISTRE(italic)
    MACRO_REGISTRE(leftAlign)
    MACRO_REGISTRE(rightAlign)
    MACRO_REGISTRE(justify)
    MACRO_REGISTRE(center)
    MACRO_REGISTRE(setLineSpacing)
    MACRO_REGISTRE(setParagraphSpacing)
    MACRO_REGISTRE(about)
    MACRO_REGISTRE(aboutQt)
            //
    ;//
    boldAct->setCheckable(true);
    QFont boldFont=boldAct->font();
    boldFont.setBold(true);
    boldAct->setFont(boldFont);
    italicAct->setCheckable(true);
    QFont italicFont=italicAct->font();
    italicFont.setItalic(true);
    italicAct->setFont(italicFont);
    //
    alignmentGroup=new QActionGroup(this);
    leftAlignAct->setCheckable(true);
    rightAlignAct->setCheckable(true);
    justifyAct->setCheckable(true);
    centerAct->setCheckable(true);
    alignmentGroup->addAction(this->leftAlignAct);
    alignmentGroup->addAction(this->rightAlignAct);
    alignmentGroup->addAction(this->justifyAct);
    alignmentGroup->addAction(this->centerAct);
    leftAlignAct->setChecked(true);
}
void MainWindow::createMenus(){
    // QMenu *fileMenu,*editMenu,*formatMenu,*helpMenu;
    fileMenu=menuBar()->addMenu(tr("&File"));
    editMenu=menuBar()->addMenu(tr("&Edit"));
    formatMenu=menuBar()->addMenu(tr("&Format"));
    helpMenu=menuBar()->addMenu(tr("&Help"));
    //
#define ACT(m) m##Act
    fileMenu->addAction(ACT(newFile));
    fileMenu->addAction(ACT(open));
    fileMenu->addAction(ACT(save));
    fileMenu->addAction(ACT(print));
    fileMenu->addSeparator();
    fileMenu->addAction(ACT(exit));
    //
    editMenu->addAction(ACT(undo));
    editMenu->addAction(ACT(redo));
    editMenu->addSeparator();
    editMenu->addAction(ACT(cut));
    editMenu->addAction(ACT(copy));
    editMenu->addAction(ACT(paste));
    editMenu->addSeparator();
    //
    formatMenu->addAction(ACT(bold));
    formatMenu->addAction(ACT(italic));
    formatMenu->addSeparator()->setText(tr("Alignment"));
    formatMenu->addAction(ACT(leftAlign));
    formatMenu->addAction(ACT(rightAlign));
    formatMenu->addAction(ACT(justify));
    formatMenu->addAction(ACT(center));
    formatMenu->addSeparator();
    formatMenu->addAction(ACT(setLineSpacing));
    formatMenu->addAction(ACT(setParagraphSpacing));
    //
    helpMenu->addAction(ACT(about));
    helpMenu->addAction(ACT(aboutQt));



}

MainWindow::~MainWindow()
{

}
