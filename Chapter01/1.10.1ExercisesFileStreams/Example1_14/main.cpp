/*
Run the program excerpted in Example 1.11 as written and then
• Modify it so that it gets the filename from the user as an STL string fileName
before writing or reading. You need to use the function fileName.c_str() to
convert the string to a form acceptable to the open() function. DONE??
• Modify it so that it makes sure that the file specified by the user does not already
exist (or that it is okay to overwrite if it does exist) before opening it for output.
• Explain what happens if you read the individual numbers with variables of
the wrong type (e.g., int instead of float or double ) in the “watch for errors”
section.
• Explain what happens if you read only with numerical variables and do not
use the newstr variable in the “watch for errors” block.
 */

#include <QTextStream>
#include <QString>
#include <QFile>

QTextStream cout(stdout);
QTextStream cerr(stderr);
QTextStream cin(stdin);

int main()
{
    QString str, newstr;
    QTextStream strbuf(&str);

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;

    cout << "An in-memory stream" << endl;
    strbuf << "luckynumber: " << lucky << endl
           << "pi: " << pi << endl
           << "e: " << e << endl;

    cout << str;
    QString fileName;
    cout << "Enter an existing filename to overwrite: " << endl;
    cin >> fileName;
    QFile data(fileName);
    cout << "The fileName you entered is: " << fileName << endl;

    //QFile data("mydata");
    data.open(QIODevice::WriteOnly);
    QTextStream out(&data);
    out << str;
    data.close();

    cout << "Read data from the file - watch for errors" << endl;
    if (data.open(QIODevice::ReadOnly))
    {
        QTextStream in(&data);
        int lucky2;
        in >> newstr >> lucky2;
        if (lucky != lucky2)
            cerr << "ERROR! wrong " << newstr << lucky2 << endl;
        else
            cout << newstr << " OK" << endl;

        float pi2;
        in >> newstr >> pi2;
        if (pi2 != pi)
            cerr << "ERROR! wrong " << newstr << pi2 << endl;
        else
            cout << newstr << " OK" << endl;

        double e2;
        in >> newstr >> e2;
        if (e2 != e)
            cerr << "ERROR! wrong " << newstr << e2 << endl;
        else
            cout << newstr << " OK" << endl;

        data.close();
    }

    cout << "Read from file line-by-line" << endl;
    if (data.open(QIODevice::ReadOnly))
    {
        QTextStream in (&data);
        while (not in.atEnd())
        {
            newstr = in.readLine();
            cout << newstr << endl;
        }
        data.close();
    }

    return 0;
}
