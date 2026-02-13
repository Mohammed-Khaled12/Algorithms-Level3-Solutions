#include <iostream>
#include <fstream>
using namespace std;

struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

stClient ReadNewClient()
{
    stClient newClient;
    cout << "Enter Account Number?\n";
    getline(cin, newClient.accountNumber);

    cout << "Enter pinCode?\n";
    getline(cin, newClient.pinCode);

    cout << "Enter Name?\n";
    getline(cin, newClient.name);

    cout << "Enter phone?\n";
    getline(cin, newClient.phone);

    cout << "Enter Account Balance?\n";
    cin >> newClient.accountBalance;

    // Discard the newline character left in the buffer by 'cin'
    // to prevent subsequent 'getline' calls from skipping input.
    cin.ignore(1000, '\n');

    return newClient;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string clientRecord = "";

    clientRecord += Client.accountNumber + Seperator;
    clientRecord += Client.pinCode + Seperator;
    clientRecord += Client.name + Seperator;
    clientRecord += Client.phone + Seperator;
    clientRecord += to_string(Client.accountBalance);

    return clientRecord;
}

void AddDataLineToFile(string fileName, string dataLine)
{
    fstream MyFile;

    MyFile.open(fileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << dataLine << "\n";
        MyFile.close();
    }
}

void addNewClient()
{
    string fileName;
    cout << "\nPlease Enter Client Data: \n\n";
    stClient Client = ReadNewClient();

    string dataLine = ConvertRecordToLine(Client);

    cout << "Please Enter File Name\n";
    getline(cin, fileName);

    AddDataLineToFile(fileName, dataLine);
}

void addClients()
{
    char addMore;
    do
    {
        addNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> addMore;
    } while (toupper(addMore) == 'Y');
}

int main()
{
    addClients();
    return 0;
}