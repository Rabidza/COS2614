#include <QDate>
#include <QDebug>
#include <limits.h>

#include "testassertequals.h"

void TestAssertEquals::test()
{
    // Example 8.6
    qDebug() << "Testing bools";
    bool boolvalue = true;
    QVERIFY(1);
    QVERIFY(true);
    QVERIFY(boolvalue);
    qDebug() << QString("We are in file: %1 Line: %2").arg(__FILE__).arg(__LINE__);
    QCOMPARE(boolvalue, true);

    // Example 8.7
    qDebug() << "Testing QStrings";
    QString string1 = "apples";
    QString string2 = "oranges";
    QString string3 = "apples";
    QCOMPARE("apples", "apples");
    QCOMPARE(string1, QString("apples"));
    QCOMPARE(QString("oranges"), string2);
    QCOMPARE(string1, string3);
    QVERIFY(string2 != string3);

    // Example 8.8
    qDebug() << "Testing QDates";
    QString datestr("2010-11-21");
    QDate dateobj = QDate::fromString(datestr, Qt::ISODate);
    QVERIFY(dateobj.isValid());
    QVariant variant(dateobj);
    QString message(QString("comparing datestr: %1 dateobj: %2 variant: %3")
            .arg(datestr).arg(dateobj.toString()).arg(variant.toString()));
    qDebug() << message;
    QCOMPARE(variant, QVariant(dateobj));
    QCOMPARE(QVariant(dateobj), variant);
    QCOMPARE(variant.toString(), datestr);
    QCOMPARE(datestr, variant.toString());
    QEXPECT_FAIL("","Keep going!", Continue);
    QCOMPARE(datestr, dateobj.toString());

    // Example 8.9
    qDebug() << "Testing ints and doubles";
    int i = 4;
    QCOMPARE (4, i);
    uint u(LONG_MAX + 1), v (u / 2);
    QCOMPARE(u, v * 2);
    double d(2. / 3.), e (d / 2);
    QVERIFY(d != e);
    QVERIFY(d == e*2);
    double f(1./3.);
    QEXPECT_FAIL("","Keep going!", Continue);
    QVERIFY(f * 3 == 2);
    qDebug() << "Testing pointers";
    void *nullpointer = 0;
    void *nonnullpointer = &d;
    QVERIFY(nullpointer != 0);
    qDebug() << "There is one more item left in the test.";
    QVERIFY(nonnullpointer != 0);

}

// Generate a main program
QTEST_MAIN(TestAssertEquals)
