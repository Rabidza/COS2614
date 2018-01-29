#ifndef QSTD_H
#define QSTD_H

#include <QTextStream>
#include <QString>
#include <QFile>

namespace qstd
{
    //declared but not defined:
    extern QTextStream cout;
    extern QTextStream cin;
    extern QTextStream cerr;

    //function declarations:
    bool yes(QString yesNoQuestion);
    bool more(QString prompt);
    int promptInt(int base = 10);
    double promptDouble();
    void promptOutputFile(QFile& outfile);
    void promptInputFile(Qfile& infile);
};

#endif // QSTD_H
