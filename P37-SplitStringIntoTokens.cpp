#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString()
{
    string S1;
    cout << "Please Enter a String\n";
    getline(cin, S1);
    return S1;
}

vector<string> split(string S1, string delim)
{
    short pos = 0;
    string word;
    vector<string> vString;
    while ((pos = S1.find(delim)) != string::npos)
    {
        word = S1.substr(0, pos);
        if (word != "")
        {
            vString.push_back(word);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

int main()
{
    vector<string> vString = split(readString(), " ");
    cout << "Tokens: " << vString.size() << "\n";
    for (string &i : vString)
    {
        cout << i << "\n";
    }

    return 0;
}