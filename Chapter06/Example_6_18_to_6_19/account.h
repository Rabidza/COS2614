#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDate>

class Account{
public:
    Account(unsigned acctno, double bal, QString Owner);
    virtual ~Account(){}
    virtual void deposit(double amt);
    virtual QString toString() const;
    virtual QString toString(char delimiter);
protected:
    unsigned m_AcctNo;
    double m_Balance;
    QString m_Owner;
};

class InsecureAccount : public Account
{
public:
    InsecureAccount(unsigned acctno, double bal, QString owner);
    QString toString() const;
    void deposit(double amt, QDate postDate);
};

#endif // ACCOUNT_H
