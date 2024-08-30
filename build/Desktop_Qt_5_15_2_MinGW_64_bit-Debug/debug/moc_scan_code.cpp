/****************************************************************************
** Meta object code from reading C++ file 'scan_code.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../scan_code.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scan_code.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_scan_code_t {
    QByteArrayData data[22];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scan_code_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scan_code_t qt_meta_stringdata_scan_code = {
    {
QT_MOC_LITERAL(0, 0, 9), // "scan_code"
QT_MOC_LITERAL(1, 10, 18), // "onStartScanClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14), // "onScanFinished"
QT_MOC_LITERAL(4, 45, 18), // "onScanIDTextEdited"
QT_MOC_LITERAL(5, 64, 20), // "addScanResultToTable"
QT_MOC_LITERAL(6, 85, 6), // "result"
QT_MOC_LITERAL(7, 92, 14), // "saveJSONToFile"
QT_MOC_LITERAL(8, 107, 8), // "jsonData"
QT_MOC_LITERAL(9, 116, 8), // "fileName"
QT_MOC_LITERAL(10, 125, 19), // "create_room_temp_js"
QT_MOC_LITERAL(11, 145, 9), // "room_strc"
QT_MOC_LITERAL(12, 155, 6), // "status"
QT_MOC_LITERAL(13, 162, 11), // "send_cs_msg"
QT_MOC_LITERAL(14, 174, 12), // "QJsonObject&"
QT_MOC_LITERAL(15, 187, 7), // "root_js"
QT_MOC_LITERAL(16, 195, 3), // "cmd"
QT_MOC_LITERAL(17, 199, 21), // "cs_communicate_encode"
QT_MOC_LITERAL(18, 221, 11), // "QByteArray&"
QT_MOC_LITERAL(19, 233, 6), // "buffer"
QT_MOC_LITERAL(20, 240, 18), // "on_Savebtn_clicked"
QT_MOC_LITERAL(21, 259, 20) // "on_Stop_Scan_clicked"

    },
    "scan_code\0onStartScanClicked\0\0"
    "onScanFinished\0onScanIDTextEdited\0"
    "addScanResultToTable\0result\0saveJSONToFile\0"
    "jsonData\0fileName\0create_room_temp_js\0"
    "room_strc\0status\0send_cs_msg\0QJsonObject&\0"
    "root_js\0cmd\0cs_communicate_encode\0"
    "QByteArray&\0buffer\0on_Savebtn_clicked\0"
    "on_Stop_Scan_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scan_code[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    2,   70,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      13,    2,   78,    2, 0x08 /* Private */,
      17,    3,   83,    2, 0x08 /* Private */,
      20,    0,   90,    2, 0x08 /* Private */,
      21,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QByteArray, QMetaType::QString,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QString,   15,   16,
    QMetaType::Void, 0x80000000 | 18, QMetaType::QString, QMetaType::QString,   19,   16,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void scan_code::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<scan_code *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStartScanClicked(); break;
        case 1: _t->onScanFinished(); break;
        case 2: _t->onScanIDTextEdited(); break;
        case 3: _t->addScanResultToTable((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->saveJSONToFile((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->create_room_temp_js((*reinterpret_cast< room_strc(*)>(_a[1]))); break;
        case 6: _t->send_cs_msg((*reinterpret_cast< QJsonObject(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->cs_communicate_encode((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->on_Savebtn_clicked(); break;
        case 9: _t->on_Stop_Scan_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject scan_code::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_scan_code.data,
    qt_meta_data_scan_code,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *scan_code::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scan_code::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_scan_code.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int scan_code::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
