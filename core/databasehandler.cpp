#include "databasehandler.h"
#include <QDebug>
#include <QDate>
#include <QSqlError>
#include <QSqlRecord>

QString databaseName = "gestion_bancaire.sqlite";
QString userName = "root";
QString userPassword = "MySQL";
QString databaseDriver = "QSQLITE";


DatabaseHandler::DatabaseHandler()
{
    openDatabase();
    _query = QSqlQuery(_bdd);
    //createGestionBancaire();
}

QString DatabaseHandler::category(int num)      {
    switch (num) {
        case 0: return "Bilan";
        case 1: return "Job";
        case 2: return "Food";
        case 3: return "Bar";
        case 4: return "Restorant";
        case 5: return "Technology";
        case 6: return "Numerical";
        case 7: return "Life";
        case 8: return "Sport";
        case 9: return "Health";
        case 10: return "Transport";
        case 11: return "Bike";
        case 12: return "Car";
        case 13: return "Else";
        default: return "Unknown";
    }
}
int     DatabaseHandler::category(QString name) {
    if (name == "Bilan") return 0;
    if (name == "Job") return 1;
    if (name == "Food") return 2;
    if (name == "Bar") return 3;
    if (name == "Restorant") return 4;
    if (name == "Technology") return 5;
    if (name == "Numerical") return 6;
    if (name == "Life") return 7;
    if (name == "Sport") return 8;
    if (name == "Health") return 9;
    if (name == "Transport") return 10;
    if (name == "Bike") return 11;
    if (name == "Car") return 12;
    if (name == "Else") return 13;
    return -1; // Return -1 for unknown category
}
QString DatabaseHandler::account(int num)       {
    switch (num) {
        case 0: return "Compte courant";
        case 1: return "Livret Beu";
        case 2: return "Livret Jeune";
        default: return "Unknown";
    }
}
int     DatabaseHandler::account(QString name)  {
    if (name == "Compte courant") return 0;
    if (name == "Livret Beu") return 1;
    if (name == "Livret Jeune") return 2;
    return -1; // Return -1 for unknown account type
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
void DatabaseHandler::createGestionBancaire(){
    createDefaultTables();
    loadDefaultValues();
}
void DatabaseHandler::createDefaultTables(){
    QString createTable[3];

    createTable[0] =
        "CREATE TABLE account ("
        "   id      INTEGER PRIMARY KEY NOT NULL, "
        "   name    CHAR(50) NOT NULL, "
        "   sold    REAL NOT NULL "
        ");"
    ;

    createTable[1] =
        "CREATE TABLE category ("
        "   id      INTEGER PRIMARY KEY NOT NULL, "
        "   name    CHAR(50) NOT NULL "
        ");"
    ;

    createTable[2] =
        "CREATE TABLE moneytransaction ("
        "    id        INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "    amount    REAL NOT NULL, "
        "    date      DATE NOT NULL, "
        "    account   INTEGER NOT NULL, "
        "    category  INTEGER NOT NULL, "
        "    FOREIGN KEY (account) REFERENCES account(id), "
        "    FOREIGN KEY (category) REFERENCES category(id) "
        ");"
    ;


    for(int i=0;i<3;i++){
        if(!_query.exec(createTable[i])){
            qDebug() << "Error - creating table: " << _query.lastError().text();
            return;
        }
        qDebug()<< "OK - Table "<<i<<" added ";
    }

    qDebug()<<"OK - Tables added successfully.";
}

double getInitialSoldValue(int accountId) {
    switch (accountId) {
        case 0: return 849.32;
        case 1: return 11500.00;
        case 2: return 1661.82;
        default: return 0.0;
    }
}
QString DatabaseHandler::getAccountInsertStatement()  {
    QString insertStatement = "INSERT INTO account (id, name, sold) VALUES ";

    for (int i = 0; i <= 2; ++i) {
        insertStatement += QString("(%1, '%2', %3)").arg(i).arg(account(i)).arg(getInitialSoldValue(i));
        if (i < 2) {
            insertStatement += ",";
        }
    }

    insertStatement += ";";

    return insertStatement;
}
QString DatabaseHandler::getCategoryInsertStatement() {
    QString insertStatement = "INSERT INTO category (id, name) VALUES ";

    for (int i = 0; i <= 13; ++i) {
        insertStatement += QString("(%1, '%2')").arg(i).arg(category(i));
        if (i < 13) insertStatement += ",";
    }

    insertStatement += ";";

    return insertStatement;
}

void DatabaseHandler::loadDefaultValues(){
    QString fillTable[3];

    fillTable[0] = getCategoryInsertStatement();
    fillTable[1] = getAccountInsertStatement();

    fillTable[2] =
        "INSERT INTO moneytransaction (date, account, amount, category)"
        "VALUES"

        "   ('2019-05-01', 0, -40.25,  0),"
        "   ('2019-06-01', 0, 114.52,  0),"
        "   ('2019-07-01', 0, -338.57, 0),"
        "   ('2019-08-01', 0, 26.56,   0),"
        "   ('2019-09-01', 0, -26.62,  0),"
        "   ('2019-10-01', 0, -0.30,   0),"
        "   ('2019-11-01', 0, 0.02,    0),"
        "   ('2019-12-01', 0, -60.74,  0),"
        "   ('2020-01-01', 0, 3.48,    0),"
        "   ('2020-02-01', 0, 26.13,   0),"
        "   ('2020-03-01', 0, -38.58,  0),"
        "   ('2020-04-01', 0, -33.61,  0),"
        "   ('2020-05-01', 0, 61.01,   0),"
        "   ('2020-06-01', 0, -301.20, 0),"
        "   ('2020-07-01', 0, -271.12, 0),"
        "   ('2020-08-01', 0, -536.69, 0),"
        "   ('2020-09-01', 0, -146.85, 0),"
        "   ('2020-10-01', 0, -65.77,  0),"
        "   ('2020-11-01', 0, 1073.30, 0),"
        "   ('2020-12-01', 0, 245.60,  0),"
        "   ('2021-01-01', 0, 858.99,  0),"
        "   ('2021-02-01', 0, 242.99,  0),"
        "   ('2021-03-01', 0, 355.78,  0),"
        "   ('2021-04-01', 0, 136.16,  0),"
        "   ('2021-05-01', 0, 9.29,    0),"
        "   ('2021-06-01', 0, -39.09,  0),"
        "   ('2021-07-01', 0, -111.35, 0),"
        "   ('2021-08-01', 0, 622.50,  0),"
        "   ('2021-09-01', 0, -261.06, 0),"
        "   ('2021-10-01', 0, 262.13,  0),"
        "   ('2021-11-01', 0, -59.49,  0),"
        "   ('2021-12-01', 0, -295.76, 0),"
        "   ('2022-01-01', 0, 27.86,   0),"
        "   ('2022-02-01', 0, -152.09, 0),"
        "   ('2022-03-01', 0, -293.61, 0),"
        "   ('2022-04-01', 0, -205.44, 0),"
        "   ('2022-05-01', 0, -431.23, 0),"
        "   ('2022-06-01', 0, -132.17, 0),"
        "   ('2022-07-01', 0, 245.93,  0),"
        "   ('2022-08-01', 0, 312.19,  0),"
        "   ('2022-09-01', 0, -409.14, 0),"
        "   ('2022-10-01', 0, 2344.28, 0),"
        "   ('2022-11-01', 0, -230.83, 0),"
        "   ('2022-12-01', 0, 901.77,  0),"
        "   ('2023-01-01', 0, 804.77,  0),"
        "   ('2023-02-01', 0, 1888.94, 0),"
        "   ('2023-03-01', 0, 671.57,  0),"
        "   ('2023-04-01', 0, 913.76,  0),"
        "   ('2023-05-01', 0, 599.33,  0),"
        "   ('2023-06-01', 0, 1345.43, 0),"
        "   ('2023-07-01', 0, -222.69, 0),"
        "   ('2023-08-01', 0, -362.03, 0),"
        "   ('2023-09-01', 0, 534.58,  0),"
        "   ('2023-10-01', 0, 1057.33, 0),"

        "   ('2019-05-01', 0, -92.73, 2),"
        "   ('2019-05-01', 0, -60.55, 9),"
        "   ('2019-05-01', 0, -53.98, 5),"
        "   ('2019-05-01', 0, -3.35, 13),"
        "   ('2019-05-01', 0, -14.99, 7),"

        "   ('2019-06-01', 0, -95.08, 2),"
        "   ('2019-06-01', 0, -9.90,  5),"
        "   ('2019-06-01', 0, -5.50,  9),"
        "   ('2019-06-01', 0, -3.35,  13),"

        "   ('2019-07-01', 0, -239.09, 2),"
        "   ('2019-07-01', 0, -200.00, 11),"
        "   ('2019-07-01', 0, -66.80,  10),"
        "   ('2019-07-01', 0, -87.98,  5),"
        "   ('2019-07-01', 0, -18.40,  7),"
        "   ('2019-07-01', 0, -36.30,  5),"
        "   ('2019-07-01', 0, -3.35,   13),"

        "   ('2019-08-01', 0, -105.02, 2),"
        "   ('2019-08-01', 0, -52.00,  8),"
        "   ('2019-08-01', 0, -12.50,  4),"
        "   ('2019-08-01', 0, -26.79,  5),"
        "   ('2019-08-01', 0, -4.35,   13),"
        "   ('2019-08-01', 0, -25.50,  10),"
        "   ('2019-08-01', 0, -16.60,  11),"

        "   ('2019-09-01', 0, -148.91, 2),"
        "   ('2019-09-01', 0, -101.37, 7),"
        "   ('2019-09-01', 0, -14.99,  5),"
        "   ('2019-09-01', 0, -3.35,   13),"

        "   ('2019-10-01', 0, -236.55, 2),"
        "   ('2019-10-01', 0, -34.00,  9),"
        "   ('2019-10-01', 0, -18.40,  7),"
        "   ('2019-10-01', 0, -3.35,   13),"

        "   ('2019-11-01', 0, -76.79,  2),"
        "   ('2019-11-01', 0, -14.00,  5),"
        "   ('2019-11-01', 0, -3.35,   13),"

        "   ('2019-12-01', 0, -185.37, 9),"
        "   ('2019-12-01', 0, -129.02, 2),"
        "   ('2019-12-01', 0, -9.00,   10),"
        "   ('2019-12-01', 0, -3.35,   13),"

        "   ('2020-01-01', 0, -162.67, 2),"
        "   ('2020-01-01', 0, -6.50,   9),"
        "   ('2020-01-01', 0, -3.35,   13),"

        "   ('2020-02-01', 0, -168.56, 2),"
        "   ('2020-02-01', 0, -87.51, 5),"
        "   ('2020-04-01', 0, -45.32,  6),"
        "   ('2020-02-01', 0, -13.99,  8),"
        "   ('2020-02-01', 0, -55.67,  7),"
        "   ('2020-02-01', 0, -4.82,   13),"

        "   ('2020-03-01', 0, -242.19, 2),"
        "   ('2020-03-01', 0, -53.18,  6),"
        "   ('2020-03-01', 0, -14.40,  4),"
        "   ('2020-03-01', 0, -4.81,   13),"

        "   ('2020-04-01', 0, -212.49, 2),"
        "   ('2020-04-01', 0, -53.31,  6),"
        "   ('2020-04-01', 0, -4.81,   13),"

        "   ('2020-05-01', 0, -79.13,  2),"
        "   ('2020-05-01', 0, -46.12,  7),"
        "   ('2020-05-01', 0, -13.91,  6),"
        "   ('2020-05-01', 0, -6.00,   4),"
        "   ('2020-05-01', 0, -4.03,   13),"
        "   ('2020-05-01', 0, -1.70,   9),"

        "   ('2020-06-01', 0, -198.09, 2),"
        "   ('2020-06-01', 0, -60.00,  7),"
        "   ('2020-06-01', 0, -45.00,  3),"
        "   ('2020-06-01', 0, -3.35,   13),"
        "   ('2020-06-01', 0, -93.57,  5),"
        "   ('2020-06-01', 0, -64.21,  5),"
        "   ('2020-06-01', 0, -37.98,  6),"
        "   ('2020-06-01', 0, -34.00,  9),"

        "   ('2020-07-01', 0, -208.95, 2),"
        "   ('2020-07-01', 0, -128.82, 6),"
        "   ('2020-07-01', 0, -28.25,  10),"
        "   ('2020-07-01', 0, -17.45,  7),"
        "   ('2020-07-01', 0, -6.70,   13),"
        "   ('2020-07-01', 0, -50.45,  5),"

        "   ('2020-08-01', 0, -549.80, 5),"
        "   ('2020-08-01', 0, -173.90, 10),"
        "   ('2020-08-01', 0, -127.80, 7),"
        "   ('2020-08-01', 0, -35.79,  5),"
        "   ('2020-08-01', 0, -34.05,  2),"
        "   ('2020-08-01', 0, -16.75,  13),"

        "   ('2020-09-01', 0, -221.74, 2),"
        "   ('2020-09-01', 0, -173.20, 9),"
        "   ('2020-09-01', 0, -59.67,  4),"
        "   ('2020-09-01', 0, -32.97,  10),"
        "   ('2020-09-01', 0, -29.99,  7),"
        "   ('2020-09-01', 0, -6.99,   6),"
        "   ('2020-09-01', 0, -4.20,   5),"
        "   ('2020-09-01', 0, -3.35,   13),"

        "   ('2020-10-01', 0, -158.38, 2),"
        "   ('2020-10-01', 0, -32.35,  13),"
        "   ('2020-10-01', 0, -27.98,  6),"
        "   ('2020-10-01', 0, -24.08,  4),"

        "   ('2020-11-01', 0, -103.68,2),"
        "   ('2020-11-01', 0, -39.89, 6),"
        "   ('2020-11-01', 0, -9.80,  8),"
        "   ('2020-11-01', 0, -7.00,  4),"
        "   ('2020-11-01', 0, -3.35,  13),"
        "   ('2020-11-01', 0, -8.00,  10),"
        "   ('2020-11-01', 0, -13.00, 7),"

        "   ('2020-12-01', 0, -120.94,2),"
        "   ('2020-12-01', 0, -81.29, 5),"
        "   ('2020-12-01', 0, -32.90, 4),"
        "   ('2020-12-01', 0, -58.00, 7),"
        "   ('2020-12-01', 0, -55.64, 6),"
        "   ('2020-12-01', 0, -8.00,  10),"
        "   ('2020-12-01', 0, -3.35,  13),"

        "   ('2021-01-01', 0, -88.92, 2),"
        "   ('2021-01-01', 0, -18.00, 4),"
        "   ('2021-01-01', 0, -3.35,  13),"

        "   ('2021-02-01', 0, -121.95,2),"
        "   ('2021-02-01', 0, -55.06, 5),"
        "   ('2021-02-01', 0, -7.99,  6),"
        "   ('2021-02-01', 0, -3.35,  13),"

        "   ('2021-03-01', 0, -81.56, 2),"
        "   ('2021-03-01', 0, -27.01, 5),"
        "   ('2021-03-01', 0, -46.58, 4),"
        "   ('2021-03-01', 0, -3.35,  13),"

        "   ('2021-04-01', 0, -195.19,2),"
        "   ('2021-04-01', 0, -73.30, 5),"
        "   ('2021-04-01', 0, -30.00, 8),"
        "   ('2021-04-01', 0, -3.35,  13),"

        "   ('2021-05-01', 0, -232.22,2),"
        "   ('2021-05-01', 0, -14.98, 5),"
        "   ('2021-05-01', 0, -12.00, 10),"
        "   ('2021-05-01', 0, -109.97,7),"
        "   ('2021-05-01', 0, -42.35, 13),"
        "   ('2021-05-01', 0, -11.49, 6),"
        "   ('2021-05-01', 0, -9.90,  4),"

        "   ('2021-06-01', 0, -237.97,2),"
        "   ('2021-06-01', 0, -123.39,6),"
        "   ('2021-06-01', 0, -85.97, 10),"
        "   ('2021-06-01', 0, -29.54, 5),"
        "   ('2021-06-01', 0, -4.42,  13),"

        "   ('2021-07-01', 0, -110.03,2),"
        "   ('2021-07-01', 0, -154.93,10),"
        "   ('2021-07-01', 0, -91.05, 7),"
        "   ('2021-07-01', 0, -51.99, 6),"
        "   ('2021-07-01', 0, -31.00, 8),"
        "   ('2021-07-01', 0, -8.00,  9),"
        "   ('2021-07-01', 0, -3.35,  13),"

        "   ('2021-08-01', 0, -92.00, 7),"
        "   ('2021-08-01', 0, -49.99, 5),"
        "   ('2021-08-01', 0, -41.30, 6),"
        "   ('2021-08-01', 0, -108.36,10),"
        "   ('2021-08-01', 0, -56.09, 2),"
        "   ('2021-08-01', 0, -7.95,  9),"
        "   ('2021-08-01', 0, -6.50,  5),"
        "   ('2021-08-01', 0, -4.31,  13),"

        "   ('2021-09-01', 0, -259.22,2),"
        "   ('2021-09-01', 0, -239.00,11),"
        "   ('2021-09-01', 0, -161.83,6),"
        "   ('2021-09-01', 0, -15.70, 9),"
        "   ('2021-09-01', 0, -11.20, 3),"
        "   ('2021-09-01', 0, -13.11, 13),"

        "   ('2021-10-01', 0, -163.50,2),"
        "   ('2021-10-01', 0, -20.10, 3),"
        "   ('2021-10-01', 0, -64.00, 8),"
        "   ('2021-10-01', 0, -16.93, 5),"
        "   ('2021-10-01', 0, -8.99,  6),"
        "   ('2021-10-01', 0, -3.35,  13),"

        "   ('2021-11-01', 0, -281.36,2),"
        "   ('2021-11-01', 0, -26.90, 3),"
        "   ('2021-11-01', 0, -95.00, 8),"
        "   ('2021-11-01', 0, -99.98, 7),"
        "   ('2021-11-01', 0, -7.25,  13),"

        "   ('2021-12-01', 0, -176.40,2),"
        "   ('2021-12-01', 0, -229.95,10),"
        "   ('2021-12-01', 0, -88.20, 3),"
        "   ('2021-12-01', 0, -33.98, 5),"
        "   ('2021-12-01', 0, -62.93, 6),"
        "   ('2021-12-01', 0, -25.05, 9),"
        "   ('2021-12-01', 0, -15.90, 7),"
        "   ('2021-12-01', 0, -3.35,  13),"

        "   ('2019-05-01', 0, 185.35,  1),"
        "   ('2019-06-01', 0, 228.35,  1),"
        "   ('2019-07-01', 0, 313.35,  1),"
        "   ('2019-08-01', 0, 272.50,  1),"
        "   ('2019-09-01', 0, 242.00,  1),"
        "   ('2019-10-01', 0, 292.00,  1),"
        "   ('2019-11-01', 0, 99.15,   1),"
        "   ('2019-12-01', 0, 266.00,  1),"
        "   ('2020-01-01', 0, 176.00,  1),"
        "   ('2020-02-01', 0, 402.00,  1),"
        "   ('2020-03-01', 0, 276.00,  1),"
        "   ('2020-04-01', 0, 237.00,  1),"
        "   ('2020-05-01', 0, 211.90,  1),"
        "   ('2020-06-01', 0, 235.00,  1),"
        "   ('2020-07-01', 0, 169.50,  1),"
        "   ('2020-08-01', 0, 421.40,  1),"
        "   ('2020-09-01', 0, 385.26,  1),"
        "   ('2020-10-01', 0, 169.00,  1),"
        "   ('2020-11-01', 0, 1258.60, 1),"
        "   ('2020-12-01', 0, 438.10,  1),"
        "   ('2021-01-01', 0, 963.20,  1),"
        "   ('2021-02-01', 0, 442.20,  1),"
        "   ('2021-03-01', 0, 569.40,  1),"
        "   ('2021-04-01', 0, 439.00,  1),"
        "   ('2021-05-01', 0, 442.20,  1),"
        "   ('2021-06-01', 0, 442.20,  1),"
        "   ('2021-07-01', 0, 339.00,  1),"
        "   ('2021-08-01', 0, 989.00,  1),"
        "   ('2021-09-01', 0, 439.00,  1),"
        "   ('2021-10-01', 0, 539.00,  1),"
        "   ('2021-11-01', 0, 452.00,  1),"
        "   ('2021-12-01', 0, 340.00,  1),"
        "   ('2022-01-01', 0, 440.00,  1),"
        "   ('2022-02-01', 0, 340.00,  1),"
        "   ('2022-03-01', 0, 340.00,  1),"
        "   ('2022-04-01', 0, 340.00,  1),"
        "   ('2022-05-01', 0, 660.81,  1),"
        "   ('2022-06-01', 0, 982.37,  1),"
        "   ('2022-07-01', 0, 2166.79, 1),"
        "   ('2022-08-01', 0, 922.10,  1),"
        "   ('2022-09-01', 0, 362.52,  1),"
        "   ('2022-10-01', 0, 3031.28, 1),"
        "   ('2022-11-01', 0, 1823.63, 1),"
        "   ('2022-12-01', 0, 1979.70, 1),"
        "   ('2023-01-01', 0, 1900.02, 1),"
        "   ('2023-02-01', 0, 2620.11, 1),"
        "   ('2023-03-01', 0, 1530.60, 1),"
        "   ('2023-04-01', 0, 1510.94, 1),"
        "   ('2023-05-01', 0, 1596.23, 1),"
        "   ('2023-06-01', 0, 2720.12, 1),"
        "   ('2023-07-01', 0, 1939.83, 1),"
        "   ('2023-08-01', 0, 1874.52, 1),"
        "   ('2023-09-01', 0, 1580.39, 1),"
        "   ('2023-10-01', 0, 1911.65, 1)"
        ";"
    ;


    for(int i=0;i<3;i++){
        if(!_query.exec(fillTable[i])){
            qDebug() << "Error - filling table: " << _query.lastError().text();
            if(_query.lastError().nativeErrorCode()!="1555") return;
        }
        qDebug()<<"OK - Data "<<i<<" sucessfuly imported";
    }

    qDebug()<<"OK - Datas sucessfuly imported";
}


bool DatabaseHandler::queryExec(QString txt){
    if(!_query.exec(txt)){
        qDebug()<<"ERROR - Fail to execute query : "<<txt;
        qDebug()<<"SQL "<<_query.lastError().text();
        return false;
    }
    return true;
}


QList<QString> DatabaseHandler::getAllItems(const QString& tableName, const QString& columnName) {
    QList<QString> list;

    QString queryStr = "SELECT " + columnName + " FROM " + tableName;
    queryExec(queryStr);

    int id = _query.record().indexOf(columnName);
    while (_query.next()) {
        list.append(_query.value(id).toString());
    }

    return list;
}

QList<QMap<QString, QString>> DatabaseHandler::getItemsWithColumns(const QString& tableName, const QStringList& columnNames) {
    QList<QMap<QString, QString>> itemList;

    QString columns = columnNames.join(", ");
    QString queryStr = "SELECT " + columns + " FROM " + tableName;
    queryExec(queryStr);

    while (_query.next()) {
        QMap<QString, QString> itemData;
        for (const QString& columnName : columnNames) {
            itemData[columnName] = _query.value(columnName).toString();
        }
        itemList.append(itemData);
    }

    return itemList;
}


void DatabaseHandler::insertTransaction(QString accountId, QString amount, QString date, QString categoryId, QString details){
    QString txt = "";

    // Insert transaction in database

    txt = "INSERT INTO moneytransaction(account, amount, date, category) "
          "VALUES ("+accountId+",'"+amount+"','"+date+"',"+categoryId+");";

    if(!queryExec(txt)) return;
    qDebug()<< "OK - Transaction inserted " << account(accountId.toInt()) <<" "<<amount;


    // Update account's sold

    txt = "UPDATE account SET sold = sold +("+amount+") WHERE id = "+accountId+";";

    if(!queryExec(txt)) return;
    qDebug() << "OK - Account's sold updated";
}


float DatabaseHandler::getSold(QString accountId){
    QString txt = "SELECT sold from account where id = "+accountId+";";

    if(!queryExec(txt)) return 0.0;

    _query.next();
    float sold = _query.value("sold").toFloat();
    qDebug()<<"OK - Sold retreived "<<sold;
    return sold;
}
