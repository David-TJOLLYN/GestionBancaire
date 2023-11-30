#include "account.h"
#include "core/transaction.h"
#include <QDateTime>

Account::Account(int id, QString name, float sold, QString number, DatabaseHandler *bdd, QObject *parent) :
    QObject{parent}, _bdd(bdd),_name(name), _id(QString::number(id)), _sold(sold), _number(number)
{
    qDebug()<<"Create account : "<<toString();
}

void Account::setSold(float sold){
    if(sold == _sold) return;
    _sold = sold;
    emit soldChanged();
}

QString Account::toString(){
    return _id+" "+_name+" "+QString::number(_sold,'f',2);
}

void Account::addTransaction(QString amount, QString date, QString category, QString details){
    QString accountId = _id;
    QString categoryId= _bdd->getCategorieId(category);

    _bdd->insertTransaction(accountId,amount,date,categoryId,details);
    setSold(_bdd->getSold(accountId));

    emit updateLastTransaction();
}

QVariantList Account::getMonthlyEvolution(QString start_date, QString end_date){

    QString txt =
        "SELECT date, amount FROM moneytransaction "
        "   WHERE account="+_id+" "
        "   AND category="+_bdd->getCategorieId("Bilan")+" "
        "   AND date BETWEEN '"+start_date+"' AND '"+end_date+"';";

    _bdd->queryExec(txt);
    QSqlQuery *query = _bdd->getQuery();

    QVariantList list;
    while(query->next()){
        list.append(query->value("amount"));
    }
    return list;
}


QVariantList Account::getLastTransactions(int nbr){
    QVariantList list;
    QSqlQuery *query = _bdd->getQuery();

    QString ids = "SELECT id FROM moneytransaction "
                  "WHERE account="+_id+" ORDER BY id DESC "
                  "LIMIT "+QString::number(nbr);

    QString txt = "SELECT moneytransaction.date, moneytransaction.amount, category.name "
                  "FROM moneytransaction "
                  "JOIN category ON moneytransaction.category = category.id "
                  "WHERE moneytransaction.id IN ("+ids+");";

    if(!_bdd->queryExec(txt)) return list;
    qDebug()<<"OK - Get last "<<nbr<<" transactions";

    while(query->next()){
        QString date = query->value("date").toString();
        QString amount = QString::number(query->value("amount").toFloat(),'f',2);
        QString category = query->value("name").toString();

        QVariant variant = QVariant::fromValue(new Transaction(date,amount,category,_name,""));

        list.append(variant);
    }


    std::reverse(list.begin(), list.end());

    return list;
}
