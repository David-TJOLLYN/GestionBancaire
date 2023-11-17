#include "account.h"
#include <QDateTime>

Account::Account(QString name, float sold, QString number, DatabaseHandler *bdd, QObject *parent) :
    QObject{parent}, _bdd(bdd), _name(name), _sold(sold), _number(number)
{

}

void Account::setSold(float sold){
    if(sold == _sold) return;
    _sold = sold;
    emit soldChanged();
}

QString Account::toString(){
    return _name;
}

void Account::addTransaction(bool type, QString amount, QString category, QString details){
    _bdd->insertMoneyTransaction(_name,amount.toFloat(),type,category,QDateTime::currentDateTime().date(),details);
    setSold(_bdd->getSoldString(_name).toFloat());
}

QVariantList Account::getMonthlyEvolution(QString start_date, QString end_date){

    QString txt =
        "SELECT date, amount FROM moneytransaction "
        "   WHERE account="+QString::number(_bdd->account(_name))+" "
        "   AND category="+QString::number(_bdd->category("Bilan"))+" "
        "   AND date BETWEEN '"+start_date+"' AND '"+end_date+"';";

    qDebug()<<_bdd->queryExec(txt);
    QSqlQuery *query = _bdd->getQuery();

    QVariantList list;
    while(query->next()){
        list.append(query->value("amount"));
    }
    return list;
}
