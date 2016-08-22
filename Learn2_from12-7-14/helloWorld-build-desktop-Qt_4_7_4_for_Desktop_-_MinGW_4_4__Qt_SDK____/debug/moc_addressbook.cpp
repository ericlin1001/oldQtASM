/****************************************************************************
** Meta object code from reading C++ file 'addressbook.h'
**
** Created: Mon Jul 16 00:00:36 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../helloWorld/addressbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addressbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FindDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FindDialog[] = {
    "FindDialog\0\0findClicked()\0"
};

const QMetaObject FindDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FindDialog,
      qt_meta_data_FindDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FindDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FindDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FindDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FindDialog))
        return static_cast<void*>(const_cast< FindDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FindDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: findClicked(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_AdressBook[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      25,   11,   11,   11, 0x0a,
      41,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,
      57,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
      82,   11,   11,   11, 0x0a,
      98,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdressBook[] = {
    "AdressBook\0\0addContact()\0submitContact()\0"
    "cancel()\0next()\0previous()\0editContact()\0"
    "removeContact()\0findContact()\0"
    "saveToFile()\0loadFromFile()\0"
};

const QMetaObject AdressBook::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AdressBook,
      qt_meta_data_AdressBook, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AdressBook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AdressBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AdressBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdressBook))
        return static_cast<void*>(const_cast< AdressBook*>(this));
    return QWidget::qt_metacast(_clname);
}

int AdressBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addContact(); break;
        case 1: submitContact(); break;
        case 2: cancel(); break;
        case 3: next(); break;
        case 4: previous(); break;
        case 5: editContact(); break;
        case 6: removeContact(); break;
        case 7: findContact(); break;
        case 8: saveToFile(); break;
        case 9: loadFromFile(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
