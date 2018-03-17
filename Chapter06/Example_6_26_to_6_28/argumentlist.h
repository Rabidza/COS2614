#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H

#include <QStringList>

class ArgumentList : public QStringList
{
public:
    ArgumentList();
    ArgumentList(int argc, char* argv[])
    {
        argsToStringlist(argc, argv);
    }
    ArgumentList(const QStringList& argumentList)
        : QStringList(argumentList)
    {

    }
    bool getSwitch(QString option);
    QString getSwitchArg(QString option, QString defaultRetVal=QString());
private:
    void argsToStringlist(int argc, char* argv[]);
};

#endif // ARGUMENTLIST_H
