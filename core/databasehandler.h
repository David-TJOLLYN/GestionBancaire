#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class Account;

class DatabaseHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList accounts READ accounts NOTIFY accountsChanged FINAL)

public:
    DatabaseHandler(bool *status);

    QList<QString> getAllItems(const QString& tableName, const QString& columnName);
    QList<QMap<QString, QString>> getItemsWithColumns(const QString& tableName, const QStringList& columnNames);

    void insertTransaction(QString accountId, QString amount, QString date, QString categoryId, QString details);
    float getSold(QString accountId);

    bool exec(QSqlQuery *query);

    QVariantList accounts();
    QVariantList getCategories();

    QString getCategorieId(QString name);
//    QString getCategoryName(int id);
    QString getAccountId(QString name);
//    QString getAccountName(int id);

public slots:
    bool addAccount(QString name, QString number, QString bank, QString type);

signals:
    void updateSold(QString account, QString newSold);
    void accountsChanged();

private:
    QSqlDatabase _bdd;
    QList<Account*> _accounts;

    bool openDatabase();
    bool createGestionBancaire();
    bool loadAccounts();

    bool createAccountTable();
    bool createCategoryTable();
    bool createTransactionTable();
    bool createBankTables();
    bool createTables();

    bool insertDefaultAccounts();
    bool insertDefaultCategories();
    bool insertDefaultTransactions();
    bool insertDefaultBanks();
    bool insertDefaultValues();

};

#endif // DATABASEHANDLER_H
