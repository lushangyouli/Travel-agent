/****************************************************************************
** Meta object code from reading C++ file 'enquiry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../secondversion/enquiry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enquiry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_enquiry_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_enquiry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_enquiry_t qt_meta_stringdata_enquiry = {
    {
QT_MOC_LITERAL(0, 0, 7), // "enquiry"
QT_MOC_LITERAL(1, 8, 18), // "ReturnToMainwindow"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 50, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(5, 74, 14), // "receiveSetTime"
QT_MOC_LITERAL(6, 89, 3), // "day"
QT_MOC_LITERAL(7, 93, 4), // "hour"
QT_MOC_LITERAL(8, 98, 7), // "minutes"
QT_MOC_LITERAL(9, 106, 4), // "name"
QT_MOC_LITERAL(10, 111, 33), // "on_comboBox_3_currentIndexCha..."
QT_MOC_LITERAL(11, 145, 4), // "arg1"
QT_MOC_LITERAL(12, 150, 10) // "timeUpDate"

    },
    "enquiry\0ReturnToMainwindow\0\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "receiveSetTime\0day\0hour\0minutes\0name\0"
    "on_comboBox_3_currentIndexChanged\0"
    "arg1\0timeUpDate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_enquiry[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    4,   47,    2, 0x08 /* Private */,
      10,    1,   56,    2, 0x08 /* Private */,
      12,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void enquiry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        enquiry *_t = static_cast<enquiry *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReturnToMainwindow(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->receiveSetTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->on_comboBox_3_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->timeUpDate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (enquiry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&enquiry::ReturnToMainwindow)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject enquiry::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_enquiry.data,
      qt_meta_data_enquiry,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *enquiry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *enquiry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_enquiry.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int enquiry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void enquiry::ReturnToMainwindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
