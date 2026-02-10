#include <iostream>
#include <string>
using namespace std;

string readString()
{
    string S1;
    cout << "Please Enter a String\n";
    getline(cin, S1);
    return S1;
}

char readChar()
{
    char C1;
    cout << "Please Enter a Character\n";
    cin >> C1;
    return C1;
}

int countCharMatchCase(string S1, char C1)
{
    int charCounter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] == C1)
        {
            charCounter++;
        }
    }
    return charCounter;
}

int countCharIgnoreCase(string S1, char C1)
{
    int charCounter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (toupper(S1[i]) == C1 || tolower(S1[i]) == C1)
        {
            charCounter++;
        }
    }
    return charCounter;
}

// anthor Method
// int countCharIgnoreCase(string S1, char C1)
// {
//     int charCounter = 0;
//     char lowerC1 = tolower(C1);

//     for (int i = 0; i < S1.length(); i++)
//     {
//         if (tolower(S1[i]) == lowerC1)
//         {
//             charCounter++;
//         }
//     }
//     return charCounter;
// }

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
    string S1 = readString();
    char C1 = readChar();

    cout << "Letter \'" << C1 << "\' Count = " << countCharMatchCase(S1, C1) << "\n";
    cout << "Letter \'" << C1 << "\' Or Letter \'" << invertChar(C1) << "\' Count = " << countCharIgnoreCase(S1, C1) << "\n";
    return 0;
}