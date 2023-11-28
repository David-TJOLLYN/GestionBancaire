#include "databasewrapper.h"
#include "QDateTime"

DatabaseWrapper::DatabaseWrapper(QObject *parent) : QObject{parent},
  _wrapper(new DatabaseHandler())
{
    _query = _wrapper->getQuery();
}

void DatabaseWrapper::loadAccounts(){
    _query->exec("Select name, sold from account;");

    while(_query->next()){
        QString name = _query->value("name").toString();
        float sold   = _query->value("sold").toFloat();
        QString num  = "3892 9365 8792";

        _accounts.append(new Account(name, sold, num, _wrapper));
    }
}

QVariantList DatabaseWrapper::getAccounts() {
    QVariantList list;

    loadAccounts();
    foreach(auto account, _accounts){
        list.append(QVariant::fromValue(account));
    }

    return list;
}

QVariantList DatabaseWrapper::getCategories(){
    QVariantList list;

    _query->exec("SELECT name from category;");

    while(_query->next()){
        list.append(_query->value("name"));
    }

    return list;
}


float DatabaseWrapper::getTotalSold(){
    _query->exec("SELECT SUM(sold) from account;");
    _query->next();
    return _query->value(0).toFloat();
}
