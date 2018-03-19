#include <QTextStream>
#include <QDebug>
#include "person.h"
#include <QDebug>

static QTextStream cout(stdout);

void growBunch()
{
    qDebug() << "First we create a bunch of objects." << endl;
    QObject bunch;
    bunch.setObjectName("A Stack Object");
    /*other objects are created on the heap */
    Person* mike = new Person("Mike", &bunch);
    Person* carol = new Person("Carol", &bunch);
    new Person("Greg", mike);
    new Person("Peter", mike);
    new Person("Bobby", mike);
    new Person("Marcia", carol);
    new Person("Jan", carol);
    new Person("Cindy", carol);
    new Person("Alice");
    qDebug() << "\nDisplay the list using QObject::dumpObjectTree()"
             << endl;
    bunch.dumpObjectTree();
    cout << "\nReady to return from growBunch() -"
         << " Destroy all local stack ojects." << endl;

}

int main(int , char**)
{
    growBunch();
    cout << "We have now returned from growBunch()."
         <<  "\nWhat happened to Alice?" << endl;

    return 0;
}
