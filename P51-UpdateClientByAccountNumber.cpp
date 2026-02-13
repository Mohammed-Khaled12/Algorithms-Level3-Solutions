#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <string>
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

bool ConfirmUpdate()
{
    char Confirm;
    cout << "Are You Sure You Want To Update This Client? Y/N\n";
    cin >> Confirm;

    cin.ignore(1000, '\n');

    return (toupper(Confirm) == 'Y');
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string clientRecord = "";

    clientRecord += Client.AccountNumber + Seperator;
    clientRecord += Client.PinCode + Seperator;
    clientRecord += Client.Name + Seperator;
    clientRecord += Client.Phone + Seperator;
    clientRecord += to_string(Client.AccountBalance);

    return clientRecord;
}

void SaveClientsDataToFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (stClient& C : vClients)
        {
            MyFile << ConvertRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}

void UpdateClientRecord(vector<stClient>& vClients, stClient ClientToUpdate)
{
    for (int i = 0; i < vClients.size(); i++)
    {
        if (ClientToUpdate.AccountNumber == vClients[i].AccountNumber)
        {
            cout << "Enter PinCode?\n";
            getline(cin, vClients[i].PinCode);
            cout << "Enter Name?\n";
            getline(cin, vClients[i].Name);
            cout << "Enter Phone?\n";
            getline(cin, vClients[i].Phone);
            cout << "Enter Account Balance?\n";
            cin >> vClients[i].AccountBalance;

            cin.ignore(1000, '\n');


            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "Updated Succesfully\n";
            break;
        }
    }

}

void SearchInVector(vector<stClient>& vClients, string TargetAccountNum)
{
    bool Found = false;
    for (stClient& i : vClients)
    {
        if (i.AccountNumber == TargetAccountNum)
        {
            PrintClientRecord(i);
            Found = true;

            if (ConfirmUpdate())
            {
                UpdateClientRecord(vClients, i);
            }

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
    cout << "Enter Account Number? \n";
    cin >> TargetAccountNum;
    SearchInVector(vClients, TargetAccountNum);

    return 0;
}