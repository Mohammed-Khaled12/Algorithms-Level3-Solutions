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

int countChar(string S1, char C1)
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

int main()
{
    string S1 = readString();
    char C1 = readChar();

    cout << "Letter \'" << C1 << "\' Count = " << countChar(S1, C1);
    return 0;
}