/*
1. Write a short program that asks the user to enter a Celsius value and then
computes the equivalent Fahrenheit temperature. It should use a QInputDialog
*/
#include <QtWidgets>
#include <QApplication>
#include <QInputDialog>
#include <QString>

int ConvertToFahrenheit(int degress)
{
    return degress * 9.0/5.0 + 32;
}

int main (int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    int answer = 0;
    bool ok;
    do {

        double Celsius = QInputDialog::getDouble(0, "Enter Degrees Celsius", "Degrees: ", 0.00, -10000, 10000, 2, &ok);
        double Fahrenheit;
        if (ok)
        {
            Fahrenheit = ConvertToFahrenheit(Celsius);

            QString response = QString("%1 Degrees Celsius = %2 Degrees Fahrenheit").arg(Celsius).arg(Fahrenheit);
            answer = QMessageBox::question(0, "Calculate Again?", response, QMessageBox::Yes | QMessageBox::No);
        }
    } while (answer == QMessageBox::Yes && ok);

    cout << "Celsius\tFahrenheit" << endl;
    for (int i = 0; i <= 100; i+=5)
        cout << i << "\t" << ConvertToFahrenheit(i) << endl;



    return EXIT_SUCCESS;
}
