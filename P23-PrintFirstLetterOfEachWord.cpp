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

void printFirstChar(string S1)
{
    bool isFirst = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirst)
        {
            cout << S1[i] << "\n";
        }
        isFirst = (S1[i] == ' ') ? true : false;
    }
}

int main()
{
    printFirstChar(readString());
    return 0;
}