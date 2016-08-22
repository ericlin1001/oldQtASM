#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void contextMenuEvent(QContextMenuEvent *event);
    void showText(QString str){
        infoLabel->setText(str);

    }

private slots:
#define MACRO_REGISTRE_SLOT(m) inline void m(){showText(tr("Invoked "#m"."));}
#ifdef MACRO_REGISTRE
#undef MACRO_REGISTRE
#endif
#define MACRO_REGISTRE(m) MACRO_REGISTRE_SLOT(m)

    inline void newFile(){showText(tr("Invoked newFile."));}
    inline void open(){showText(tr("Invoked open."));}
    inline void save(){showText(tr("Invoked save."));}
    inline void print(){showText(tr("Invoked print."));}
    inline void exit(){showText(tr("Invoked exit."));}
    inline void undo(){showText(tr("Invoked undo."));}
    inline void redo(){showText(tr("Invoked redo."));}
    inline void cut(){showText(tr("Invoked cut."));}
    inline void copy(){showText(tr("Invoked copy."));}
    inline void paste(){showText(tr("Invoked paste."));}
    inline void bold(){showText(tr("Invoked bold."));}
    inline void italic(){showText(tr("Invoked italic."));}
    inline void leftAlign(){showText(tr("Invoked leftAlign."));}
    inline void rightAlign(){showText(tr("Invoked rightAlign."));}
    inline void justify(){showText(tr("Invoked justify."));}
    inline void center(){showText(tr("Invoked center."));}
    inline void setLineSpacing(){showText(tr("Invoked setLineSpacing."));}
    inline void setParagraphSpacing(){showText(tr("Invoked setParagraphSpacing."));}
    inline void about(){showText(tr("Invoked about."));}
    inline void aboutQt(){showText(tr("Invoked aboutQt."));}
//
private:
    void createActions();
    void createMenus();
    //
    QLabel *infoLabel;
    //
private:

    QMenu *fileMenu,*editMenu,*formatMenu,*helpMenu;
    QActionGroup *alignmentGroup;
    //
#define REGISTER_ACTION(m) QAction *m##Act;
#ifdef MACRO_REGISTRE
#undef MACRO_REGISTRE
#endif
#define MACRO_REGISTRE(m) REGISTER_ACTION(m)
    MACRO_REGISTRE(newFile)
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
};

#endif // MAINWINDOW_H
