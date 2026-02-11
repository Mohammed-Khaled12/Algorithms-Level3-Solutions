#include <iostream>
#include <string>
using namespace std;

string RemovePunctuationsFromString(string S1)
{
    string S2 = "";
    for (int i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    cout << RemovePunctuationsFromString(S1);

    return 0;
}