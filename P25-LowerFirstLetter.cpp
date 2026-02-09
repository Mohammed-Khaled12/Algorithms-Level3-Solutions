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

void LowerFirstLetterOfEachWord(string S1)
{
    bool isFirst = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirst)
        {
            S1[i] = tolower(S1[i]);
            isFirst = false;
        }
        else if (S1[i] == ' ')
        {
            isFirst = true;
        }
    }
    cout << "String After: \n";
    cout << S1;
}

int main()
{
    LowerFirstLetterOfEachWord(readString());
    return 0;
}