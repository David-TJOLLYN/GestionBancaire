#include "transaction.h"

Transaction::Transaction(int id, QString date, QString amount, QString category, QString accountId, QString details, QObject *parent)
    : QObject{parent}, _id(id), _date(date), _category(category), _account(accountId), _amount(amount), _details(details)
{

}

QString Transaction::toString(){
    return _date+" "+_amount+" "+_category;
}
