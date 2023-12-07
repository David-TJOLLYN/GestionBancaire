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
    Q_PROPERTY(QVariantList categories READ categories NOTIFY categoriesChanged FINAL)
    Q_PROPERTY(QVariantList banks READ banks NOTIFY banksChanged FINAL)

public:
    DatabaseHandler(bool *status);

    void insertTransaction(QString accountId, QString amount, QString date, QString categoryId, QString details);

    bool exec(QSqlQuery *query);

    QVariantList accounts();
    QVariantList categories();
    QVariantList banks();

    QString getCategorieId(QString name);
    QString getAccountId(QString name);
    QString getBankId(QString name);

public slots:
    bool addAccount(QString name, QString number, QString bank, QString type);
    bool addCategory(QString name);
    bool addBank(QString name);
    QVariant account(int id);

signals:
    void accountsChanged();
    void categoriesChanged();
    void banksChanged();

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
