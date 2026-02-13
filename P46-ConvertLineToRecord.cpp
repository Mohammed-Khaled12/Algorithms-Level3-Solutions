#include <iostream>
#include <vector>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

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

stClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    stClient Client;

    vector<string> vClientData = split(Line, Seperator);

    Client.AccountNumber = vClientData.at(0);
    Client.PinCode = vClientData.at(1);
    Client.Name = vClientData.at(2);
    Client.Phone = vClientData.at(3);
    Client.AccountBalance = stod(vClientData.at(4));

    return Client;
}

void PrintClientRecord(stClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

int main()
{
    string Line;
    cout << "Enter Line Record\n";
    getline(cin, Line);

    stClient Client = ConvertLinetoRecord(Line, "#//#");
    PrintClientRecord(Client);

    return 0;
}