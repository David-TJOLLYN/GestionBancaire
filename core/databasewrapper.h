#ifndef DATABASEWRAPPER_H
#define DATABASEWRAPPER_H

#include <QObject>
#include "databasehandler.h"
#include "account.h"

class DatabaseWrapper : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseWrapper(QObject *parent = nullptr);

    DatabaseHandler* handler(){return _wrapper;}

    QVariantList getAccounts();
    QVariantList getCategories();

public slots:
    void insertTransaction(QString account, QString amount, QString category, QString details);
    float getTotalSold();

signals:

private:
    QSqlQuery       *_query;
    DatabaseHandler *_wrapper;
    QList<Account*>  _accounts;

    void loadAccounts();
};

#endif // DATABASEWRAPPER_H
