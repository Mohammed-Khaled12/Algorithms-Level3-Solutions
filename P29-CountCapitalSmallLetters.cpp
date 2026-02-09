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

int countCapital(string S1)
{
    int capitalCounter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            capitalCounter++;
        }
        
    }
    return capitalCounter;
}

int countSmall(string S1)
{
    int smallCounter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            smallCounter++;
        }
        
    }
    return smallCounter;
}

int main()
{
    string S1 = readString();
    cout << "String Length = " << S1.length() << "\n";
    cout << "Capital Letters Count= " << countCapital(S1) << "\n";
    cout << "Small Letters Count= " << countSmall(S1) << "\n";
    return 0;
}

/*
    Anthor Solution (Better Just one loop)
struct stStringCounts {
    int CapitalCount = 0;
    int SmallCount = 0;
};

stStringCounts countLetters(string S1) {
    stStringCounts Counts;
    for (int i = 0; i < S1.length(); i++) {
        if (isupper(S1[i])) Counts.CapitalCount++;
        else if (islower(S1[i])) Counts.SmallCount++;
    }
    return Counts;
}
    */