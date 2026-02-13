#include <iostream>
#include <string>
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

int main()
{
    cout << "\nPlease Enter Client Data: \n\n";
    stClient Client;
    Client = ReadNewClient();
    cout << "\n\nClient Record for Saving is: \n";
    cout << ConvertRecordToLine(Client);
    return 0;
}