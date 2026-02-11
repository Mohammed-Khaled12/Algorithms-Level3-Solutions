#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string S1, string word, string replaceTo)
{
    short pos = S1.find(word);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, word.length(), replaceTo);
        pos = S1.find(word);
    }

    return S1;
}

int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "Jordan";
    string ReplaceTo = "USA";
    cout << "\nOrigial String\n" << S1;
    cout << "\n\nString After Replace:" ;
    cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(S1,StringToReplace, ReplaceTo);

    return 0;
}