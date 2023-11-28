#include "account.h"
#include "core/transaction.h"
#include <QDateTime>

Account::Account(QString name, float sold, QString number, DatabaseHandler *bdd, QObject *parent) :
    QObject{parent}, _bdd(bdd), _name(name), _sold(sold), _number(number)
{
    _id = QString::number(_bdd->account(_name));
}

void Account::setSold(float sold){
    if(sold == _sold) return;
    _sold = sold;
    emit soldChanged();
}

QString Account::toString(){
    return _name;
}

void Account::addTransaction(QString amount, QString date, QString category, QString details){
    QString accountId = QString::number(_bdd->account(_name));
    QString categoryId= QString::number(_bdd->category(category));

    _bdd->insertTransaction(accountId,amount,date,categoryId,details);
    setSold(_bdd->getSold(accountId));

    emit updateLastTransaction();
}

QVariantList Account::getMonthlyEvolution(QString start_date, QString end_date){

    QString txt =
        "SELECT date, amount FROM moneytransaction "
        "   WHERE account="+_id+" "
        "   AND category="+QString::number(_bdd->category("Bilan"))+" "
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

    qDebug()<<"get last "<<nbr<<" transactions";

    QString maxId = "SELECT MAX(id)-"+QString::number(nbr)+" FROM moneytransaction";

    QString txt = "SELECT date, amount, category FROM moneytransaction "
                  "WHERE account=0 AND id > ("+maxId+");";

    _bdd->queryExec(txt);

    while(query->next()){
        QString date = query->value("date").toString();
        QString amount = QString::number(query->value("amount").toFloat(),'f',2);
        QString category = _bdd->category(query->value("category").toInt());

        QVariant variant = QVariant::fromValue(new Transaction(date,amount,category,_name,""));

        list.append(variant);
    }

    std::reverse(list.begin(), list.end());

    return list;
}
