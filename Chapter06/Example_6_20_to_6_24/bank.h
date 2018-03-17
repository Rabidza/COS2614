#ifndef BANK_H
#define BANK_H

#include <QString>
#include <QList>

class Account;

class Bank
{
public:
    Bank& operator<< (Account* acct);
    ~Bank();
    QString getAcctListing() const;
private:
    QList<Account*> m_Accounts;
};

#endif // BANK_H
