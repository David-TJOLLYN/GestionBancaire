#include "databasewrapper.h"
#include "QDateTime"

DatabaseWrapper::DatabaseWrapper(QObject *parent) : QObject{parent},
  _wrapper(new DatabaseHandler())
{
}

void DatabaseWrapper::loadAccounts(){
    _wrapper->queryExec("Select name, sold from account;");
    QSqlQuery *query = _wrapper->getQuery();

    while(query->next()){
        QString name = query->value("name").toString();
        float sold = query->value("sold").toFloat();
        QString num = "3892 9365 8792";

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

    _wrapper->queryExec("SELECT name from category;");
    QSqlQuery *query = _wrapper->getQuery();
    while(query->next()){
        list.append(query->value("name"));
    }
    return list;
}

void DatabaseWrapper::insertTransaction(bool type, QString account, QString amount, QString category, QString details){
    _wrapper->insertMoneyTransaction(account,amount.toFloat(),type,category,QDateTime::currentDateTime().date(),details);
}
