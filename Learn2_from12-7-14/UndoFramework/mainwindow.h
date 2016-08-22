#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include<QUndoStack>
#include<DiagramScene>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void iteMoved(DiagramItem *movedDiagram,const QPointF &moveStartPosition);
private slots:
    void deleteItem();
    void addBox();
    void addTriangle();
    void about();
    void itemMenuAboutToShow();
    void itemMenuAboutToHide();
private:
    void createActions();
    void createMenus();
    void createUndoView();
    //
    QAction *deleteAct,*addBoxAct,*addTriangleAct,*undoAct,*redoAct,*exitAct,*aboutAct;
    QMenu *fileMenu,*editMenu,itemMenu,helpMenu;
    QUndoStack *undoStack;
    DiagramScene *diagramScene;
    QUndoView *undoView;
    //
};

#endif // MAINWINDOW_H
