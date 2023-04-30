/****************************************************************************
** Meta object code from reading C++ file 'employe2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rania-dawser/employe2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employe2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_employe2_t {
    QByteArrayData data[15];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_employe2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_employe2_t qt_meta_stringdata_employe2 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "employe2"
QT_MOC_LITERAL(1, 9, 21), // "on_pb_ajouter_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_pb_supprimer_clicked"
QT_MOC_LITERAL(4, 56, 26), // "on_button_modifier_clicked"
QT_MOC_LITERAL(5, 83, 21), // "on_pdf_button_clicked"
QT_MOC_LITERAL(6, 105, 17), // "on_login2_clicked"
QT_MOC_LITERAL(7, 123, 19), // "on_line_textChanged"
QT_MOC_LITERAL(8, 143, 4), // "arg1"
QT_MOC_LITERAL(9, 148, 15), // "on_stat_clicked"
QT_MOC_LITERAL(10, 164, 36), // "on_comboBox_SUPP_currentIndex..."
QT_MOC_LITERAL(11, 201, 5), // "index"
QT_MOC_LITERAL(12, 207, 34), // "on_comboBoxtri_currentIndexCh..."
QT_MOC_LITERAL(13, 242, 24), // "on_pushButtontri_clicked"
QT_MOC_LITERAL(14, 267, 11) // "checkSeriel"

    },
    "employe2\0on_pb_ajouter_clicked\0\0"
    "on_pb_supprimer_clicked\0"
    "on_button_modifier_clicked\0"
    "on_pdf_button_clicked\0on_login2_clicked\0"
    "on_line_textChanged\0arg1\0on_stat_clicked\0"
    "on_comboBox_SUPP_currentIndexChanged\0"
    "index\0on_comboBoxtri_currentIndexChanged\0"
    "on_pushButtontri_clicked\0checkSeriel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_employe2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      12,    1,   81,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void employe2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        employe2 *_t = static_cast<employe2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pb_ajouter_clicked(); break;
        case 1: _t->on_pb_supprimer_clicked(); break;
        case 2: _t->on_button_modifier_clicked(); break;
        case 3: _t->on_pdf_button_clicked(); break;
        case 4: _t->on_login2_clicked(); break;
        case 5: _t->on_line_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_stat_clicked(); break;
        case 7: _t->on_comboBox_SUPP_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_comboBoxtri_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButtontri_clicked(); break;
        case 10: _t->checkSeriel(); break;
        default: ;
        }
    }
}

const QMetaObject employe2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_employe2.data,
      qt_meta_data_employe2,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *employe2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *employe2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_employe2.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int employe2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
