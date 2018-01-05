#include <iostream>
using namespace std;

double toCelsius(double fahrenheitTemp);
double toFahrenheit(double celsiusTemp);

int main()
{
    char choice;
    double ceclius;
    double fahrenheit;
    double degrees;

    cout << "Which unit do you want to convert from?" << endl
         << "(c)elsius or (f)ahrenheit: ";
    cin >> choice;

    choice = tolower(choice);
    if (choice == 'c')
    {
        cout << "Enter the degrees Celsius: ";
        cin >> degrees;
        cout << degrees << " degrees Celsius is equal to " << toFahrenheit(degrees) << " degress Fahrenheit" << endl;

    }
    else if (choice == 'f')
    {
        cout << "Enter the degrees Fahrenheit: ";
        cin >> degrees;
        cout << degrees << " degrees Fahrenheit is equal to " << toCelsius(degrees) << " degress Celsius" << endl;
    }
}

double toCelsius(double fahrenheitTemp)
{
    return (fahrenheitTemp - 32) * 5/9;

}

double toFahrenheit(double celsiusTemp)
{
    return (celsiusTemp * 9/5) + 32;
}
