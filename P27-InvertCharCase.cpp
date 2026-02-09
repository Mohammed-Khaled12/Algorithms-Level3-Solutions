#include <iostream>
#include <string>
using namespace std;

char readChar()
{
    char C1;
    cout << "Please Enter a Character\n";
    cin >> C1;
    return C1;
}

char invertChar(char C1)
{
    if (isupper(C1))
    {
        C1 = C1 + 32;
    }
    else
    {
        C1 = C1 - 32;
    }

    return C1;
}

int main()
{
    char C1 = readChar();
    cout << "After Invert: " << invertChar(C1) << "\n";
    return 0;
}