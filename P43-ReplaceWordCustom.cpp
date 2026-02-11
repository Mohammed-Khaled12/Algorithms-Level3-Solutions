#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString(string msg)
{
    string S1;
    cout << msg << "\n";
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

string UpperAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

string joinStrings(vector<string> &vString, string delim)
{
    string sentence = "";

    for (string &i : vString)
    {
        sentence += i + delim;
    }

    return sentence.substr(0, sentence.length() - delim.length());
}

string ReplaceWordInString(string S1, string word, string replaceTo, bool matchCase = 1)
{
    vector<string> vString = split(S1, " ");
    for (auto &&s : vString)
    {
        if (matchCase)
        {
            if (s == word)
            {
                s = replaceTo;
            }
        }
        else
        {
            if (UpperAllString(s) == UpperAllString(word))
            {
                s = replaceTo;
            }
        }
    }
    S1 = joinStrings(vString, " ");
    return S1;
}

int main()
{
    bool matchCase;
    string S1 = readString("Please Enter a String");
    string word = readString("Enter a Word To Replace");
    string replaceTo = readString("Replace To ?");
    cout << "Do you Want to Match Case ? [1][0] \n";
    cin >> matchCase;

    cout << ReplaceWordInString(S1, word, replaceTo, matchCase);


    return 0;
}