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
    DatabaseHandler();

    QList<QString> getAllItems(const QString& tableName, const QString& columnName);
    QList<QMap<QString, QString>> getItemsWithColumns(const QString& tableName, const QStringList& columnNames);

    void insertTransaction(QString accountId, QString amount, QString date, QString categoryId, QString details);
    float getSold(QString accountId);

    QSqlQuery* getQuery(){return &_query;}
    bool queryExec(QString txt);

    void loadAccounts();
    QVariantList accounts();
    QVariantList getCategories();

    QString getCategorieId(QString name);
    QString getCategoryName(int id);
    QString getAccountId(QString name);
    QString getAccountName(int id);

public slots:
    void addAccount(QString name, QString number, QString bank, QString type);

signals:
    void updateSold(QString account, QString newSold);
    void accountsChanged();

private:
    QSqlDatabase _bdd;
    QSqlQuery _query;
    QList<Account*> _accounts;

    bool openDatabase();

    QString getCategoryInsertStatement();
    QString getAccountInsertStatement();

    void createGestionBancaire();
    void loadDefaultValues();
    void createDefaultTables();
};

#endif // DATABASEHANDLER_H
