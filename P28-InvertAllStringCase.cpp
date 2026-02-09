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

string invertString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            S1[i] = tolower(S1[i]);
        }
        else
        {
            S1[i] = toupper(S1[i]);
        }
    }

    return S1;
}

int main()
{
    string S1 = readString();
    cout << "After Invert: " << invertString(S1) << "\n";
    return 0;
}