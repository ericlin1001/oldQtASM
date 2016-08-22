#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent)
{
    imageLabel=new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    scrollArea=new QScrollArea();
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);
    createActions();
    createMenus();
    setWindowTitle(tr("Image Viewer"));;
    resize(500,400);
}

ImageViewer::~ImageViewer()
{

}
void ImageViewer::open(){
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open Image File"),QDir::currentPath());
    if(!fileName.isEmpty()){
        QImage image(fileName);
        if(image.isNull()){
            QMessageBox::information(this,tr("Image Viewer"),tr("Cannot load %1").arg(fileName));
             return;
        }
        imageLabel->setPixmap(QPixmap::fromImage(image));
        scaleFactor=1.0;
        printAct->setEnabled(true);;
        fitToWindowAct->setEnabled(true);
        updateActions();
        if(!fitToWindowAct->isChecked()){
            imageLabel->adjustSize();
        }
    }

}

void ImageViewer::print(){

}

void ImageViewer::zoomIn(){
    scaleImage(1.25);
}

void ImageViewer::zoomOut(){
    scaleImage(0.8);
}

void ImageViewer::normalSize(){
    this->scaleFactor=1.0;
    this->imageLabel->adjustSize();
}

void ImageViewer::fitToWindow(){

}

void ImageViewer::about(){
    QMessageBox::about(this,tr("About Image Viewer"),tr("<p>The <b>Image Viewer</b>...</p>"));

}

//
void ImageViewer::createActions(){
    openAct=new QAction(tr("&Open..."),this);
    openAct->setShortcut(tr("Ctrl+O"));
    connect(openAct,SIGNAL(triggered()),this,SLOT(open()));

    printAct=new QAction(tr("&Print..."),this);
    printAct->setShortcut(tr("Ctrl+P"));
    connect(printAct,SIGNAL(triggered()),this,SLOT(print()));

    exitAct=new QAction(tr("&Close..."),this);
    exitAct->setShortcut(tr("Ctrl+C"));
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close()));

    zoomInAct=new QAction(tr("&ZoomIn..."),this);
    zoomInAct->setShortcut(tr("Ctrl+I"));
    connect(zoomInAct,SIGNAL(triggered()),this,SLOT(zoomIn()));

    zoomOutAct=new QAction(tr("&ZoomOut..."),this);
    zoomOutAct->setShortcut(tr("Ctrl+O"));
    connect(zoomOutAct,SIGNAL(triggered()),this,SLOT(zoomOut()));

    normalSizeAct=new QAction(tr("&normalSizeAct..."),this);
    connect(normalSizeAct,SIGNAL(triggered()),this,SLOT(normalSize()));

    fitToWindowAct=new QAction(tr("&fitToWindowAct..."),this);
    connect(openAct,SIGNAL(triggered()),this,SLOT(fitToWindow()));

    aboutAct=new QAction(tr("&aboutAct..."),this);
    aboutAct->setShortcut(tr("Ctrl+O"));
    connect(aboutAct,SIGNAL(triggered()),this,SLOT(about()));

    aboutAtAct=new QAction(tr("&aboutAtAct..."),this);
    aboutAtAct->setShortcut(tr("Ctrl+O"));
    connect(aboutAtAct,SIGNAL(triggered()),this,SLOT(about()));
}

void ImageViewer::createMenus(){
    QMenu *fileMenu,*viewMenu,*helpMenu;
    fileMenu=new QMenu(tr("File"),this);
    fileMenu->addAction(this->openAct);
    fileMenu->addAction(this->printAct);
    fileMenu->addAction(this->exitAct);
    fileMenu->addAction(this->openAct);

    //
    viewMenu=new QMenu(tr("View"),this);
    viewMenu->addAction(this->zoomInAct);
    viewMenu->addAction(this->zoomOutAct);
    viewMenu->addAction(this->normalSizeAct);
    viewMenu->addAction(this->fitToWindowAct);

    //
    helpMenu=new QMenu(tr("Help"),this);
    helpMenu->addAction(this->aboutAct);
    helpMenu->addAction(this->aboutAtAct);
    //
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(viewMenu);
    menuBar()->addMenu(helpMenu);
}

void ImageViewer::updateActions(){

}

void ImageViewer::scaleImage(double factor){
    Q_ASSERT(imageLabel->pixmap());
    this->scaleFactor*=factor;
    imageLabel->resize(scaleFactor*imageLabel->pixmap()->size());
    adjustScrollBar(this->scrollArea->verticalScrollBar(),factor);
    adjustScrollBar(this->scrollArea->horizontalScrollBar(),factor);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar,double factor){
    scrollBar->setValue(scrollBar->value()*factor);
}
/*
//
QLabel *imageLabel;
QScrollArea *scrollArea;
double scaleFactor;
QPrinter printer;
//actions:
QAction *openAct;
QAction *printAct;
QAction *exitAct;
QAction *zoomInAct,*zoomOutAct,*normalSizeAct,*fitToWindowAct,*aboutAct,*aboutAtAct;
QMenu *fileMenu,*viewMenu,*helpMenu;
*/
