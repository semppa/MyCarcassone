/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../carcassonev2/View/gamewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameWindow_t {
    QByteArrayData data[23];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameWindow_t qt_meta_stringdata_GameWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameWindow"
QT_MOC_LITERAL(1, 11, 6), // "closed"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "updateChat"
QT_MOC_LITERAL(4, 30, 3), // "msg"
QT_MOC_LITERAL(5, 34, 15), // "changeTurnLabel"
QT_MOC_LITERAL(6, 50, 8), // "PlayerID"
QT_MOC_LITERAL(7, 59, 2), // "id"
QT_MOC_LITERAL(8, 62, 28), // "on_chatInputLE_returnPressed"
QT_MOC_LITERAL(9, 91, 9), // "placeTile"
QT_MOC_LITERAL(10, 101, 21), // "std::shared_ptr<Tile>"
QT_MOC_LITERAL(11, 123, 4), // "tile"
QT_MOC_LITERAL(12, 128, 14), // "tileToBePlaced"
QT_MOC_LITERAL(13, 143, 8), // "GameTile"
QT_MOC_LITERAL(14, 152, 11), // "placeFigure"
QT_MOC_LITERAL(15, 164, 23), // "std::shared_ptr<Figure>"
QT_MOC_LITERAL(16, 188, 6), // "figure"
QT_MOC_LITERAL(17, 195, 12), // "removeFigure"
QT_MOC_LITERAL(18, 208, 16), // "updateScoreBoard"
QT_MOC_LITERAL(19, 225, 7), // "endGame"
QT_MOC_LITERAL(20, 233, 14), // "rotateTileView"
QT_MOC_LITERAL(21, 248, 7), // "rotateN"
QT_MOC_LITERAL(22, 256, 21) // "on_endTurnBtn_clicked"

    },
    "GameWindow\0closed\0\0updateChat\0msg\0"
    "changeTurnLabel\0PlayerID\0id\0"
    "on_chatInputLE_returnPressed\0placeTile\0"
    "std::shared_ptr<Tile>\0tile\0tileToBePlaced\0"
    "GameTile\0placeFigure\0std::shared_ptr<Figure>\0"
    "figure\0removeFigure\0updateScoreBoard\0"
    "endGame\0rotateTileView\0rotateN\0"
    "on_endTurnBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x08 /* Private */,
       5,    1,   78,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      14,    1,   88,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,
      18,    0,   94,    2, 0x08 /* Private */,
      19,    0,   95,    2, 0x08 /* Private */,
      20,    1,   96,    2, 0x08 /* Private */,
      22,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   11,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,

       0        // eod
};

void GameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->updateChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->changeTurnLabel((*reinterpret_cast< PlayerID(*)>(_a[1]))); break;
        case 3: _t->on_chatInputLE_returnPressed(); break;
        case 4: _t->placeTile((*reinterpret_cast< std::shared_ptr<Tile>(*)>(_a[1]))); break;
        case 5: _t->tileToBePlaced((*reinterpret_cast< GameTile(*)>(_a[1]))); break;
        case 6: _t->placeFigure((*reinterpret_cast< std::shared_ptr<Figure>(*)>(_a[1]))); break;
        case 7: _t->removeFigure((*reinterpret_cast< std::shared_ptr<Figure>(*)>(_a[1]))); break;
        case 8: _t->updateScoreBoard(); break;
        case 9: _t->endGame(); break;
        case 10: _t->rotateTileView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_endTurnBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameWindow::closed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_GameWindow.data,
    qt_meta_data_GameWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void GameWindow::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
