/****************************************************************************
** Meta object code from reading C++ file 'maingame.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../maingame.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maingame.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSmaingameENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmaingameENDCLASS = QtMocHelpers::stringData(
    "maingame",
    "paintEvent",
    "",
    "QPaintEvent*",
    "event",
    "exitApp",
    "menuApp",
    "displayDeathMessage",
    "resetGame",
    "moveSnake",
    "generateObstacle",
    "pauseGame",
    "updateCountdown",
    "clearPauseText"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmaingameENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x08,    1 /* Private */,
       5,    0,   77,    2, 0x08,    3 /* Private */,
       6,    0,   78,    2, 0x08,    4 /* Private */,
       7,    0,   79,    2, 0x08,    5 /* Private */,
       8,    0,   80,    2, 0x08,    6 /* Private */,
       9,    0,   81,    2, 0x08,    7 /* Private */,
      10,    0,   82,    2, 0x08,    8 /* Private */,
      11,    0,   83,    2, 0x08,    9 /* Private */,
      12,    0,   84,    2, 0x08,   10 /* Private */,
      13,    0,   85,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject maingame::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSmaingameENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmaingameENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmaingameENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<maingame, std::true_type>,
        // method 'paintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>,
        // method 'exitApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'menuApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayDeathMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveSnake'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generateObstacle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateCountdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearPauseText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void maingame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<maingame *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< std::add_pointer_t<QPaintEvent*>>(_a[1]))); break;
        case 1: _t->exitApp(); break;
        case 2: _t->menuApp(); break;
        case 3: _t->displayDeathMessage(); break;
        case 4: _t->resetGame(); break;
        case 5: _t->moveSnake(); break;
        case 6: _t->generateObstacle(); break;
        case 7: _t->pauseGame(); break;
        case 8: _t->updateCountdown(); break;
        case 9: _t->clearPauseText(); break;
        default: ;
        }
    }
}

const QMetaObject *maingame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *maingame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmaingameENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int maingame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
