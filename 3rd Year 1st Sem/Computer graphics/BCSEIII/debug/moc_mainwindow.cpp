/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 17),
QT_MOC_LITERAL(4, 44, 7),
QT_MOC_LITERAL(5, 52, 3),
QT_MOC_LITERAL(6, 56, 20),
QT_MOC_LITERAL(7, 77, 15),
QT_MOC_LITERAL(8, 93, 21),
QT_MOC_LITERAL(9, 115, 21),
QT_MOC_LITERAL(10, 137, 21),
QT_MOC_LITERAL(11, 159, 7),
QT_MOC_LITERAL(12, 167, 1),
QT_MOC_LITERAL(13, 169, 7),
QT_MOC_LITERAL(14, 177, 1),
QT_MOC_LITERAL(15, 179, 19),
QT_MOC_LITERAL(16, 199, 14),
QT_MOC_LITERAL(17, 214, 16),
QT_MOC_LITERAL(18, 231, 16),
QT_MOC_LITERAL(19, 248, 10),
QT_MOC_LITERAL(20, 259, 2),
QT_MOC_LITERAL(21, 262, 2)
    },
    "MainWindow\0Mouse_Pressed\0\0showMousePosition\0"
    "QPoint&\0pos\0on_show_axes_clicked\0"
    "on_Draw_clicked\0on_set_point1_clicked\0"
    "on_set_point2_clicked\0on_pushButton_clicked\0"
    "changeX\0x\0changeY\0y\0on_showgrid_clicked\0"
    "on_dda_clicked\0on_bress_clicked\0"
    "on_midpt_clicked\0drawCircle\0p1\0r0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a,
       3,    1,   85,    2, 0x0a,
       6,    0,   88,    2, 0x08,
       7,    0,   89,    2, 0x08,
       8,    0,   90,    2, 0x08,
       9,    0,   91,    2, 0x08,
      10,    0,   92,    2, 0x08,
      11,    1,   93,    2, 0x08,
      13,    1,   96,    2, 0x08,
      15,    0,   99,    2, 0x08,
      16,    0,  100,    2, 0x08,
      17,    0,  101,    2, 0x08,
      18,    0,  102,    2, 0x08,
      19,    2,  103,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int,   12,
    QMetaType::Int, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,   20,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->showMousePosition((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->on_show_axes_clicked(); break;
        case 3: _t->on_Draw_clicked(); break;
        case 4: _t->on_set_point1_clicked(); break;
        case 5: _t->on_set_point2_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: { int _r = _t->changeX((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = _t->changeY((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->on_showgrid_clicked(); break;
        case 10: _t->on_dda_clicked(); break;
        case 11: _t->on_bress_clicked(); break;
        case 12: _t->on_midpt_clicked(); break;
        case 13: _t->drawCircle((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
