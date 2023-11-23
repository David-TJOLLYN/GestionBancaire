#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class DatabaseHandler : public QObject
{
    Q_OBJECT

public:
    DatabaseHandler();

    QList<QString> getAllItems(const QString& tableName, const QString& columnName);
    QList<QMap<QString, QString>> getItemsWithColumns(const QString& tableName, const QStringList& columnNames);

    void insertMoneyTransaction(QString account, qreal value, QString cathegory, QDate date, QString details="");
    QString getSoldString(QString account);

    QSqlQuery* getQuery(){return &_query;}
    bool queryExec(QString txt);

    int account(QString name);
    int category(QString name);
    QString account(int name);
    QString category(int name);


signals:
    void updateSold(QString account, QString newSold);

private:
    QSqlDatabase _bdd;
    QSqlQuery _query;

    bool openDatabase();

    QString getCategoryInsertStatement();
    QString getAccountInsertStatement();

    void createGestionBancaire();
    void loadDefaultValues();
    void createDefaultTables();
};

//clazy:suppress=non-pod-static
namespace TABLES {

    const QString account = "account";
    const QString cathegory = "cathegory";
    const QString moneytransaction = "moneytransaction";
    const QString monthlyrecords = "monthlyrecords";

    namespace Account{
        const QString name = "name";
        const QString sold = "sold";
        const QString details = "details";

        namespace Name {
            const QString compte_courant = "'Compte courant'";
            const QString livret_bleu = "'Livret Beu'";
            const QString livret_jeune= "'Livret Jeune'";
        }
    }

    namespace Cathegory{
        const QString Name = "name";
        const QString Details = "details";
    }

    namespace MoneyTransaction{
        const QString Id = "id";
        const QString value = "amount";
        const QString Date = "date";
        const QString Account = "account";
        const QString Cathegory = "cathegory";
    }

    namespace MonthlyRecords{
        const QString Id = "id";
        const QString value = "amount";
        const QString Date = "date";
        const QString Account = "account";
        const QString Cathegory = "cathegory";
    }
}

#endif // DATABASEHANDLER_H
