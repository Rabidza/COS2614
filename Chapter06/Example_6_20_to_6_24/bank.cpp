#include <QDebug>
#include "bank.h"
#include "account.h"

Bank::~Bank()
{
    qDeleteAll(m_Accounts);
    m_Accounts.clear();
}

Bank& Bank::operator<< (Account* acct)
{
    m_Accounts << acct;
    return *this;
}

QString Bank::getAcctListing() const
{
    QString listing("\n");
    foreach(Account* acct, m_Accounts)
        listing += QString("%1\n").arg(acct->getName());
    return listing;
}

int main()
{
    QString listing;
    {
        Bank bnk;
        Account* a1 = new Account(1, 423, "Gene Kelly");
        JointAccount* a2 = new JointAccount(2, 1541, "Fred Astaire", "Ginger Rodgers");
        JointAccount* a3 = new JointAccount(*a1, "Leslie Caron");
        bnk << a1;
        bnk << a2;
        bnk << a3;
        JointAccount* a4 = new JointAccount(*a3);
        bnk << a4;
        listing = bnk.getAcctListing();
    }

    qDebug() << listing;
    qDebug() << "Now exit program";
}
