#include <iostream>
#include <string>
#include <vector>
using namespace std;

string joinStrings(vector<string> &vString, string delim)
{
    string sentence = "";

    for (string &i : vString)
    {
        sentence += i + delim;
    }

    return sentence.substr(0, sentence.length() - delim.length());
}

string joinStrings(string arr[], int length, string delim)
{
    string sentence = "";

    for (int i = 0; i < length; i++)
    {
        sentence += arr[i] + delim;
    }

    return sentence.substr(0, sentence.length() - delim.length());
}

int main()
{
    vector<string> vString = {"Mohammed", "Khaled"};
    string arr[] = {"Mohammed", "Khaled"};
    int arrLength = 2;
    cout << joinStrings(vString, " ") << "\n";
    cout << joinStrings(arr, arrLength, " ") << "\n";
    return 0;
}