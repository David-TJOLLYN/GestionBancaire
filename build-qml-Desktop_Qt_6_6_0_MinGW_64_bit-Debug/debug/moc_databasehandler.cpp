/****************************************************************************
** Meta object code from reading C++ file 'databasehandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../core/databasehandler.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
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
struct qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS = QtMocHelpers::stringData(
    "DatabaseHandler",
    "accountsChanged",
    "",
    "categoriesChanged",
    "banksChanged",
    "addAccount",
    "name",
    "number",
    "bank",
    "type",
    "addCategory",
    "addBank",
    "account",
    "id",
    "accounts",
    "categories",
    "banks"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[16];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[13];
    char stringdata5[11];
    char stringdata6[5];
    char stringdata7[7];
    char stringdata8[5];
    char stringdata9[5];
    char stringdata10[12];
    char stringdata11[8];
    char stringdata12[8];
    char stringdata13[3];
    char stringdata14[9];
    char stringdata15[11];
    char stringdata16[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS_t qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "DatabaseHandler"
        QT_MOC_LITERAL(16, 15),  // "accountsChanged"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 17),  // "categoriesChanged"
        QT_MOC_LITERAL(51, 12),  // "banksChanged"
        QT_MOC_LITERAL(64, 10),  // "addAccount"
        QT_MOC_LITERAL(75, 4),  // "name"
        QT_MOC_LITERAL(80, 6),  // "number"
        QT_MOC_LITERAL(87, 4),  // "bank"
        QT_MOC_LITERAL(92, 4),  // "type"
        QT_MOC_LITERAL(97, 11),  // "addCategory"
        QT_MOC_LITERAL(109, 7),  // "addBank"
        QT_MOC_LITERAL(117, 7),  // "account"
        QT_MOC_LITERAL(125, 2),  // "id"
        QT_MOC_LITERAL(128, 8),  // "accounts"
        QT_MOC_LITERAL(137, 10),  // "categories"
        QT_MOC_LITERAL(148, 5)   // "banks"
    },
    "DatabaseHandler",
    "accountsChanged",
    "",
    "categoriesChanged",
    "banksChanged",
    "addAccount",
    "name",
    "number",
    "bank",
    "type",
    "addCategory",
    "addBank",
    "account",
    "id",
    "accounts",
    "categories",
    "banks"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDatabaseHandlerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       3,   77, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    4 /* Public */,
       3,    0,   57,    2, 0x06,    5 /* Public */,
       4,    0,   58,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    4,   59,    2, 0x0a,    7 /* Public */,
      10,    1,   68,    2, 0x0a,   12 /* Public */,
      11,    1,   71,    2, 0x0a,   14 /* Public */,
      12,    1,   74,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QString,    6,
    QMetaType::QVariant, QMetaType::Int,   13,

 // properties: name, type, flags
      14, QMetaType::QVariantList, 0x00015801, uint(0), 0,
      15, QMetaType::QVariantList, 0x00015801, uint(1), 0,
      16, QMetaType::QVariantList, 0x00015801, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject DatabaseHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDatabaseHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS_t,
        // property 'accounts'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'categories'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'banks'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DatabaseHandler, std::true_type>,
        // method 'accountsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'categoriesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'banksChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addAccount'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addCategory'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addBank'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'account'
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void DatabaseHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatabaseHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->accountsChanged(); break;
        case 1: _t->categoriesChanged(); break;
        case 2: _t->banksChanged(); break;
        case 3: { bool _r = _t->addAccount((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->addCategory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->addBank((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariant _r = _t->account((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatabaseHandler::*)();
            if (_t _q_method = &DatabaseHandler::accountsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DatabaseHandler::*)();
            if (_t _q_method = &DatabaseHandler::categoriesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DatabaseHandler::*)();
            if (_t _q_method = &DatabaseHandler::banksChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DatabaseHandler *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->accounts(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->categories(); break;
        case 2: *reinterpret_cast< QVariantList*>(_v) = _t->banks(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *DatabaseHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDatabaseHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DatabaseHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DatabaseHandler::accountsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DatabaseHandler::categoriesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DatabaseHandler::banksChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
