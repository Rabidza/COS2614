/*
Run the program excerpted in Example 1.11 as written and then
• Modify it so that it gets the filename from the user as an STL string fileName
before writing or reading. You need to use the function fileName.c_str() to
convert the string to a form acceptable to the open() function. Not sure...
• Modify it so that it makes sure that the file specified by the user does not already
exist (or that it is okay to overwrite if it does exist) before opening it for output.
• Explain what happens if you read the individual numbers with variables of
the wrong type (e.g., int instead of float or double ) in the “watch for errors”
section.
• Explain what happens if you read only with numerical variables and do not
use the newstr variable in the “watch for errors” block.
 */

#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
    using namespace std;
    ostringstream strbuf;

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;

    cout << "An in-memory stream" << endl;
    strbuf << "luckynumber: " << lucky << endl
           << "pi: " << pi << endl
           << "e: " << e << endl;

    string strval = strbuf.str();
    cout << strval;

    ofstream outf;
    string fileName;
    cout << "Enter an existing filename to overwrite: ";
    cin >> fileName;

    ifstream ifile(fileName);
    if (ifile)
    {
        outf.open(fileName.c_str());
        outf << strval;
        outf.close();
    }
    else
    {
        cout << "The file does not exist!";
    }

    return 0;
}
