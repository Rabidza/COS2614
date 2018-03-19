#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>

class Person : public QObject
{
public:
    explicit Person(QString name, QObject* parent = 0);
    virtual ~Person();
};

#endif // PERSON_H
