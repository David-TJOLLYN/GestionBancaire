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
            "('Bilan'),('Job'),('Food'),('Bar'),('Restorant'),('Technology'),"
            "('Numerical'),('Life'),('Sport'),('Health'),('Transport'),('Bike'),"
            "('Car'),('Else'),('Internal')"
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

        "   ('2019-05-01', 1, -40.25,  0),"
        "   ('2019-06-01', 1, 114.52,  0),"
        "   ('2019-07-01', 1, -338.57, 0),"
        "   ('2019-08-01', 1, 26.56,   0),"
        "   ('2019-09-01', 1, -26.62,  0),"
        "   ('2019-10-01', 1, -0.30,   0),"
        "   ('2019-11-01', 1, 0.02,    0),"
        "   ('2019-12-01', 1, -60.74,  0),"
        "   ('2020-01-01', 1, 3.48,    0),"
        "   ('2020-02-01', 1, 26.13,   0),"
        "   ('2020-03-01', 1, -38.58,  0),"
        "   ('2020-04-01', 1, -33.61,  0),"
        "   ('2020-05-01', 1, 61.01,   0),"
        "   ('2020-06-01', 1, -301.20, 0),"
        "   ('2020-07-01', 1, -271.12, 0),"
        "   ('2020-08-01', 1, -536.69, 0),"
        "   ('2020-09-01', 1, -146.85, 0),"
        "   ('2020-10-01', 1, -65.77,  0),"
        "   ('2020-11-01', 1, 1073.30, 0),"
        "   ('2020-12-01', 1, 245.60,  0),"
        "   ('2021-01-01', 1, 858.99,  0),"
        "   ('2021-02-01', 1, 242.99,  0),"
        "   ('2021-03-01', 1, 355.78,  0),"
        "   ('2021-04-01', 1, 136.16,  0),"
        "   ('2021-05-01', 1, 9.29,    0),"
        "   ('2021-06-01', 1, -39.09,  0),"
        "   ('2021-07-01', 1, -111.35, 0),"
        "   ('2021-08-01', 1, 622.50,  0),"
        "   ('2021-09-01', 1, -261.06, 0),"
        "   ('2021-10-01', 1, 262.13,  0),"
        "   ('2021-11-01', 1, -59.49,  0),"
        "   ('2021-12-01', 1, -295.76, 0),"
        "   ('2022-01-01', 1, 27.86,   0),"
        "   ('2022-02-01', 1, -152.09, 0),"
        "   ('2022-03-01', 1, -293.61, 0),"
        "   ('2022-04-01', 1, -205.44, 0),"
        "   ('2022-05-01', 1, -431.23, 0),"
        "   ('2022-06-01', 1, -132.17, 0),"
        "   ('2022-07-01', 1, 245.93,  0),"
        "   ('2022-08-01', 1, 312.19,  0),"
        "   ('2022-09-01', 1, -409.14, 0),"
        "   ('2022-10-01', 1, 2344.28, 0),"
        "   ('2022-11-01', 1, -230.83, 0),"
        "   ('2022-12-01', 1, 901.77,  0),"
        "   ('2023-01-01', 1, 804.77,  0),"
        "   ('2023-02-01', 1, 1888.94, 0),"
        "   ('2023-03-01', 1, 671.57,  0),"
        "   ('2023-04-01', 1, 913.76,  0),"
        "   ('2023-05-01', 1, 599.33,  0),"
        "   ('2023-06-01', 1, 1345.43, 0),"
        "   ('2023-07-01', 1, -222.69, 0),"
        "   ('2023-08-01', 1, -362.03, 0),"
        "   ('2023-09-01', 1, 534.58,  0),"
        "   ('2023-10-01', 1, 1057.33, 0),"

        "   ('2019-05-01', 1, -92.73, 2),"
        "   ('2019-05-01', 1, -60.55, 9),"
        "   ('2019-05-01', 1, -53.98, 5),"
        "   ('2019-05-01', 1, -3.35, 13),"
        "   ('2019-05-01', 1, -14.99, 7),"

        "   ('2019-06-01', 1, -95.08, 2),"
        "   ('2019-06-01', 1, -9.90,  5),"
        "   ('2019-06-01', 1, -5.50,  9),"
        "   ('2019-06-01', 1, -3.35,  13),"

        "   ('2019-07-01', 1, -239.09, 2),"
        "   ('2019-07-01', 1, -200.00, 11),"
        "   ('2019-07-01', 1, -66.80,  10),"
        "   ('2019-07-01', 1, -87.98,  5),"
        "   ('2019-07-01', 1, -18.40,  7),"
        "   ('2019-07-01', 1, -36.30,  5),"
        "   ('2019-07-01', 1, -3.35,   13),"

        "   ('2019-08-01', 1, -105.02, 2),"
        "   ('2019-08-01', 1, -52.00,  8),"
        "   ('2019-08-01', 1, -12.50,  4),"
        "   ('2019-08-01', 1, -26.79,  5),"
        "   ('2019-08-01', 1, -4.35,   13),"
        "   ('2019-08-01', 1, -25.50,  10),"
        "   ('2019-08-01', 1, -16.60,  11),"

        "   ('2019-09-01', 1, -148.91, 2),"
        "   ('2019-09-01', 1, -101.37, 7),"
        "   ('2019-09-01', 1, -14.99,  5),"
        "   ('2019-09-01', 1, -3.35,   13),"

        "   ('2019-10-01', 1, -236.55, 2),"
        "   ('2019-10-01', 1, -34.00,  9),"
        "   ('2019-10-01', 1, -18.40,  7),"
        "   ('2019-10-01', 1, -3.35,   13),"

        "   ('2019-11-01', 1, -76.79,  2),"
        "   ('2019-11-01', 1, -14.00,  5),"
        "   ('2019-11-01', 1, -3.35,   13),"

        "   ('2019-12-01', 1, -185.37, 9),"
        "   ('2019-12-01', 1, -129.02, 2),"
        "   ('2019-12-01', 1, -9.00,   10),"
        "   ('2019-12-01', 1, -3.35,   13),"

        "   ('2020-01-01', 1, -162.67, 2),"
        "   ('2020-01-01', 1, -6.50,   9),"
        "   ('2020-01-01', 1, -3.35,   13),"

        "   ('2020-02-01', 1, -168.56, 2),"
        "   ('2020-02-01', 1, -87.51, 5),"
        "   ('2020-04-01', 1, -45.32,  6),"
        "   ('2020-02-01', 1, -13.99,  8),"
        "   ('2020-02-01', 1, -55.67,  7),"
        "   ('2020-02-01', 1, -4.82,   13),"

        "   ('2020-03-01', 1, -242.19, 2),"
        "   ('2020-03-01', 1, -53.18,  6),"
        "   ('2020-03-01', 1, -14.40,  4),"
        "   ('2020-03-01', 1, -4.81,   13),"

        "   ('2020-04-01', 1, -212.49, 2),"
        "   ('2020-04-01', 1, -53.31,  6),"
        "   ('2020-04-01', 1, -4.81,   13),"

        "   ('2020-05-01', 1, -79.13,  2),"
        "   ('2020-05-01', 1, -46.12,  7),"
        "   ('2020-05-01', 1, -13.91,  6),"
        "   ('2020-05-01', 1, -6.00,   4),"
        "   ('2020-05-01', 1, -4.03,   13),"
        "   ('2020-05-01', 1, -1.70,   9),"

        "   ('2020-06-01', 1, -198.09, 2),"
        "   ('2020-06-01', 1, -60.00,  7),"
        "   ('2020-06-01', 1, -45.00,  3),"
        "   ('2020-06-01', 1, -3.35,   13),"
        "   ('2020-06-01', 1, -93.57,  5),"
        "   ('2020-06-01', 1, -64.21,  5),"
        "   ('2020-06-01', 1, -37.98,  6),"
        "   ('2020-06-01', 1, -34.00,  9),"

        "   ('2020-07-01', 1, -208.95, 2),"
        "   ('2020-07-01', 1, -128.82, 6),"
        "   ('2020-07-01', 1, -28.25,  10),"
        "   ('2020-07-01', 1, -17.45,  7),"
        "   ('2020-07-01', 1, -6.70,   13),"
        "   ('2020-07-01', 1, -50.45,  5),"

        "   ('2020-08-01', 1, -549.80, 5),"
        "   ('2020-08-01', 1, -173.90, 10),"
        "   ('2020-08-01', 1, -127.80, 7),"
        "   ('2020-08-01', 1, -35.79,  5),"
        "   ('2020-08-01', 1, -34.05,  2),"
        "   ('2020-08-01', 1, -16.75,  13),"

        "   ('2020-09-01', 1, -221.74, 2),"
        "   ('2020-09-01', 1, -173.20, 9),"
        "   ('2020-09-01', 1, -59.67,  4),"
        "   ('2020-09-01', 1, -32.97,  10),"
        "   ('2020-09-01', 1, -29.99,  7),"
        "   ('2020-09-01', 1, -6.99,   6),"
        "   ('2020-09-01', 1, -4.20,   5),"
        "   ('2020-09-01', 1, -3.35,   13),"

        "   ('2020-10-01', 1, -158.38, 2),"
        "   ('2020-10-01', 1, -32.35,  13),"
        "   ('2020-10-01', 1, -27.98,  6),"
        "   ('2020-10-01', 1, -24.08,  4),"

        "   ('2020-11-01', 1, -103.68,2),"
        "   ('2020-11-01', 1, -39.89, 6),"
        "   ('2020-11-01', 1, -9.80,  8),"
        "   ('2020-11-01', 1, -7.00,  4),"
        "   ('2020-11-01', 1, -3.35,  13),"
        "   ('2020-11-01', 1, -8.00,  10),"
        "   ('2020-11-01', 1, -13.00, 7),"

        "   ('2020-12-01', 1, -120.94,2),"
        "   ('2020-12-01', 1, -81.29, 5),"
        "   ('2020-12-01', 1, -32.90, 4),"
        "   ('2020-12-01', 1, -58.00, 7),"
        "   ('2020-12-01', 1, -55.64, 6),"
        "   ('2020-12-01', 1, -8.00,  10),"
        "   ('2020-12-01', 1, -3.35,  13),"

        "   ('2021-01-01', 1, -88.92, 2),"
        "   ('2021-01-01', 1, -18.00, 4),"
        "   ('2021-01-01', 1, -3.35,  13),"

        "   ('2021-02-01', 1, -121.95,2),"
        "   ('2021-02-01', 1, -55.06, 5),"
        "   ('2021-02-01', 1, -7.99,  6),"
        "   ('2021-02-01', 1, -3.35,  13),"

        "   ('2021-03-01', 1, -81.56, 2),"
        "   ('2021-03-01', 1, -27.01, 5),"
        "   ('2021-03-01', 1, -46.58, 4),"
        "   ('2021-03-01', 1, -3.35,  13),"

        "   ('2021-04-01', 1, -195.19,2),"
        "   ('2021-04-01', 1, -73.30, 5),"
        "   ('2021-04-01', 1, -30.00, 8),"
        "   ('2021-04-01', 1, -3.35,  13),"

        "   ('2021-05-01', 1, -232.22,2),"
        "   ('2021-05-01', 1, -14.98, 5),"
        "   ('2021-05-01', 1, -12.00, 10),"
        "   ('2021-05-01', 1, -109.97,7),"
        "   ('2021-05-01', 1, -42.35, 13),"
        "   ('2021-05-01', 1, -11.49, 6),"
        "   ('2021-05-01', 1, -9.90,  4),"

        "   ('2021-06-01', 1, -237.97,2),"
        "   ('2021-06-01', 1, -123.39,6),"
        "   ('2021-06-01', 1, -85.97, 10),"
        "   ('2021-06-01', 1, -29.54, 5),"
        "   ('2021-06-01', 1, -4.42,  13),"

        "   ('2021-07-01', 1, -110.03,2),"
        "   ('2021-07-01', 1, -154.93,10),"
        "   ('2021-07-01', 1, -91.05, 7),"
        "   ('2021-07-01', 1, -51.99, 6),"
        "   ('2021-07-01', 1, -31.00, 8),"
        "   ('2021-07-01', 1, -8.00,  9),"
        "   ('2021-07-01', 1, -3.35,  13),"

        "   ('2021-08-01', 1, -92.00, 7),"
        "   ('2021-08-01', 1, -49.99, 5),"
        "   ('2021-08-01', 1, -41.30, 6),"
        "   ('2021-08-01', 1, -108.36,10),"
        "   ('2021-08-01', 1, -56.09, 2),"
        "   ('2021-08-01', 1, -7.95,  9),"
        "   ('2021-08-01', 1, -6.50,  5),"
        "   ('2021-08-01', 1, -4.31,  13),"

        "   ('2021-09-01', 1, -259.22,2),"
        "   ('2021-09-01', 1, -239.00,11),"
        "   ('2021-09-01', 1, -161.83,6),"
        "   ('2021-09-01', 1, -15.70, 9),"
        "   ('2021-09-01', 1, -11.20, 3),"
        "   ('2021-09-01', 1, -13.11, 13),"

        "   ('2021-10-01', 1, -163.50,2),"
        "   ('2021-10-01', 1, -20.10, 3),"
        "   ('2021-10-01', 1, -64.00, 8),"
        "   ('2021-10-01', 1, -16.93, 5),"
        "   ('2021-10-01', 1, -8.99,  6),"
        "   ('2021-10-01', 1, -3.35,  13),"

        "   ('2021-11-01', 1, -281.36,2),"
        "   ('2021-11-01', 1, -26.90, 3),"
        "   ('2021-11-01', 1, -95.00, 8),"
        "   ('2021-11-01', 1, -99.98, 7),"
        "   ('2021-11-01', 1, -7.25,  13),"

        "   ('2021-12-01', 1, -176.40,2),"
        "   ('2021-12-01', 1, -229.95,10),"
        "   ('2021-12-01', 1, -88.20, 3),"
        "   ('2021-12-01', 1, -33.98, 5),"
        "   ('2021-12-01', 1, -62.93, 6),"
        "   ('2021-12-01', 1, -25.05, 9),"
        "   ('2021-12-01', 1, -15.90, 7),"
        "   ('2021-12-01', 1, -3.35,  13),"

        "   ('2019-05-01', 1, 185.35,  1),"
        "   ('2019-06-01', 1, 228.35,  1),"
        "   ('2019-07-01', 1, 313.35,  1),"
        "   ('2019-08-01', 1, 272.50,  1),"
        "   ('2019-09-01', 1, 242.00,  1),"
        "   ('2019-10-01', 1, 292.00,  1),"
        "   ('2019-11-01', 1, 99.15,   1),"
        "   ('2019-12-01', 1, 266.00,  1),"
        "   ('2020-01-01', 1, 176.00,  1),"
        "   ('2020-02-01', 1, 402.00,  1),"
        "   ('2020-03-01', 1, 276.00,  1),"
        "   ('2020-04-01', 1, 237.00,  1),"
        "   ('2020-05-01', 1, 211.90,  1),"
        "   ('2020-06-01', 1, 235.00,  1),"
        "   ('2020-07-01', 1, 169.50,  1),"
        "   ('2020-08-01', 1, 421.40,  1),"
        "   ('2020-09-01', 1, 385.26,  1),"
        "   ('2020-10-01', 1, 169.00,  1),"
        "   ('2020-11-01', 1, 1258.60, 1),"
        "   ('2020-12-01', 1, 438.10,  1),"
        "   ('2021-01-01', 1, 963.20,  1),"
        "   ('2021-02-01', 1, 442.20,  1),"
        "   ('2021-03-01', 1, 569.40,  1),"
        "   ('2021-04-01', 1, 439.00,  1),"
        "   ('2021-05-01', 1, 442.20,  1),"
        "   ('2021-06-01', 1, 442.20,  1),"
        "   ('2021-07-01', 1, 339.00,  1),"
        "   ('2021-08-01', 1, 989.00,  1),"
        "   ('2021-09-01', 1, 439.00,  1),"
        "   ('2021-10-01', 1, 539.00,  1),"
        "   ('2021-11-01', 1, 452.00,  1),"
        "   ('2021-12-01', 1, 340.00,  1),"
        "   ('2022-01-01', 1, 440.00,  1),"
        "   ('2022-02-01', 1, 340.00,  1),"
        "   ('2022-03-01', 1, 340.00,  1),"
        "   ('2022-04-01', 1, 340.00,  1),"
        "   ('2022-05-01', 1, 660.81,  1),"
        "   ('2022-06-01', 1, 982.37,  1),"
        "   ('2022-07-01', 1, 2166.79, 1),"
        "   ('2022-08-01', 1, 922.10,  1),"
        "   ('2022-09-01', 1, 362.52,  1),"
        "   ('2022-10-01', 1, 3031.28, 1),"
        "   ('2022-11-01', 1, 1823.63, 1),"
        "   ('2022-12-01', 1, 1979.70, 1),"
        "   ('2023-01-01', 1, 1900.02, 1),"
        "   ('2023-02-01', 1, 2620.11, 1),"
        "   ('2023-03-01', 1, 1530.60, 1),"
        "   ('2023-04-01', 1, 1510.94, 1),"
        "   ('2023-05-01', 1, 1596.23, 1),"
        "   ('2023-06-01', 1, 2720.12, 1),"
        "   ('2023-07-01', 1, 1939.83, 1),"
        "   ('2023-08-01', 1, 1874.52, 1),"
        "   ('2023-09-01', 1, 1580.39, 1),"
        "   ('2023-10-01', 1, 1911.65, 1)"
        ";"
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
            "('HSBC France'),"
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
