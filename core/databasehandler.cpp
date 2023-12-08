#include "databasehandler.h"
#include "account.h"
#include <QDebug>
#include <QDate>
#include <QSqlError>
#include <QSqlRecord>

QString databaseName = "gestion_bancaire.sqlite";
QString userName = "root";
QString userPassword = "MySQL";
QString databaseDriver = "QSQLITE";

DatabaseHandler::DatabaseHandler(bool *status){
    bool state = true;
    if(state) state &= openDatabase();
    //if(state) state &= createGestionBancaire();
    if(state) state &= loadAccounts();
    *status = state;
}

bool DatabaseHandler::openDatabase(){

    _bdd = QSqlDatabase::addDatabase(databaseDriver);

    _bdd.setHostName("localhost");
    _bdd.setDatabaseName(databaseName);
    _bdd.setUserName(userName);
    _bdd.setPassword(userPassword);

    if(!_bdd.open()){
        qDebug() << "Error - BDD not opened";
        return false;
    }

    qDebug()<<"OK - Database opened";
    return true;
}
bool DatabaseHandler::createGestionBancaire(){
    return createTables() && insertDefaultValues();
}

bool DatabaseHandler::createAccountTable(){
    QSqlQuery query;
    query.prepare(
        "CREATE TABLE account ("
        "   id      INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "   name    CHAR(50) NOT NULL UNIQUE, "
        "   number  CHAR(16) NOT NULL, "
        "   bank    INTEGER NOT NULL, "
        "   type    INTEGER NOT NULL, "
        "   FOREIGN KEY (bank) REFERENCES bank(id) "
        ")"
    );

    if(exec(&query)) return true;

    qDebug()<<"Fail to create account table.";
    return false;
}
bool DatabaseHandler::createCategoryTable(){
    QSqlQuery query;
    query.prepare(
        "CREATE TABLE category ("
        "   id      INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "   name    CHAR(50) NOT NULL UNIQUE"
        ")"
    );

    if(exec(&query)) return true;

    qDebug()<<"Fail to create category table.";
    return false;
}
bool DatabaseHandler::createTransactionTable(){
    QSqlQuery query;
    query.prepare(
        "CREATE TABLE moneytransaction ("
        "    id        INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "    amount    REAL NOT NULL, "
        "    date      DATE NOT NULL, "
        "    account   INTEGER NOT NULL, "
        "    category  INTEGER NOT NULL, "
        "    FOREIGN KEY (account) REFERENCES account(id), "
        "    FOREIGN KEY (category) REFERENCES category(id) "
        ");"
    );

    if(exec(&query)) return true;

    qDebug()<<"Fail to create transaction table.";
    return false;
}
bool DatabaseHandler::createBankTables(){
    QSqlQuery query;
    query.prepare(
        "CREATE TABLE bank ("
        "   id      INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "   name    CHAR(50) NOT NULL UNIQUE"
        ")"
    );

    if(exec(&query)) return true;

    qDebug()<<"Fail to create bank table.";
    return false;
}
bool DatabaseHandler::createTables(){
    bool status = true;

    status &= createAccountTable();
    status &= createCategoryTable();
    status &= createTransactionTable();
    status &= createBankTables();

    if(status) qDebug()<<"OK - Tables added successfully.";

    return status;
}

