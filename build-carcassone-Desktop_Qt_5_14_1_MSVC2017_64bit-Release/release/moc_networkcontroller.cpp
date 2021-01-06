/****************************************************************************
** Meta object code from reading C++ file 'networkcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../carcassonev2/Controller/networkcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetWorkController_t {
    QByteArrayData data[27];
    char stringdata0[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetWorkController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetWorkController_t qt_meta_stringdata_NetWorkController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "NetWorkController"
QT_MOC_LITERAL(1, 18, 8), // "sendData"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "data"
QT_MOC_LITERAL(4, 33, 10), // "newMessage"
QT_MOC_LITERAL(5, 44, 3), // "msg"
QT_MOC_LITERAL(6, 48, 9), // "newPlayer"
QT_MOC_LITERAL(7, 58, 4), // "nick"
QT_MOC_LITERAL(8, 63, 18), // "playerDisconnected"
QT_MOC_LITERAL(9, 82, 17), // "closeServerWindow"
QT_MOC_LITERAL(10, 100, 14), // "openGameWindow"
QT_MOC_LITERAL(11, 115, 17), // "changeInTurnLabel"
QT_MOC_LITERAL(12, 133, 8), // "PlayerID"
QT_MOC_LITERAL(13, 142, 2), // "id"
QT_MOC_LITERAL(14, 145, 9), // "placeTile"
QT_MOC_LITERAL(15, 155, 21), // "std::shared_ptr<Tile>"
QT_MOC_LITERAL(16, 177, 4), // "tile"
QT_MOC_LITERAL(17, 182, 11), // "placeFigure"
QT_MOC_LITERAL(18, 194, 23), // "std::shared_ptr<Figure>"
QT_MOC_LITERAL(19, 218, 6), // "figure"
QT_MOC_LITERAL(20, 225, 14), // "tileToBePlaced"
QT_MOC_LITERAL(21, 240, 8), // "GameTile"
QT_MOC_LITERAL(22, 249, 12), // "removeFigure"
QT_MOC_LITERAL(23, 262, 3), // "fig"
QT_MOC_LITERAL(24, 266, 16), // "updateScoreBoard"
QT_MOC_LITERAL(25, 283, 7), // "endGame"
QT_MOC_LITERAL(26, 291, 10) // "disconnect"

    },
    "NetWorkController\0sendData\0\0data\0"
    "newMessage\0msg\0newPlayer\0nick\0"
    "playerDisconnected\0closeServerWindow\0"
    "openGameWindow\0changeInTurnLabel\0"
    "PlayerID\0id\0placeTile\0std::shared_ptr<Tile>\0"
    "tile\0placeFigure\0std::shared_ptr<Figure>\0"
    "figure\0tileToBePlaced\0GameTile\0"
    "removeFigure\0fig\0updateScoreBoard\0"
    "endGame\0disconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetWorkController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       8,    1,   93,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    0,   97,    2, 0x06 /* Public */,
      11,    1,   98,    2, 0x06 /* Public */,
      14,    1,  101,    2, 0x06 /* Public */,
      17,    1,  104,    2, 0x06 /* Public */,
      20,    1,  107,    2, 0x06 /* Public */,
      22,    1,  110,    2, 0x06 /* Public */,
      24,    0,  113,    2, 0x06 /* Public */,
      25,    0,  114,    2, 0x06 /* Public */,
      26,    0,  115,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   16,
    QMetaType::Void, 0x80000000 | 18,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NetWorkController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetWorkController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->newMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->newPlayer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->playerDisconnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->closeServerWindow(); break;
        case 5: _t->openGameWindow(); break;
        case 6: _t->changeInTurnLabel((*reinterpret_cast< PlayerID(*)>(_a[1]))); break;
        case 7: _t->placeTile((*reinterpret_cast< std::shared_ptr<Tile>(*)>(_a[1]))); break;
        case 8: _t->placeFigure((*reinterpret_cast< std::shared_ptr<Figure>(*)>(_a[1]))); break;
        case 9: _t->tileToBePlaced((*reinterpret_cast< GameTile(*)>(_a[1]))); break;
        case 10: _t->removeFigure((*reinterpret_cast< std::shared_ptr<Figure>(*)>(_a[1]))); break;
        case 11: _t->updateScoreBoard(); break;
        case 12: _t->endGame(); break;
        case 13: _t->disconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetWorkController::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::newMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::newPlayer)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::playerDisconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::closeServerWindow)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::openGameWindow)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(PlayerID );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::changeInTurnLabel)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(std::shared_ptr<Tile> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::placeTile)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(std::shared_ptr<Figure> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::placeFigure)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(GameTile );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::tileToBePlaced)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)(std::shared_ptr<Figure> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::removeFigure)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::updateScoreBoard)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::endGame)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (NetWorkController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetWorkController::disconnect)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetWorkController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NetWorkController.data,
    qt_meta_data_NetWorkController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetWorkController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetWorkController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetWorkController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetWorkController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void NetWorkController::sendData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetWorkController::newMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetWorkController::newPlayer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetWorkController::playerDisconnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetWorkController::closeServerWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void NetWorkController::openGameWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void NetWorkController::changeInTurnLabel(PlayerID _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void NetWorkController::placeTile(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void NetWorkController::placeFigure(std::shared_ptr<Figure> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void NetWorkController::tileToBePlaced(GameTile _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void NetWorkController::removeFigure(std::shared_ptr<Figure> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void NetWorkController::updateScoreBoard()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void NetWorkController::endGame()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void NetWorkController::disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
