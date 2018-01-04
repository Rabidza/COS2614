/*
1. Locate the code for Example 1.3 in the src tree and then
• Build and test that program with a variety of input values, including some
non-numeric values. DONE
• Determine the largest input value that can produce a valid output. DONE (17)
• Change the program so that it can produce valid results for larger input
values. (DONE IS unsigned long long correct?) (65 is now the largest number)
• Modify the program so that it cannot produce invalid results. (DONE if (nfact < 0 || n > 65) is this correct though???)
• Explore the effects of using the statement
if (cin >> n) { ... }
to enclose the processing of n in this program. In particular, try entering nonnumeric
data after the prompt. This is an example of the use of a conversion
operator, which is discussed in more detail in Section 19.9.1. (NOT DONE -- Not sure how to approach this one.)
• Modify the program so that it can accept values from the user until the
value 9999 is entered. (DONE with while loop)
 */

#include <iostream>

unsigned long long factorial(unsigned long long n)
{
    unsigned long long ans = 1;
    for (unsigned long long i = 2; i <= n; i++)
    {
        ans = ans * i;
        if (ans < 0)
        {
            return -1;
        }
    }

    return ans;
}

int main()
{
    using namespace std;
    cout << "Please enter n: " << flush;
    unsigned long long n;
    cin >> n;
    while (n != 9999)
    {
        if (n >= 0)
        {
            unsigned long long nfact = factorial(n);
            if (nfact < 0 || n > 65)
            {
                cerr << "overflow error: "
                     << n << " is too big." << endl;
            }
            else
            {
                cout << "factorial(" << n << ") = "
                     << nfact << endl;
            }
        }
        else
        {
            cerr << "Undefined: "
                 << "factorial of a negative number: " << n << endl;
        }

        cout << "Please enter n (9999 to quit): " << flush;
        cin >> n;
    }

    return 0;
}
