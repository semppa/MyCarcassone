/****************************************************************************
** Meta object code from reading C++ file 'serverwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../carcassonev2/View/serverwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerWindow_t {
    QByteArrayData data[13];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerWindow_t qt_meta_stringdata_ServerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerWindow"
QT_MOC_LITERAL(1, 13, 14), // "swWindowClosed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 22), // "on_closeServer_clicked"
QT_MOC_LITERAL(4, 52, 27), // "on_chatSendLE_returnPressed"
QT_MOC_LITERAL(5, 80, 10), // "updateChat"
QT_MOC_LITERAL(6, 91, 3), // "msg"
QT_MOC_LITERAL(7, 95, 12), // "addNewPlayer"
QT_MOC_LITERAL(8, 108, 6), // "player"
QT_MOC_LITERAL(9, 115, 12), // "removePlayer"
QT_MOC_LITERAL(10, 128, 17), // "closeServerWindow"
QT_MOC_LITERAL(11, 146, 23), // "on_StartGameBtn_clicked"
QT_MOC_LITERAL(12, 170, 14) // "openGameWindow"

    },
    "ServerWindow\0swWindowClosed\0\0"
    "on_closeServer_clicked\0"
    "on_chatSendLE_returnPressed\0updateChat\0"
    "msg\0addNewPlayer\0player\0removePlayer\0"
    "closeServerWindow\0on_StartGameBtn_clicked\0"
    "openGameWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ServerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->swWindowClosed(); break;
        case 1: _t->on_closeServer_clicked(); break;
        case 2: _t->on_chatSendLE_returnPressed(); break;
        case 3: _t->updateChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->addNewPlayer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->removePlayer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->closeServerWindow(); break;
        case 7: _t->on_StartGameBtn_clicked(); break;
        case 8: _t->openGameWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerWindow::swWindowClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ServerWindow.data,
    qt_meta_data_ServerWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ServerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ServerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ServerWindow::swWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