bool DatabaseHandler::insertDefaultAccounts()  {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO account (name, number, bank, type) "
        "VALUES "
            "('Compte courant','258963247456',5,0),"
            "('Livret Bleu','147858742369',5,1),"
            "('Livret Jeune','357852198652',5,1);"
    );

    if(exec(&query)) return true;

    qDebug()<<"Fail to insert accounts.";
    return false;
}
bool DatabaseHandler::insertDefaultCategories() {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO category (name) "
        "VALUES "

            "('Job'),"
            "('Food'),"
            "('Bar'),"
            "('Restorant'),"
            "('Technology'),"
            "('Numerical'),"
            "('Life'),"
            "('Sport'),"
            "('Health'),"
            "('Transport'),"
            "('Bike'),"
            "('Car'),"
            "('Else'),"
            "('Internal'),"
            "('Child support'),"
            "('Bank charge'),"
            "('Hobby'),"
            "('Allocation')"
    );
    if(exec(&query)) return true;

    qDebug()<<"Fail to insert categories.";
    return false;
}
bool DatabaseHandler::insertDefaultTransactions(){
    QSqlQuery query;
    query.prepare(
        "INSERT INTO moneytransaction (date, account, amount, category)"
        "VALUES"

        "   ('2019-05-01', 1, -92.73, 2),"
        "   ('2019-05-01', 1, -60.55, 9),"
        "   ('2019-05-01', 1, -15.99, 8),"
        "   ('2019-05-01', 1, -37.99, 17),"
        "   ('2019-05-01', 1, -14.99, 7),"
        "   ('2019-05-01', 1, -3.35, 16),"
        "   ('2019-05-01', 1, +3.35, 16),"
        "   ('2019-05-01', 1, +182.00,15),"

        "   ('2019-06-01', 1, -95.00, 2),"
        "   ('2019-06-01', 1, -9.90, 17),"
        "   ('2019-06-01', 1, -5.50, 9),"
        "   ('2019-06-01', 1, -3.35, 16),"
        "   ('2019-06-01', 1, +225.00, 15),"
        "   ('2019-06-01', 1, +3.35, 16),"

        "   ('2019-07-01', 1, +310.00, 15),"
        "   ('2019-07-01', 1, +3.35, 16),"
        "   ('2019-07-01', 1, -239.09, 2),"
        "   ('2019-07-01', 1, -218.40, 7),"
        "   ('2019-07-01', 1, -66.80, 10),"
        "   ('2019-07-01', 1, -87.98, 5),"
        "   ('2019-07-01', 1, -36.30, 17),"
        "   ('2019-07-01', 1, -3.35, 16),"

        "   ('2019-08-01', 1, -105.20, 2),"
        "   ('2019-08-01', 1, -52.00, 8),"
        "   ('2019-08-01', 1, -12.50, 4),"
        "   ('2019-08-01', 1, -26.79, 6),"
        "   ('2019-08-01', 1, -4.35, 16),"
        "   ('2019-08-01', 1, -25.00, 10),"
        "   ('2019-08-01', 1, -19.60, 12),"
        "   ('2019-08-01', 1, +269.00, 15),"
        "   ('2019-08-01', 1, +3.35, 16),"

        "   ('2019-09-01', 1, +242.00, 15),"
        "   ('2019-09-01', 1, -148.92, 2),"
        "   ('2019-09-01', 1, -101.37, 7),"
        "   ('2019-09-01', 1, -14.99, 5),"
        "   ('2019-09-01', 1, -3.35, 16),"

        "   ('2019-10-01', 1, -236.55, 2),"
        "   ('2019-10-01', 1, -34.00, 9),"
        "   ('2019-10-01', 1, -18.40, 7),"
        "   ('2019-10-01', 1, -3.35, 16),"
        "   ('2019-10-01', 1, +292.00, 15),"

        "   ('2019-11-01', 1, +99.15, 15),"
        "   ('2019-11-01', 1, -76.79, 2),"
        "   ('2019-11-01', 1, -18.99, 17),"
        "   ('2019-11-01', 1, -3.35, 16),"

        "   ('2019-12-01', 1, -185.37, 9),"
        "   ('2019-12-01', 1, -126.02, 2),"
        "   ('2019-12-01', 1, -9.00, 10),"
        "   ('2019-12-01', 1, -3.35, 16),"
        "   ('2019-12-01', 1, +266.00, 15),"

        "   ('2020-01-01', 1, +176.00, 15),"
        "   ('2020-01-01', 1, -162.67, 2),"
        "   ('2020-01-01', 1, -6.5, 9),"
        "   ('2020-01-01', 1, -3.35, 16),"

        "   ('2020-02-01', 1, -168.56, 2),"
        "   ('2020-02-01', 1, -13.99, 8),"
        "   ('2020-02-01', 1, -87.40, 5),"
        "   ('2020-02-01', 1, -45.43, 6),"
        "   ('2020-02-01', 1, -55.67, 7),"
        "   ('2020-02-01', 1, -4.82, 16),"
        "   ('2020-02-01', 1, +402.00, 15),"

        "   ('2020-03-01', 1, +276.00, 15),"
        "   ('2020-03-01', 1, -242.19, 2),"
        "   ('2020-03-01', 1, -14.40, 4),"
        "   ('2020-03-01', 1, -54.18, 6),"
        "   ('2020-03-01', 1, -4.81, 16),"

        "   ('2020-04-01', 1, -212.49, 2),"
        "   ('2020-04-01', 1, -54.31, 6),"
        "   ('2020-04-01', 1, -4.81, 16),"
        "   ('2020-04-01', 1, +237.00, 15),"

        "   ('2020-05-01', 1, +165.00, 15),"
        "   ('2020-05-01', 1, +45.43, 6),"
        "   ('2020-05-01', 1, +1.47, 16),"
        "   ('2020-05-01', 1, -79.13, 2),"
        "   ('2020-05-01', 1, -58.91, 6),"
        "   ('2020-05-01', 1, -6.00, 4),"
        "   ('2020-05-01', 1, -2.82, 7),"
        "   ('2020-05-01', 1, -4.03, 16),"

        "   ('2020-06-01', 1, -198.09, 2),"
        "   ('2020-06-01', 1, -128.58, 7),"
        "   ('2020-06-01', 1, -3.35, 16),"
        "   ('2020-06-01', 1, -79.99, 5),"
        "   ('2020-06-01', 1, -37.98, 6),"
        "   ('2020-06-01', 1, -34.00, 9),"
        "   ('2020-06-01', 1, +235.00, 15),"

        "   ('2020-07-01', 1, +165.00, 15),"
        "   ('2020-07-01', 1, +4.45, 16),"
        "   ('2020-07-01', 1, -208.95, 2),"
        "   ('2020-07-01', 1, -128.82, 6),"
        "   ('2020-07-01', 1, -6.70, 16),"
        "   ('2020-07-01', 1, -45.70, 7),"
        "   ('2020-07-01', 1, -50.45, 5),"

        "   ('2020-08-01', 1, -573.80, 5),"
        "   ('2020-08-01', 1, -149.90, 10),"
        "   ('2020-08-01', 1, -147.80, 7),"
        "   ('2020-08-01', 1, -35.79, 17),"
        "   ('2020-08-01', 1, -34.05, 2),"
        "   ('2020-08-01', 1, -13.40, 13),"
        "   ('2020-08-01', 1, -3.35, 16),"
        "   ('2020-08-01', 1, +421.40, 15),"

        "   ('2020-09-01', 1, +385.26, 15),"
        "   ('2020-09-01', 1, -221.74, 2),"
        "   ('2020-09-01', 1, -173.20, 9),"
        "   ('2020-09-01', 1, -60.10, 7),"
        "   ('2020-09-01', 1, -29.56, 4),"
        "   ('2020-09-01', 1, -32.97, 10),"
        "   ('2020-09-01', 1, -6.99, 6),"
        "   ('2020-09-01', 1, -3.35, 16),"
        "   ('2020-09-01', 1, -4.20, 5),"

        "   ('2020-10-01', 1, -158.36, 2),"
        "   ('2020-10-01', 1, -26.35, 16),"
        "   ('2020-10-01', 1, -6.00, 13),"
        "   ('2020-10-01', 1, -27.98, 6),"
        "   ('2020-10-01', 1, -24.08, 4),"
        "   ('2020-10-01', 1, +165.00, 15),"
        "   ('2020-10-01', 1, +4.00, 13 ),"

        "   ('2020-11-01', 1, +165.00,15),"
        "   ('2020-11-01', 1, +1093.60, 18),"
        "   ('2020-11-01', 1, -103.68, 2),"
        "   ('2020-11-01', 1, -39.89, 6),"
        "   ('2020-11-01', 1, -9.80, 8),"
        "   ('2020-11-01', 1, -7.00, 4),"
        "   ('2020-11-01', 1, -13.00, 7),"
        "   ('2020-11-01', 1, -3.35, 16),"
        "   ('2020-11-01', 1, -8.00, 10),"

        "   ('2020-12-01', 1, -120.94, 2),"
        "   ('2020-12-01', 1, -81.29, 17),"
        "   ('2020-12-01', 1, -18.00, 4),"
        "   ('2020-12-01', 1, -72.90, 7),"
        "   ('2020-12-01', 1, -55.64, 6),"
        "   ('2020-12-01', 1, -8.00, 10),"
        "   ('2020-12-01', 1, -3.35, 16),"
        "   ('2020-12-01', 1, +165.00, 15),"
        "   ('2020-12-01', 1, +235.20, 18),"
        "   ('2020-12-01', 1, +19.90, 13),"

        "   ('2021-01-01', 1, +798.20, 18),"
        "   ('2021-01-01', 1, +165.00, 15),"
        "   ('2021-01-01', 1, -88.92, 2),"
        "   ('2021-01-01', 1, -18.00, 4),"
        "   ('2021-01-01', 1, -3.35, 16),"

        "   ('2021-02-01', 1, -121.95, 2),"
        "   ('2021-02-01', 1, -55.06, 5),"
        "   ('2021-02-01', 1, -7.99, 6),"
        "   ('2021-02-01', 1, -3.35, 16),"
        "   ('2021-02-01', 1, +165.00, 15),"
        "   ('2021-02-01', 1, +277.20, 18),"

        "   ('2021-03-01', 1, +165.00, 15),"
        "   ('2021-03-01', 1, +380.40, 18),"
        "   ('2021-03-01', 1, +24.00, 15),"
        "   ('2021-03-01', 1, -81.56, 2),"
        "   ('2021-03-01', 1, -46.58, 10),"
        "   ('2021-03-01', 1, -27.01, 5),"
        "   ('2021-03-01', 1, -3.35, 16),"

        "   ('2021-04-01', 1, -195.19, 2),"
        "   ('2021-04-01', 1, -74.30, 7),"
        "   ('2021-04-01', 1, -30.00, 8),"
        "   ('2021-04-01', 1, -3.35, 16),"
        "   ('2021-04-01', 1, +174.00, 18),"
        "   ('2021-04-01', 1, +265.00, 15),"

        "   ('2021-05-01', 1, +165.00, 15),"
        "   ('2021-05-01', 1, +277.00, 18),"
        "   ('2021-05-01', 1, -232.22, 2),"
        "   ('2021-05-01', 1, -136.95, 7),"
        "   ('2021-05-01', 1, -39.00, 13),"
        "   ('2021-05-01', 1, -3.35, 16),"
        "   ('2021-05-01', 1, -11.49, 6),"
        "   ('2021-05-01', 1, -9.90, 4),"

        "   ('2021-06-01', 1, -237.97, 2),"
        "   ('2021-06-01', 1, -123.39, 6),"
        "   ('2021-06-01', 1, -85.97, 7),"
        "   ('2021-06-01', 1, -29.54, 17),"
        "   ('2021-06-01', 1, -4.42, 16),"
        "   ('2021-06-01', 1, +277.00, 18),"
        "   ('2021-06-01', 1, +165.00, 15),"

        "   ('2021-07-01', 1, +165.00, 15),"
        "   ('2021-07-01', 1, +174.00, 18),"
        "   ('2021-07-01', 1, -163.98, 10),"
        "   ('2021-07-01', 1, -110.03, 2),"
        "   ('2021-07-01', 1, -72.00, 7),"
        "   ('2021-07-01', 1, -51.99, 6),"
        "   ('2021-07-01', 1, -8.00, 9),"
        "   ('2021-07-01', 1, -3.35, 16),"
        "   ('2021-07-01', 1, -31.00, 8),"

        "   ('2021-08-01', 1, -92.00, 7),"
        "   ('2021-08-01', 1, -49.99, 5),"
        "   ('2021-08-01', 1, -41.30, 6),"
        "   ('2021-08-01', 1, -108.36, 10),"
        "   ('2021-08-01', 1, -56.09, 2),"
        "   ('2021-08-01', 1, -7.95, 9),"
        "   ('2021-08-01', 1, -6.50, 4),"
        "   ('2021-08-01', 1, -4.31, 16),"
        "   ('2021-08-01', 1, +174.00, 18),"
        "   ('2021-08-01', 1, +565.00, 15),"
        "   ('2021-08-01', 1, +250.00, 15),"

        "   ('2021-09-01', 1, -259.22, 2),"
        "   ('2021-09-01', 1, -239.00, 11),"
        "   ('2021-09-01', 1, -161.83, 6),"
        "   ('2021-09-01', 1, -15.70, 9),"
        "   ('2021-09-01', 1, -13.11, 16),"
        "   ('2021-09-01', 1, -11.20, 7),"
        "   ('2021-09-01', 1, +265.00, 15),"
        "   ('2021-09-01', 1, +174.00, 18),"

        "   ('2021-10-01', 1, +365.00, 15),"
        "   ('2021-10-01', 1, +174.00, 18),"
        "   ('2021-10-01', 1, -165.30, 2),"
        "   ('2021-10-01', 1, -64.00, 8),"
        "   ('2021-10-01', 1, -20.10, 3),"
        "   ('2021-10-01', 1, -16.93, 7),"
        "   ('2021-10-01', 1, -8.99, 6),"
        "   ('2021-10-01', 1, -3.35, 16),"

        "   ('2021-11-01', 1, -281.36, 2),"
        "   ('2021-11-01', 1, -95.00, 8),"
        "   ('2021-11-01', 1, -26.90, 3),"
        "   ('2021-11-01', 1, -99.98, 7),"
        "   ('2021-11-01', 1, -4.90, 13),"
        "   ('2021-11-01', 1, -3.35, 16),"
        "   ('2021-11-01', 1, +265.00, 15),"
        "   ('2021-11-01', 1, +174.00, 18),"
        "   ('2021-11-01', 1, +12.00, 7),"

        "   ('2021-12-01', 1, +175.00, 18),"
        "   ('2021-12-01', 1, +165.00, 15),"
        "   ('2021-12-01', 1, -229.95, 10),"
        "   ('2021-12-01', 1, -176.40, 2),"
        "   ('2021-12-01', 1, -88.20, 3),"
        "   ('2021-12-01', 1, -33.98, 5),"
        "   ('2021-12-01', 1, -62.93, 6),"
        "   ('2021-12-01', 1, -25.05, 9),"
        "   ('2021-12-01', 1, -15.90, 7),"
        "   ('2021-12-01', 1, -3.35, 16)"
    );

    if(exec(&query)) return true;

    qDebug()<<"Fail to insert default transactions";
    return false;
}
bool DatabaseHandler::insertDefaultBanks(){
    QSqlQuery query;
    query.prepare(
        "INSERT INTO bank (name) "
        "VALUES "
            "('BNP Parisbas'),"
            "('Credit Agricole'),"
            "('Societe Generale'),"
            "('Groupe BPCE'),"
            "('Credit Mutuel'),"
            "('LCL'),"
            "('HS16 France'),"
            "('La Banque Postale'),"
            "('Natixis'),"
            "('Credit du Nord')"
    );

    if(exec(&query)) return true;

    qDebug()<<"Fail to insert default accounts";
    return false;
}
bool DatabaseHandler::insertDefaultValues(){
    bool status = true;

    status &= insertDefaultAccounts();
    status &= insertDefaultCategories();
    status &= insertDefaultBanks();
    status &= insertDefaultTransactions();

    if(status) qDebug()<<"OK - Default values successfull inserted.";

    return status;
}

