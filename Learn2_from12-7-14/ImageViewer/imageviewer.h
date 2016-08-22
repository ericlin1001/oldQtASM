#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QtGui>

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = 0);
    ~ImageViewer();
private slots:
    void open();
    void print();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();
private:
    void createActions();
    void createMenus();
    void updateActions();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar,double factor);
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

};

#endif // IMAGEVIEWER_H
