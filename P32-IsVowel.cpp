#include <iostream>
using namespace std;

char readChar()
{
    char C1;
    cout << "Please Enter a Character\n";
    cin >> C1;
    return C1;
}

bool isVowel(char C1)
{
    char C1Upper = toupper(C1);
    if (C1Upper == 'A' || C1Upper == 'E' || C1Upper == 'I' || C1Upper == 'O' || C1Upper == 'U')
    {
        return true;
    }
    return false;
}

// more Clean Method
// bool isVowel(char C1)
// {
//     C1 = toupper(C1);
//     return (C1 == 'A' || C1 == 'E' || C1 == 'I' || C1 == 'O' || C1 == 'U');
// }

int main()
{
    if (isVowel(readChar()))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}