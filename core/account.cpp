#include "account.h"
#include "core/transaction.h"
#include <QDateTime>

Account::Account(int id, DatabaseHandler *bdd, QObject *parent) :
    QObject{parent}, _bdd(bdd), _id(QString::number(id))
{
    //qDebug()<<"Create account : "<<toString();
}

QString Account::name(){
    QSqlQuery query;
    query.prepare("SELECT name FROM account WHERE id = :accountId");
    query.bindValue(":accountId", _id);
    query.exec();
    query.next();
    return query.value(0).toString();
}
QString Account::number(){
    QSqlQuery query;
    query.prepare("SELECT number FROM account WHERE id = :accountId");
    query.bindValue(":accountId", _id);
    query.exec();
    query.next();
    return query.value(0).toString();
}
QString Account::bank(){
    QSqlQuery query;
    query.prepare(
        "SELECT bank.name FROM account "
        "JOIN bank ON account.bank = bank.id "
        "WHERE account.id = :accountId"
    );
    query.bindValue(":accountId", _id);
    query.exec();
    query.next();
    //qDebug()<<"Account "<<_id<<" bank "<<query.value(0).toString();
    return query.value(0).toString();
}
bool Account::type(){
    QSqlQuery query;
    query.prepare("SELECT type FROM account WHERE id = :accountId");
    query.bindValue(":accountId", _id);
    query.exec();
    query.next();
    return query.value(0).toBool();
}
float Account::sold(){
    QSqlQuery query;
    query.prepare("SELECT SUM(amount) FROM moneytransaction WHERE account = :accountId");
    query.bindValue(":accountId", _id);
    query.exec();
    query.next();
    //qDebug()<<"OK - "<<_id<<" sold retreived "<<query.value(0).toFloat();
    return query.value(0).toFloat();
}

void Account::setName(QString name){
    if(name == Account::name()) return;

    QSqlQuery query;
    query.prepare("UPDATE account SET name = :newName WHERE id = :accountId");
    query.bindValue(":newName", name);
    query.bindValue(":accountId", _id);

    if (query.exec()) emit nameChanged();
}
void Account::setType(int type){
    if(type == Account::type()) return;

    QSqlQuery query;
    query.prepare("UPDATE account SET type = :accountType WHERE id = :accountId");
    query.bindValue(":accountType", type);
    query.bindValue(":accountId", _id);

    if(query.exec())emit typeChanged();
}
void Account::setNumber(QString number){
    if(number == Account::number()) return;

    QSqlQuery query;
    query.prepare("UPDATE account SET number = :newNumber WHERE id = :accountId");
    query.bindValue(":newNumber", number);
    query.bindValue(":accountId", _id);

    if(query.exec()) emit numberChanged();
}
void Account::setBank(QString bank){
    if(bank == Account::bank()) return;

    QSqlQuery query;
    query.prepare(
        "UPDATE account SET bank = bank.id FROM bank "
        "WHERE account.id = :accountId AND bank.name = :bankName"
    );
    query.bindValue(":accountId", _id);
    query.bindValue(":bankName", bank);

    if(query.exec()) emit bankChanged();
}


QString Account::toString(){
    return "Account id = "+_id;
}

void Account::addTransaction(QString amount, QString date, QString category, QString details){
    QString accountId = _id;
    QString categoryId= _bdd->getCategorieId(category);

    _bdd->insertTransaction(accountId,amount,date,categoryId,details);
    emit soldChanged();
    emit updateLastTransaction();
}


QVariantList Account::getLastTransactions(int nbr){
    QVariantList list;
    QSqlQuery query;

    query.prepare(
        "SELECT mt.date, mt.amount, c.name "
        "FROM moneytransaction mt "
        "JOIN category c ON mt.category = c.id "
        "WHERE mt.account = :accountId "
        "  AND mt.id IN (SELECT id FROM moneytransaction "
        "                WHERE account = :accountId "
        "                ORDER BY id DESC LIMIT :limit)");

    query.bindValue(":accountId", _id);
    query.bindValue(":limit", nbr);

    if (!query.exec()) return list;

    qDebug()<<"OK - Get last "<<nbr<<" transactions";

    while(query.next()){
        QString date = query.value("date").toString();
        QString amount = QString::number(query.value("amount").toFloat(),'f',2);
        QString category = query.value("name").toString();

        QVariant variant = QVariant::fromValue(new Transaction(date,amount,category,_id,""));

        list.append(variant);

        //qDebug()<<date<<" "<<amount<<" "<<category;
    }


    std::reverse(list.begin(), list.end());

    return list;
}

QVariantList Account::transactions(){
    QVariantList list;
    QSqlQuery query;

    query.prepare(
        "SELECT mt.date, mt.amount, c.name "
        "FROM moneytransaction mt "
        "JOIN category c ON mt.category = c.id "
        "WHERE mt.account = :accountId ");

    query.bindValue(":accountId", _id);

    if (!query.exec()) return list;

    qDebug()<<"OK - Get all transactions";

    while(query.next()){
        QString date = query.value("date").toString();
        QString amount = QString::number(query.value("amount").toFloat(),'f',2);
        QString category = query.value("name").toString();

        QVariant variant = QVariant::fromValue(new Transaction(date,amount,category,_id,""));

        list.append(variant);

        //qDebug()<<date<<" "<<amount<<" "<<category;
    }

    std::reverse(list.begin(), list.end());

    return list;
}


QVariantList Account::getMonthlySold(QString start, QString end, int type) {
    QVariantList list;

    if(type>2) return list;
    QString condition[] = {"1=1","amount >= 0","amount<=0"};

    QSqlQuery query;
    query.prepare(
        "SELECT "
        "    strftime('%Y-%m', date) AS month, "
        "    SUM(amount) AS monthly_sum "
        "FROM moneytransaction "
        "WHERE "
        "    (:typeCondition) AND "
        "    account = :account AND "
        "    date BETWEEN :start_date AND :end_date "
        "GROUP BY month, account;"
    );

    query.bindValue(":typeCondition", condition[type]);
    query.bindValue(":account", _id);
    query.bindValue(":start_date", start);
    query.bindValue(":end_date", end);

    if (!_bdd->exec(&query)){
        qDebug()<<"Fail to get monthly sold.";
        return list;
    }

    while (query.next()) {
        //qDebug() << query.value("month").toString() << " " << query.value("monthly_sum").toDouble();
        list.append(query.value("monthly_sum").toFloat());
    }
    return list;
}

QVariantList Account::getMonthlyPositiveSold(QString start, QString end){
    return getMonthlySold(start,end,true);
}
QVariantList Account::getMonthlyNegativeSold(QString start, QString end){
    return getMonthlySold(start,end,false);
}
