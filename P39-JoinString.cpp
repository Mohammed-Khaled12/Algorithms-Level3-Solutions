#include <iostream>
#include <string>
#include <vector>
using namespace std;

string joinStrings(vector<string>& vString, string delim)
{
    string sentence = "";

    for (string &i : vString)
    {
        sentence += i + delim;
    }

    return sentence.substr(0 , sentence.length()-delim.length());
}
// Another Solution
// string joinStrings(vector<string>& vString, string delim)
// {
//     string sentence = "";
//     for (short i = 0; i < vString.size(); i++)
//     {
//         sentence += vString[i];
//         if (i < vString.size() - 1)
//         {
//             sentence += delim;
//         }
//     }
//     return sentence;
// }

int main()
{
    vector<string> vString = {"Mohammed", "Khaled"};
    cout << joinStrings(vString , " ");
    return 0;
}