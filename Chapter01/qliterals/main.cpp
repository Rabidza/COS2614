#include <QTextStream>
#include <QString>

int main()
{
    const char* charstr = "This is one very long string "
            " so I will continue it on the next line";
    QTextStream cout(stdout);
    QString str = charstr;
    cout << str << endl;
    cout << "\nA\tb\\c\'d\"" << endl;

    return 0;
}
