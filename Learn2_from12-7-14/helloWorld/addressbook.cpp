#include"addressbook.h"
#include<QLabel>
#include<QGridLayout>
#include<QMessageBox>

    FindDialog::FindDialog(QWidget *parent):QDialog(parent){
        findBtn=new QPushButton(tr("&Find"));
        findEdit=new QLineEdit();
        QLabel *findLabel=new QLabel(tr("The name of contact:"));
        findEdit->setFocus();
        connect(findBtn,SIGNAL(clicked()),this,SLOT(findClicked()));
        connect(findBtn,SIGNAL(clicked()),this,SLOT(accept()));
        QHBoxLayout *layout=new QHBoxLayout;
        layout->addWidget(findLabel);
        layout->addWidget(findEdit);
        layout->addWidget(findBtn);
        setLayout(layout);
        setWindowTitle(tr("Find a contact"));
        findText="";
        hide();
    }
    QString FindDialog::getFindText(){
        return this->findText;
    }

    void FindDialog::findClicked(){
        findText=this->findEdit->text();
        if(findText.isEmpty()){
            QMessageBox::information(this,tr("Empty Field"),tr("Please enter a name."));
            return ;
        }else{
            findEdit->clear();
            hide();
        }
    }







///*****************
AdressBook:: AdressBook(QWidget *parent):QWidget(parent){
    QLabel *nameLabel=new QLabel(tr("Name:"));
    nameLine=new QLineEdit;
    QLabel *addressLabel=new QLabel(tr("Address:"));
    addressText=new QTextEdit;

           //
    addBtn=new QPushButton(tr("&Add"));
    submitBtn=new QPushButton(tr("&Submit"));
    cancelBtn=new QPushButton(tr("&Cancel"));
    nextBtn=new QPushButton(tr("&Next"));
    previousBtn=new QPushButton(tr("&Previous"));
    editBtn=new QPushButton(tr("&Edit"));
    removeBtn=new QPushButton(tr("&Remove"));
    findDialog=new FindDialog();
    findBtn=new QPushButton(tr("&Find"));
    findBtn->setEnabled(false);
    this->loadBtn=new QPushButton(tr("&Load..."));
    loadBtn->setToolTip(tr("Load contacts from a file"));
    this->saveBtn=new QPushButton(tr("&Save..."));
    saveBtn->setToolTip(tr("Save contacts to file."));
    //
    nameLine->setReadOnly(true);
    addressText->setReadOnly(true);

    addBtn->setEnabled(true);
    submitBtn->hide();
    cancelBtn->hide();
    //
    nextBtn->setEnabled(false);
    previousBtn->setEnabled(false);
    editBtn->setEnabled(false);
    removeBtn->setEnabled(false);

    //
    connect(addBtn,SIGNAL(clicked()),this,SLOT(addContact()));
    connect(submitBtn,SIGNAL(clicked()),this,SLOT(submitContact()));
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(cancel()));
    connect(nextBtn,SIGNAL(clicked()),this,SLOT(next()));
    connect(previousBtn,SIGNAL(clicked()),this,SLOT(previous()));
    connect(editBtn,SIGNAL(clicked()),this,SLOT(editContact()));
    connect(removeBtn,SIGNAL(clicked()),this,SLOT(removeContact()));
    connect(findBtn,SIGNAL(clicked()),this,SLOT(findContact()));
    connect(this->loadBtn,SIGNAL(clicked()),this,SLOT(loadFromFile()));
    connect(this->saveBtn,SIGNAL(clicked()),this,SLOT(saveToFile()));
    //
    QVBoxLayout *btnLayout=new QVBoxLayout;
    btnLayout->addWidget(addBtn,Qt::AlignTop);
    btnLayout->addWidget(submitBtn);
    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(editBtn);
    btnLayout->addWidget(removeBtn);
    btnLayout->addWidget(findBtn);
    btnLayout->addWidget(this->loadBtn);
    btnLayout->addWidget(this->saveBtn);
    btnLayout->addStretch();
    //
    QHBoxLayout *browerLayout=new QHBoxLayout();
    browerLayout->addWidget(nextBtn);
    browerLayout->addWidget(previousBtn);
    //
    QGridLayout *mainLayout=new QGridLayout();
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(nameLine,0,1);
    mainLayout->addWidget(addressLabel,1,0,Qt::AlignTop);
    mainLayout->addWidget(addressText,1,1);
    mainLayout->addLayout(btnLayout,1,2);
    mainLayout->addLayout(browerLayout,2,1);
    //
    setLayout(mainLayout);
    setWindowTitle(tr("Simple Address book"));
//

   }

void AdressBook::addContact(){
    nameLine->clear();
    addressText->clear();
    nameLine->setFocus(Qt::OtherFocusReason);
    updateMode(AddingMode);
}

