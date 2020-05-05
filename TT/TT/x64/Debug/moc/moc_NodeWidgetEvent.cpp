/****************************************************************************
** Meta object code from reading C++ file 'NodeWidgetEvent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NodeWidgetEvent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NodeWidgetEvent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NodeWidgetEvent_t {
    QByteArrayData data[11];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeWidgetEvent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeWidgetEvent_t qt_meta_stringdata_NodeWidgetEvent = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NodeWidgetEvent"
QT_MOC_LITERAL(1, 16, 10), // "sendWidget"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "state"
QT_MOC_LITERAL(4, 34, 8), // "QWidget*"
QT_MOC_LITERAL(5, 43, 6), // "widget"
QT_MOC_LITERAL(6, 50, 16), // "selectFirstPoint"
QT_MOC_LITERAL(7, 67, 17), // "selectSecondPoint"
QT_MOC_LITERAL(8, 85, 17), // "releaseMousePoint"
QT_MOC_LITERAL(9, 103, 14), // "sendMousePoint"
QT_MOC_LITERAL(10, 118, 5) // "point"

    },
    "NodeWidgetEvent\0sendWidget\0\0state\0"
    "QWidget*\0widget\0selectFirstPoint\0"
    "selectSecondPoint\0releaseMousePoint\0"
    "sendMousePoint\0point"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeWidgetEvent[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,
       7,    1,   47,    2, 0x06 /* Public */,
       8,    0,   50,    2, 0x06 /* Public */,
       9,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   10,

       0        // eod
};

void NodeWidgetEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NodeWidgetEvent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWidget((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 1: _t->selectFirstPoint((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->selectSecondPoint((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->releaseMousePoint(); break;
        case 4: _t->sendMousePoint((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NodeWidgetEvent::*)(bool , QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NodeWidgetEvent::sendWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NodeWidgetEvent::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NodeWidgetEvent::selectFirstPoint)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NodeWidgetEvent::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NodeWidgetEvent::selectSecondPoint)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NodeWidgetEvent::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NodeWidgetEvent::releaseMousePoint)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NodeWidgetEvent::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NodeWidgetEvent::sendMousePoint)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NodeWidgetEvent::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_NodeWidgetEvent.data,
    qt_meta_data_NodeWidgetEvent,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NodeWidgetEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NodeWidgetEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NodeWidgetEvent.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NodeWidgetEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void NodeWidgetEvent::sendWidget(bool _t1, QWidget * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NodeWidgetEvent::selectFirstPoint(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NodeWidgetEvent::selectSecondPoint(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NodeWidgetEvent::releaseMousePoint()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void NodeWidgetEvent::sendMousePoint(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