bool DatabaseHandler::loadAccounts(){
    QSqlQuery query;
    query.prepare("SELECT id FROM account");

    if(!exec(&query))return false;

    while(query.next()){
        int id   = query.value("id").toInt();
        _accounts.append(new Account(id, this));
    }

    qDebug()<<"OK - Account loaded.";
    return true;
}

bool DatabaseHandler::exec(QSqlQuery *query){
    if(!query->exec()){
        qDebug()<<"ERROR - Fail to execute query : "<<query->executedQuery();
        qDebug()<<"SQL "<<query->lastError().text();
        return false;
    }
    return true;
}

void DatabaseHandler::insertTransaction(QString accountId, QString amount, QString date, QString categoryId, QString details){
    QSqlQuery query;
    query.prepare("INSERT INTO moneytransaction(account, amount, date, category) "
                  "VALUES (:accountId, :amount, :date, :categoryId)");

    query.bindValue(":accountId", accountId);
    query.bindValue(":amount", amount);
    query.bindValue(":date", date);
    query.bindValue(":categoryId", categoryId);

    if (!exec(&query)) return;
    qDebug()<< "OK - Transaction inserted " << accountId <<" "<<amount;
}

bool DatabaseHandler::addAccount(QString name, QString number, QString bank, QString type){
    QString bankId = getBankId(bank);

    QSqlQuery query;
    query.prepare("INSERT INTO account (name, number, bank, type) "
                   "VALUES (:name, :number, :bank, :type)");

    query.bindValue(":name", name);
    query.bindValue(":number", number);
    query.bindValue(":bank", bankId);
    query.bindValue(":type", type);

    if(!exec(&query)){
        qDebug()<<"Fail to add new account "<<name<<".";
        return false;
    }


    int id = query.lastInsertId().toInt();

    _accounts.append(new Account(id,this));
    emit accountsChanged();

    qDebug()<<"OK - Add account"<<id<<" "<<name<<" "<<bank<<" "<<number;
    return true;
}
bool DatabaseHandler::addCategory(QString name){
    QSqlQuery query;
    query.prepare("INSERT INTO category (name) VALUES (:name)");
    query.bindValue(":name",name);

    if(exec(&query)){
        qDebug()<<"Fail to add new category "<<name<<".";
        return false;
    }

    emit categoriesChanged();
    return true;
}
bool DatabaseHandler::addBank(QString name){
    QSqlQuery query;
    query.prepare("INSERT INTO bank (name) VALUES (:name)");
    query.bindValue(":name",name);

    if(exec(&query)){
        qDebug()<<"Fail to add new bank "<<name<<".";
        return false;
    }

    emit banksChanged();
    return true;
}