void AdressBook::submitContact(){
    QString name,address;
    name=nameLine->text();
    address=addressText->toPlainText();

    if(name=="" || address ==""){
        QMessageBox::information(this,"Fail","Field can't be empty!");
        return ;
    }
    if(currentMode==AddingMode){
        if(contacts.contains(name)){
            QMessageBox::information(this,"Fail",tr("Already has this person \"%1\" \"%2\"!").arg(name,contacts[name]));
        }else{
            contacts.insert(name,address);
            oldname=name;
            oldAddress=address;
            QMessageBox::information(this,"Sucess","OK!");
        }
        if(contacts.isEmpty()){
            nameLine->clear();
            addressText->clear();
        }
    }else if(currentMode==EditingMode){
        if(oldname!=name){
            if(!contacts.contains(name)){
                contacts.remove(oldname);
                contacts.insert(name,address);
                oldname=name;
                oldAddress=address;
                QMessageBox::information(this,tr("Edit Success"),tr("\"%1\" has been edited in your address book.").arg((name)));
            }else{
                QMessageBox::information(this,tr("Edit fail"),tr("Sorry,\"%1\" is already in your address book.").arg((name)));
            }
        }else if(oldAddress!=address){
            contacts[name]=address;
            oldname=name;
            oldAddress=address;
            QMessageBox::information(this,tr("Edit Success"),tr("\"%1\" has been edited in your address book.").arg((name)));
        }
    }
    //
    nameLine->setText(oldname);
    addressText->setText(oldAddress);
    //
    updateMode(NavigationMode);
}
void AdressBook::cancel(){
    nameLine->setText(oldname);
    addressText->setText(oldAddress);
    updateMode(NavigationMode);
}
void AdressBook::next(){
    QString name=nameLine->text();
    QMap<QString,QString>::iterator i=contacts.find(name);
    if(i!=contacts.end())i++;
    if(i==contacts.end())i=contacts.begin();
    nameLine->setText(i.key());
    addressText->setText(i.value());
}

void AdressBook::previous(){
    QString name=nameLine->text();
    QMap<QString,QString>::iterator i=contacts.find(name);
    if(i==contacts.begin())i=contacts.end();
    if(i!=contacts.begin())i--;
    //
    nameLine->setText(i.key());
    addressText->setText(i.value());
}
void AdressBook::editContact(){
    oldname=nameLine->text();
    oldAddress=addressText->toPlainText();
    updateMode(EditingMode);
}

void AdressBook::removeContact(){
    QString name,address;
    name=nameLine->text();
    address=addressText->toPlainText();
    if(contacts.contains(name)){
        int choose=QMessageBox::question(this,tr("Confirm Remove"),tr("Are you sure yuo want to remove \"%1\"?").arg(name),
                QMessageBox::Yes|QMessageBox::No);
        if(choose==QMessageBox::Yes){
            previous();
            contacts.remove(name);
            QMessageBox::question(this,tr("Remove successfully"),tr("\"%1\" has been removed from your address book.").arg(name));
        }
    }
    updateMode(NavigationMode);
}
void AdressBook::updateMode(Mode mode){
    currentMode=mode;
    switch(mode){
        case NavigationMode:
            if(contacts.isEmpty()){
                nameLine->clear();
                addressText->clear();
            }

            nameLine->setReadOnly(true);
            addressText->setReadOnly(true);
            addBtn->setEnabled(true);
            //
            editBtn->setEnabled(true);
            removeBtn->setEnabled(true);
            nextBtn->setEnabled(contacts.size()>1);
            previousBtn->setEnabled(contacts.size()>1);
            //
            submitBtn->hide();
            cancelBtn->hide();
            findBtn->setEnabled(true);
            break;
        case EditingMode:

        case AddingMode:
            nameLine->setReadOnly(false);
            nameLine->setFocus();
            addressText->setReadOnly(false);
            addBtn->setEnabled(false);
            //
            editBtn->setEnabled(false);
            removeBtn->setEnabled(false);
            nextBtn->setEnabled(false);
            previousBtn->setEnabled(false);
            //
            submitBtn->show();
            cancelBtn->show();
            findBtn->setEnabled(false);
            break;
        default:
            break;
    }/*nameLine->setReadOnly(true);
    addressText->setReadOnly(true);
    addBtn->setEnabled(true);
    submitBtn->hide();
    cancelBtn->hide();
    n
    nextBtn->setEnabled(contacts.size());
    previousBtn->setEnabled(contacts.size());*/
}
void AdressBook::log(const QString &a,const QString& b){
    QMessageBox::information(this,a,b);
}

void AdressBook::findContact(){
    this->findDialog->show();
    if(this->findDialog->exec()==QDialog::Accepted){
        QString name=this->findDialog->getFindText();
        if(contacts.contains(name)){
            nameLine->setText(name);
            addressText->setText(contacts[name]);
        }else{
            QMessageBox::information(this,tr("Contact Not Found"),
                                     tr("Sorry,\"%1\" is not in your address book.").arg(name));
            return ;
        }
    }
    updateMode(NavigationMode);
}
#include<QFileDialog>
void AdressBook::saveToFile(){
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save Address Book"),"",tr("Address Book (*.abk);;All Files(*)"));
    if(fileName.isEmpty())return ;
    else{
        QFile file(fileName);
        if(!file.open((QIODevice::WriteOnly))){
            log("Unable to Open file",file.errorString());return ;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_3);
        out<<contacts;
    }
}

void AdressBook::loadFromFile(){
    QString fileName=QFileDialog::getOpenFileName(this,tr("Save Address Book"),"",tr("Address Book (*.abk);;All Files(*)"));
    if(fileName.isEmpty())return ;
    else{
        QFile file(fileName);
        if(!file.open((QIODevice::ReadOnly))){
            log("Unable to Open file",file.errorString());return ;
        }
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_3);
        contacts.empty();
        in>>contacts;
        if(contacts.isEmpty()){
            log("No contacts in file","The file you are attempting to open contains no contacts.");
        }else{
            nameLine->setText(contacts.begin().key());
            addressText->setText(contacts.begin().value());

        }
    }
    updateMode(NavigationMode);
}
