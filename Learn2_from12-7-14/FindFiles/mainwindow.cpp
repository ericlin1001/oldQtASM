#include "mainwindow.h"
#include<QtGui>
/*class MainWindow : public QDialog
{
    Q_OBJECT
private slots:
    void browse();
    void find();
private:
    QStringList findFiles(const QDir &dir,const QStringList &files,const QString &text);
    void showFiles(const QDir &dir,const QStringList &files);
    QPushButton *createButton(const QString &text,const char *member);
    void craeteFilesTable();
    //
    QComboBox *fileComboBox,textComboBox,dircomboBox;
    QLabel *fileLabel,*textLabel,*dirLabel,filesFoundLabel;
    QPushButton *browseButton,*findButton;
    QTableWidget *filesTable;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};*/
MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    browseButton=createButton(tr("&Browse..."),SLOT(browse()));
    findButton=createButton(tr("&Find"),SLOT(find()));
    this->fileComboBox=createComboBox(tr("*"));;
    this->textComboBox=createComboBox();
    dircomboBox=createComboBox(QDir::currentPath().replace('/','\\'));
    //
    fileLabel=new QLabel(tr("Name:"));
    textLabel=new QLabel(tr("Containing text:"));
    dirLabel=new QLabel(tr("In directory:"));
    filesFoundLabel=new QLabel();
    createFilesTable();
    //
    QHBoxLayout *btnLayout=new QHBoxLayout();
    btnLayout->addStretch();
    btnLayout->addWidget(findButton);
    QGridLayout *mainLayout=new QGridLayout();

    mainLayout->addWidget(fileLabel,0,0);mainLayout->addWidget(fileComboBox,0,1,1,2);
    mainLayout->addWidget(textLabel,1,0);mainLayout->addWidget(textComboBox,1,1,1,2);
    mainLayout->addWidget(dirLabel, 2,0);mainLayout->addWidget(dircomboBox,2,1);mainLayout->addWidget(browseButton,2,2);
    mainLayout->addWidget(filesTable,3,0,1,3);
    mainLayout->addWidget(filesFoundLabel,4,0,1,3);
    mainLayout->addLayout(btnLayout,5,0,1,3);
    setLayout(mainLayout);
    setWindowTitle(tr("Find Files"));
    resize(600,400);
}
QPushButton *MainWindow::createButton(const QString &text, const char *member){
    QPushButton *b=new QPushButton(text);
    connect(b,SIGNAL(clicked()),this,member);
    return b;
}
QComboBox *MainWindow::createComboBox(const QString &text){
    QComboBox *c=new QComboBox();
    c->setEditable(true);
    c->addItem(text);
    c->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    return c;
}
QStringList MainWindow::findFiles(const QDir &dir,const QStringList &files,const QString &text){
    QProgressDialog progressDlg(this);
    progressDlg.setCancelButtonText(tr("&Cancel"));
    progressDlg.setRange(0,files.size());
    progressDlg.setWindowTitle(tr("Find Files"));
    //
    QStringList foundFiles;
    qDebug()<<"files.size:"<<files.size();
    for(int i=0;i<files.size();i++){
        progressDlg.setValue(i);
        progressDlg.setLabelText(tr("Searching file number %1 of %2").arg(i).arg(files.size()));
        qApp->processEvents();
        if(progressDlg.wasCanceled()){
            break;
        }
        QFile file(dir.absoluteFilePath(files[i]));
        if(file.open(QIODevice::ReadOnly)){
            QString line;
            QTextStream in(&file);
            while(!in.atEnd()){
                if(progressDlg.wasCanceled()){
                    break;
                }
                line=in.readLine();
                if(line.contains(text)){
                    foundFiles<<files[i];break;
                }
            }
        }

    }
    return foundFiles;
}

void MainWindow::showFiles(const QDir &dir,const QStringList &files){
    //filesTable->clear();
    for(int i=0;i<files.size();i++){
        QFile file(dir.absoluteFilePath(files[i]));
        qint64 size=QFileInfo(file).size();
        QTableWidgetItem *fileNameItem=new QTableWidgetItem(files[i]);
        QTableWidgetItem *sizeItem=new QTableWidgetItem(tr("%1 KB").arg(int(size+1023)/1024));
        fileNameItem->setFlags(Qt::ItemIsEnabled);
        sizeItem->setFlags(Qt::ItemIsEnabled);
        sizeItem->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        //
        int row=filesTable->rowCount();
        filesTable->insertRow(row);
        filesTable->setItem(row,0,fileNameItem);
        filesTable->setItem(row,1,sizeItem);
    }
    filesFoundLabel->setText(tr("%1 file(s) found.").arg(files.size()));
}

void MainWindow::createFilesTable(){
    filesTable=new QTableWidget(0,2,this);//
    QStringList labels;
    labels<<tr("File Name")<<tr("Size");
    filesTable->setHorizontalHeaderLabels(labels);
    filesTable->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
    filesTable->verticalHeader()->hide();
    filesTable->setShowGrid(false);
}

void MainWindow::browse(){
    QString path;
    QDir test(dircomboBox->currentText());
    if(test.exists()){
        path=dircomboBox->currentText();
    }else{
        path=QDir::currentPath();
    }
    QString dir=QFileDialog::getExistingDirectory(this,tr("Find Files"),path);
    if(!dir.isEmpty()){
        for(int i=0;i<dircomboBox->count();i++){
            if(dircomboBox->itemText(i)==dir){
                dircomboBox->setCurrentIndex(i);
                return ;
            }
        }
        dircomboBox->addItem(dir);
        dircomboBox->setCurrentIndex(dircomboBox->currentIndex()+1);
    }
}

void MainWindow::find(){
    QString fileName=fileComboBox->currentText();
    QString text=textComboBox->currentText();
    QString path=dircomboBox->currentText();
    QDir dir=QDir(path);
    QStringList files;
    if(fileName.isEmpty())
        fileName="*";
    files=dir.entryList(QStringList(fileName),QDir::Files|QDir::NoSymLinks);
    if(!text.isEmpty())
        files=findFiles(dir,files,text);
    filesTable->setRowCount(0);
    showFiles(dir,files);

}

MainWindow::~MainWindow()
{

}
