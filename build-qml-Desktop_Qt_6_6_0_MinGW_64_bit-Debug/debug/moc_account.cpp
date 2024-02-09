/****************************************************************************
** Meta object code from reading C++ file 'account.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../core/account.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'account.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAccountENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAccountENDCLASS = QtMocHelpers::stringData(
    "Account",
    "soldChanged",
    "",
    "nameChanged",
    "typeChanged",
    "numberChanged",
    "bankChanged",
    "transactionsChanged",
    "addTransaction",
    "amount",
    "date",
    "category",
    "details",
    "deleteTransaction",
    "id",
    "getLastTransactions",
    "nbr",
    "getMonthlySold",
    "start",
    "end",
    "type",
    "getMonthlyPositiveSold",
    "getMonthlyNegativeSold",
    "getSoldGroupByCategories",
    "toString",
    "name",
    "bank",
    "sold",
    "number",
    "transactions"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAccountENDCLASS_t {
    uint offsetsAndSizes[60];
    char stringdata0[8];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[12];
    char stringdata5[14];
    char stringdata6[12];
    char stringdata7[20];
    char stringdata8[15];
    char stringdata9[7];
    char stringdata10[5];
    char stringdata11[9];
    char stringdata12[8];
    char stringdata13[18];
    char stringdata14[3];
    char stringdata15[20];
    char stringdata16[4];
    char stringdata17[15];
    char stringdata18[6];
    char stringdata19[4];
    char stringdata20[5];
    char stringdata21[23];
    char stringdata22[23];
    char stringdata23[25];
    char stringdata24[9];
    char stringdata25[5];
    char stringdata26[5];
    char stringdata27[5];
    char stringdata28[7];
    char stringdata29[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAccountENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAccountENDCLASS_t qt_meta_stringdata_CLASSAccountENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "Account"
        QT_MOC_LITERAL(8, 11),  // "soldChanged"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 11),  // "nameChanged"
        QT_MOC_LITERAL(33, 11),  // "typeChanged"
        QT_MOC_LITERAL(45, 13),  // "numberChanged"
        QT_MOC_LITERAL(59, 11),  // "bankChanged"
        QT_MOC_LITERAL(71, 19),  // "transactionsChanged"
        QT_MOC_LITERAL(91, 14),  // "addTransaction"
        QT_MOC_LITERAL(106, 6),  // "amount"
        QT_MOC_LITERAL(113, 4),  // "date"
        QT_MOC_LITERAL(118, 8),  // "category"
        QT_MOC_LITERAL(127, 7),  // "details"
        QT_MOC_LITERAL(135, 17),  // "deleteTransaction"
        QT_MOC_LITERAL(153, 2),  // "id"
        QT_MOC_LITERAL(156, 19),  // "getLastTransactions"
        QT_MOC_LITERAL(176, 3),  // "nbr"
        QT_MOC_LITERAL(180, 14),  // "getMonthlySold"
        QT_MOC_LITERAL(195, 5),  // "start"
        QT_MOC_LITERAL(201, 3),  // "end"
        QT_MOC_LITERAL(205, 4),  // "type"
        QT_MOC_LITERAL(210, 22),  // "getMonthlyPositiveSold"
        QT_MOC_LITERAL(233, 22),  // "getMonthlyNegativeSold"
        QT_MOC_LITERAL(256, 24),  // "getSoldGroupByCategories"
        QT_MOC_LITERAL(281, 8),  // "toString"
        QT_MOC_LITERAL(290, 4),  // "name"
        QT_MOC_LITERAL(295, 4),  // "bank"
        QT_MOC_LITERAL(300, 4),  // "sold"
        QT_MOC_LITERAL(305, 6),  // "number"
        QT_MOC_LITERAL(312, 12)   // "transactions"
    },
    "Account",
    "soldChanged",
    "",
    "nameChanged",
    "typeChanged",
    "numberChanged",
    "bankChanged",
    "transactionsChanged",
    "addTransaction",
    "amount",
    "date",
    "category",
    "details",
    "deleteTransaction",
    "id",
    "getLastTransactions",
    "nbr",
    "getMonthlySold",
    "start",
    "end",
    "type",
    "getMonthlyPositiveSold",
    "getMonthlyNegativeSold",
    "getSoldGroupByCategories",
    "toString",
    "name",
    "bank",
    "sold",
    "number",
    "transactions"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAccountENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       7,  166, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,    8 /* Public */,
       3,    0,  111,    2, 0x06,    9 /* Public */,
       4,    0,  112,    2, 0x06,   10 /* Public */,
       5,    0,  113,    2, 0x06,   11 /* Public */,
       6,    0,  114,    2, 0x06,   12 /* Public */,
       7,    0,  115,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    4,  116,    2, 0x0a,   14 /* Public */,
       8,    3,  125,    2, 0x2a,   19 /* Public | MethodCloned */,
      13,    1,  132,    2, 0x0a,   23 /* Public */,
      15,    1,  135,    2, 0x0a,   25 /* Public */,
      17,    3,  138,    2, 0x0a,   27 /* Public */,
      17,    2,  145,    2, 0x2a,   31 /* Public | MethodCloned */,
      21,    2,  150,    2, 0x0a,   34 /* Public */,
      22,    2,  155,    2, 0x0a,   37 /* Public */,
      23,    2,  160,    2, 0x0a,   40 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      24,    0,  165,    2, 0x02,   43 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::QVariantList, QMetaType::Int,   16,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QString, QMetaType::Int,   18,   19,   20,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::QVariantMap, QMetaType::QString, QMetaType::Int,   10,   20,

 // methods: parameters
    QMetaType::QString,

 // properties: name, type, flags
      14, QMetaType::Int, 0x00015401, uint(-1), 0,
      25, QMetaType::QString, 0x00015903, uint(1), 0,
      26, QMetaType::QString, 0x00015903, uint(4), 0,
      27, QMetaType::Float, 0x00015801, uint(0), 0,
      20, QMetaType::Int, 0x00015903, uint(2), 0,
      28, QMetaType::QString, 0x00015903, uint(3), 0,
      29, QMetaType::QVariantList, 0x00015801, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Account::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSAccountENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAccountENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAccountENDCLASS_t,
        // property 'id'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'name'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'bank'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'sold'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'type'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'number'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'transactions'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Account, std::true_type>,
        // method 'soldChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'typeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'numberChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bankChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'transactionsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTransaction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addTransaction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'deleteTransaction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getLastTransactions'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getMonthlySold'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getMonthlySold'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getMonthlyPositiveSold'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getMonthlyNegativeSold'
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getSoldGroupByCategories'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'toString'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void Account::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Account *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->soldChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->typeChanged(); break;
        case 3: _t->numberChanged(); break;
        case 4: _t->bankChanged(); break;
        case 5: _t->transactionsChanged(); break;
        case 6: _t->addTransaction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 7: _t->addTransaction((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 8: _t->deleteTransaction((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: { QVariantList _r = _t->getLastTransactions((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 10: { QVariantList _r = _t->getMonthlySold((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 11: { QVariantList _r = _t->getMonthlySold((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 12: { QVariantList _r = _t->getMonthlyPositiveSold((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 13: { QVariantList _r = _t->getMonthlyNegativeSold((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 14: { QVariantMap _r = _t->getSoldGroupByCategories((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->toString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Account::*)();
            if (_t _q_method = &Account::soldChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Account::*)();
            if (_t _q_method = &Account::nameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Account::*)();
            if (_t _q_method = &Account::typeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Account::*)();
            if (_t _q_method = &Account::numberChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Account::*)();
            if (_t _q_method = &Account::bankChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Account::*)();
            if (_t _q_method = &Account::transactionsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Account *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->bank(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->sold(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->type(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->number(); break;
        case 6: *reinterpret_cast< QVariantList*>(_v) = _t->transactions(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Account *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setBank(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setType(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setNumber(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Account::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Account::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAccountENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Account::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Account::soldChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Account::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Account::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Account::numberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Account::bankChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Account::transactionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
