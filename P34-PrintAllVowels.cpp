#include <iostream>
using namespace std;

string readString()
{
    string S1;
    cout << "Please Enter a String\n";
    getline(cin, S1);
    return S1;
}

bool isVowel(char C1)
{
    C1 = toupper(C1);
    return (C1 == 'A' || C1 == 'E' || C1 == 'I' || C1 == 'O' || C1 == 'U');
}

void printVowels(string S1)
{
    cout << "Vowels in string are: ";
    for (int i = 0; i < S1.length(); i++)
    {
        if (isVowel(S1[i]))
        {
            cout << S1[i] << " ";
        }
    }
    cout << "\n";
}

int main()
{
    printVowels(readString());
    return 0;
}