#include <iostream>
using namespace std;

string readString()
{
    string S1;
    cout << "Please Enter a String\n";
    getline(cin, S1);
    return S1;
}

void printEachWordInString(string S1)
{
    cout << "Your String Words are: \n";
    short pos = 0;
    string delim = " ";
    string Word;
    while ((pos = S1.find(delim)) != string::npos)
    {
        Word = S1.substr(0, pos);
        if (Word != "")
        {
            cout << Word << "\n";
        }
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        cout << S1 << "\n";
    }
}

int main()
{
    printEachWordInString(readString());
    return 0;
}