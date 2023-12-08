#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include "databasehandler.h"

class Account : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString bank READ bank WRITE setBank NOTIFY bankChanged)
    Q_PROPERTY(float   sold READ sold NOTIFY soldChanged)
    Q_PROPERTY(int     type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(int id READ id CONSTANT)

public:
    explicit Account(int id, DatabaseHandler *bdd, QObject *parent = nullptr);
    Q_INVOKABLE QString toString();

    int id(){return _id.toInt();}
    QString name();
    QString number();
    QString bank();
    bool  type();
    float sold();

    void setName(QString name);
    void setType(int type);
    void setNumber(QString number);
    void setBank(QString bank);

public slots:
    void addTransaction(QString amount, QString date, QString category, QString details="");
    QVariantList getLastTransactions(int nbr);
    QVariantList transactions();

    QVariantList getMonthlySold(QString start, QString end, int type=0);
    QVariantList getMonthlyPositiveSold(QString start, QString end);
    QVariantList getMonthlyNegativeSold(QString start, QString end);

signals:
    void soldChanged();
    void nameChanged();
    void typeChanged();
    void numberChanged();
    void bankChanged();
    void updateLastTransaction();

public:
    DatabaseHandler *_bdd;
    QString _id;
};

#endif // ACCOUNT_H
