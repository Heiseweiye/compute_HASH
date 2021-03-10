/****************************************************************************
** Meta object code from reading C++ file 'HASH.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HASH.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HASH.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HASH_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HASH_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HASH_t qt_meta_stringdata_HASH = {
    {
QT_MOC_LITERAL(0, 0, 4), // "HASH"
QT_MOC_LITERAL(1, 5, 8), // "OnbtnCom"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 12), // "OnbtnComSHA1"
QT_MOC_LITERAL(4, 28, 15), // "OnSlecbtn_plain"
QT_MOC_LITERAL(5, 44, 14), // "OnSlecbtn_file"
QT_MOC_LITERAL(6, 59, 9), // "OnbtnOpen"
QT_MOC_LITERAL(7, 69, 10) // "OnbtnOpen2"

    },
    "HASH\0OnbtnCom\0\0OnbtnComSHA1\0OnSlecbtn_plain\0"
    "OnSlecbtn_file\0OnbtnOpen\0OnbtnOpen2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HASH[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void HASH::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HASH *_t = static_cast<HASH *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnbtnCom(); break;
        case 1: _t->OnbtnComSHA1(); break;
        case 2: { int _r = _t->OnSlecbtn_plain();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->OnSlecbtn_file();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->OnbtnOpen();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->OnbtnOpen2();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject HASH::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HASH.data,
      qt_meta_data_HASH,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HASH::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HASH::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HASH.stringdata0))
        return static_cast<void*>(const_cast< HASH*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HASH::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
