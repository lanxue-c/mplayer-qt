/****************************************************************************
** Meta object code from reading C++ file 'miniform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "miniform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'miniform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MiniForm_t {
    QByteArrayData data[22];
    char stringdata0[323];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MiniForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MiniForm_t qt_meta_stringdata_MiniForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MiniForm"
QT_MOC_LITERAL(1, 9, 7), // "suspend"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "last_song"
QT_MOC_LITERAL(4, 28, 9), // "next_song"
QT_MOC_LITERAL(5, 38, 7), // "quitout"
QT_MOC_LITERAL(6, 46, 4), // "mute"
QT_MOC_LITERAL(7, 51, 6), // "shoutt"
QT_MOC_LITERAL(8, 58, 8), // "minimize"
QT_MOC_LITERAL(9, 67, 9), // "value_num"
QT_MOC_LITERAL(10, 77, 3), // "num"
QT_MOC_LITERAL(11, 81, 11), // "lrc_control"
QT_MOC_LITERAL(12, 93, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(13, 117, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 139, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(15, 163, 24), // "on_pushButton_13_clicked"
QT_MOC_LITERAL(16, 188, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(17, 212, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(18, 236, 30), // "on_verticalSlider_valueChanged"
QT_MOC_LITERAL(19, 267, 5), // "value"
QT_MOC_LITERAL(20, 273, 24), // "on_pushButton_14_clicked"
QT_MOC_LITERAL(21, 298, 24) // "on_pushButton_15_clicked"

    },
    "MiniForm\0suspend\0\0last_song\0next_song\0"
    "quitout\0mute\0shoutt\0minimize\0value_num\0"
    "num\0lrc_control\0on_pushButton_2_clicked\0"
    "on_pushButton_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_13_clicked\0"
    "on_pushButton_5_clicked\0on_pushButton_9_clicked\0"
    "on_verticalSlider_valueChanged\0value\0"
    "on_pushButton_14_clicked\0"
    "on_pushButton_15_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MiniForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    0,  110,    2, 0x06 /* Public */,
       9,    1,  111,    2, 0x06 /* Public */,
      11,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  115,    2, 0x08 /* Private */,
      13,    0,  116,    2, 0x08 /* Private */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    0,  119,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    1,  121,    2, 0x08 /* Private */,
      20,    0,  124,    2, 0x08 /* Private */,
      21,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MiniForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MiniForm *_t = static_cast<MiniForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->suspend(); break;
        case 1: _t->last_song(); break;
        case 2: _t->next_song(); break;
        case 3: _t->quitout(); break;
        case 4: _t->mute(); break;
        case 5: _t->shoutt(); break;
        case 6: _t->minimize(); break;
        case 7: _t->value_num((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->lrc_control(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->on_pushButton_3_clicked(); break;
        case 12: _t->on_pushButton_13_clicked(); break;
        case 13: _t->on_pushButton_5_clicked(); break;
        case 14: _t->on_pushButton_9_clicked(); break;
        case 15: _t->on_verticalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_pushButton_14_clicked(); break;
        case 17: _t->on_pushButton_15_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::suspend)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::last_song)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::next_song)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::quitout)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::mute)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::shoutt)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::minimize)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::value_num)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MiniForm::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MiniForm::lrc_control)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject MiniForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MiniForm.data,
      qt_meta_data_MiniForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MiniForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MiniForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MiniForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MiniForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MiniForm::suspend()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MiniForm::last_song()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MiniForm::next_song()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MiniForm::quitout()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MiniForm::mute()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MiniForm::shoutt()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MiniForm::minimize()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MiniForm::value_num(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MiniForm::lrc_control()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
