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

int countEachWordInString(string S1)
{
    short pos = 0;
    string delim = " ";
    string word;
    int counter = 0;
    while ((pos = S1.find(delim)) != string::npos)
    {
        word = S1.substr(0, pos);
        if (word != "")
        {
            counter++;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        counter++;
    }

    return counter;
}

int main()
{
    string S1 = readString();
    cout << "The number of words in your string is: " << countEachWordInString(S1) << "\n";
    return 0;
}