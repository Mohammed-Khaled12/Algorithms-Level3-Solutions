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

string trimLift(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            S1 = S1.substr(i, S1.length());
            return S1;
        }
    }

    return S1;
}

string trimRight(string S1)
{
    for (int i = S1.length() - 1; i > 0; i--)
    {
        if (S1[i] != ' ')
        {
            S1 = S1.substr(0, i + 1);
            return S1;
        }
    }

    return S1;
}

string Trim(string S1)
{
    return (trimLift(trimRight(S1)));
}

int main()
{
    string S1 = readString();
    cout << Trim(S1);
    return 0;
}