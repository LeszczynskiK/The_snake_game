/****************************************************************************
** Meta object code from reading C++ file 'level_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../level_window.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'level_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSlevel_windowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSlevel_windowENDCLASS = QtMocHelpers::stringData(
    "level_window",
    "paintEvent",
    "",
    "QPaintEvent*",
    "event",
    "exitApp",
    "menuApp",
    "easyApp",
    "mediumApp",
    "hardApp",
    "ultraApp",
    "obstacleMode"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlevel_windowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x08,    1 /* Private */,
       5,    0,   65,    2, 0x08,    3 /* Private */,
       6,    0,   66,    2, 0x08,    4 /* Private */,
       7,    0,   67,    2, 0x08,    5 /* Private */,
       8,    0,   68,    2, 0x08,    6 /* Private */,
       9,    0,   69,    2, 0x08,    7 /* Private */,
      10,    0,   70,    2, 0x08,    8 /* Private */,
      11,    0,   71,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject level_window::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSlevel_windowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlevel_windowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlevel_windowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<level_window, std::true_type>,
        // method 'paintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>,
        // method 'exitApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'menuApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'easyApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mediumApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hardApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ultraApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'obstacleMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void level_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<level_window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< std::add_pointer_t<QPaintEvent*>>(_a[1]))); break;
        case 1: _t->exitApp(); break;
        case 2: _t->menuApp(); break;
        case 3: _t->easyApp(); break;
        case 4: _t->mediumApp(); break;
        case 5: _t->hardApp(); break;
        case 6: _t->ultraApp(); break;
        case 7: _t->obstacleMode(); break;
        default: ;
        }
    }
}

const QMetaObject *level_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *level_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlevel_windowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int level_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
