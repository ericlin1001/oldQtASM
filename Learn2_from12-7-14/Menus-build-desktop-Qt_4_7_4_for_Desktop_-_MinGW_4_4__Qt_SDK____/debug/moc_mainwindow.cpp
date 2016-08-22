/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Jul 18 00:09:34 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Menus/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      22,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      44,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      71,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newFile()\0open()\0save()\0"
    "print()\0exit()\0undo()\0redo()\0cut()\0"
    "copy()\0paste()\0bold()\0italic()\0"
    "leftAlign()\0rightAlign()\0justify()\0"
    "center()\0setLineSpacing()\0"
    "setParagraphSpacing()\0about()\0aboutQt()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newFile(); break;
        case 1: open(); break;
        case 2: save(); break;
        case 3: print(); break;
        case 4: exit(); break;
        case 5: undo(); break;
        case 6: redo(); break;
        case 7: cut(); break;
        case 8: copy(); break;
        case 9: paste(); break;
        case 10: bold(); break;
        case 11: italic(); break;
        case 12: leftAlign(); break;
        case 13: rightAlign(); break;
        case 14: justify(); break;
        case 15: center(); break;
        case 16: setLineSpacing(); break;
        case 17: setParagraphSpacing(); break;
        case 18: about(); break;
        case 19: aboutQt(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
