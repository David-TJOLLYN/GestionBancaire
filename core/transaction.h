#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>

class Transaction : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString date READ date CONSTANT)
    Q_PROPERTY(QString amount READ amount CONSTANT)
    Q_PROPERTY(QString category READ category CONSTANT)
    Q_PROPERTY(QString details READ details CONSTANT)

public:
    explicit Transaction(QString _date, QString amount, QString category, QString account, QString details, QObject *parent = nullptr);
    Q_INVOKABLE QString toString();

    QString date(){return _date;}
    QString amount(){return _amount;}
    QString category(){return _category;}
    QString details(){return _details;}

private:
    QString _date;
    QString _category;
    QString _account;
    QString _amount;
    QString _details;
};

#endif // TRANSACTION_H
