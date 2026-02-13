#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string ClientsFileName = "tagropah.txt";

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

vector<stClient> LoadCleintsDataFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientRecord(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void SearchInVector(vector<stClient> vClients , string TargetAccountNum)
{
    bool Found = false;
    for (stClient& i : vClients)
    {
        if (i.AccountNumber == TargetAccountNum)
        {
            PrintClientRecord(i);
            Found = true;
            break;
        }
    }
    if (!Found)
    {
        cout << "Client with Account Number (" << TargetAccountNum << ") is Not Found!\n";
    }
}

int main()
{
    string TargetAccountNum;
    vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    cout << "Enter Account Number to Search For?\n";
    cin >> TargetAccountNum;
    SearchInVector(vClients , TargetAccountNum);

    return 0;
}