QVariant     DatabaseHandler::account(int id){
    QVariant var;
    qDebug()<<"Search for account "<<id;
    foreach(auto account, _accounts){
        if(account->id()==id){
            var = QVariant::fromValue(account);
            qDebug()<<"Default account "<<account->name();
        }
    }
    return var;
}
QVariantList DatabaseHandler::accounts() {
    QVariantList list;

    foreach(auto account, _accounts){
        list.append(QVariant::fromValue(account));
        //qDebug()<<QVariant::fromValue(account);
    }

    return list;
}
QVariantList DatabaseHandler::categories(){
    QVariantList list;

    QSqlQuery query;
    query.prepare("SELECT name from category;");

    exec(&query);

    while(query.next()){
        list.append(query.value("name"));
        //qDebug()<<query.value("name");
    }

    return list;
}
QVariantList DatabaseHandler::banks(){
    QVariantList list;

    QSqlQuery query;
    query.prepare("SELECT name from bank");

    exec(&query);

    while(query.next()){
        list.append(query.value("name"));
        //qDebug()<<query.value("name");
    }

    return list;
}

QString DatabaseHandler::getCategorieId(QString name){
    QSqlQuery query;
    query.prepare("SELECT id FROM category WHERE name=:categoryName;");
    query.bindValue(":categoryName",name);
    exec(&query);
    query.next();
    return query.value(0).toString();
}
QString DatabaseHandler::getAccountId(QString name){
    QSqlQuery query;
    query.prepare("SELECT id FROM account WHERE name=:categoryName;");
    query.bindValue(":categoryName",name);

    exec(&query);
    query.next();
    //qDebug()<<"get category id : "<<name<<" "<<_query.value(0).toString();
    return query.value(0).toString();
}
QString DatabaseHandler::getBankId(QString name){
    QSqlQuery query;
    query.prepare("SELECT id FROM bank WHERE name=:categoryName;");
    query.bindValue(":categoryName",name);

    exec(&query);
    query.next();
    //qDebug()<<"get bank id : "<<name<<" "<<_query.value(0).toString();
    return query.value(0).toString();
}
