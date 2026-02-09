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

string UpperAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

string LowerAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = readString();
    cout << UpperAllString(S1) << "\n";
    cout << LowerAllString(S1) << "\n";
    return 0;
}