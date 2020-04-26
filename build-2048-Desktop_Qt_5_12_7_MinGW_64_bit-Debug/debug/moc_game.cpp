/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../2048/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_game_t {
    QByteArrayData data[17];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_game_t qt_meta_stringdata_game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "game"
QT_MOC_LITERAL(1, 5, 11), // "gameChanged"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 10), // "nouvPartie"
QT_MOC_LITERAL(4, 29, 9), // "precedent"
QT_MOC_LITERAL(5, 39, 7), // "suivant"
QT_MOC_LITERAL(6, 47, 11), // "deplacement"
QT_MOC_LITERAL(7, 59, 5), // "dir_i"
QT_MOC_LITERAL(8, 65, 5), // "dir_j"
QT_MOC_LITERAL(9, 71, 16), // "enregistrePartie"
QT_MOC_LITERAL(10, 88, 3), // "nom"
QT_MOC_LITERAL(11, 92, 5), // "force"
QT_MOC_LITERAL(12, 98, 12), // "chargePartie"
QT_MOC_LITERAL(13, 111, 12), // "deletePartie"
QT_MOC_LITERAL(14, 124, 6), // "valQML"
QT_MOC_LITERAL(15, 131, 6), // "colQML"
QT_MOC_LITERAL(16, 138, 11) // "templateQML"

    },
    "game\0gameChanged\0\0nouvPartie\0precedent\0"
    "suivant\0deplacement\0dir_i\0dir_j\0"
    "enregistrePartie\0nom\0force\0chargePartie\0"
    "deletePartie\0valQML\0colQML\0templateQML"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_game[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       3,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x02 /* Public */,
       4,    0,   56,    2, 0x02 /* Public */,
       5,    0,   57,    2, 0x02 /* Public */,
       6,    2,   58,    2, 0x02 /* Public */,
       9,    2,   63,    2, 0x02 /* Public */,
      12,    1,   68,    2, 0x02 /* Public */,
      13,    1,   71,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

 // properties: name, type, flags
      14, QMetaType::QStringList, 0x00495001,
      15, QMetaType::QStringList, 0x00495001,
      16, QMetaType::QStringList, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,

       0        // eod
};

void game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameChanged(); break;
        case 1: _t->nouvPartie(); break;
        case 2: _t->precedent(); break;
        case 3: _t->suivant(); break;
        case 4: _t->deplacement((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: { int _r = _t->enregistrePartie((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->chargePartie((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->deletePartie((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&game::gameChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<game *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->readVal(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->readCol(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->readTemplate(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject game::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_game.data,
    qt_meta_data_game,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_game.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void game::gameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
