#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include "databasehandler.h"

class Account : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(float sold READ sold WRITE setSold NOTIFY soldChanged)
    Q_PROPERTY(QString number READ number CONSTANT)

public:
    explicit Account(QString name, float sold, QString number, DatabaseHandler *bdd, QObject *parent = nullptr);
    Q_INVOKABLE QString toString();

    QString name(){return _name;}
    float sold(){return _sold;}
    QString number(){return _number;}

    void setSold(float sold);

public slots:
    void addTransaction(QString amount, QString category, QString details);
    QVariantList getMonthlyEvolution(QString start, QString end);
    QVariantList getLastTransactions(int nbr);

signals:
    void soldChanged();
    void updateLastTransaction();

public:
    DatabaseHandler *_bdd;

    QString _name;
    QString _id;
    float _sold;
    QString _number;
};

#endif // ACCOUNT_H
