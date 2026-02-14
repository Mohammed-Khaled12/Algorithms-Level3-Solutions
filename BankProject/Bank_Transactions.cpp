#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

const string ClientsFileName = "bank.txt";

enum enMenuNumber
{
    Show = 1,
    Add,
    Delete,
    Update,
    Find,
    Transaction,
    Exit
};

enum enTransactionsMenuNumber
{
    Deposite = 1,
    Withdraw,
    TotalBalances,
    MainMenu,
};

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

enMenuNumber Start();

// Menu Design and Controll
void GoBackToMainMenu()
{
    // Using System Commends
    // cout << "\n\nPress any key to go back to Main Menu...";
    // cin.ignore(1000, '\n');
    // system("read -n 1 -s -p \"\"");

    // Using C++ , add <limits>
    cout << "\n\nPress Enter to go back To Main Menu...";
    cin.get();
}

void ShowMainMenu()
{
    cout << "======================================================\n";
    cout << "\t\t Main Menu Screen \n";
    cout << "======================================================\n";
    cout << "\t [1] Show Client List.\n";
    cout << "\t [2] Add New Client.\n";
    cout << "\t [3] Delete Client.\n";
    cout << "\t [4] Update Client Info.\n";
    cout << "\t [5] Find Client.\n";
    cout << "\t [6] Transaction.\n";
    cout << "\t [7] Exit.\n";
    cout << "======================================================\n";
    cout << "Choose What do you Want to do? [1 to 7]? \n";
}

void ShowTransactionMenu()
{
    cout << "======================================================\n";
    cout << "\t\t Transaction Menu Screen \n";
    cout << "======================================================\n";
    cout << "\t [1] Deposite.\n";
    cout << "\t [2] Withdraw.\n";
    cout << "\t [3] Total Balances.\n";
    cout << "\t [4] Main Menu.\n";
    cout << "======================================================\n";
    cout << "Choose What do you Want to do? [1 to 4]? \n";
}


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

vector<stClient> LoadCleintsDataFromFile()
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::in);
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

// Printing Section
void PrintClientRecord(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(const vector<stClient> &vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n\n";
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n\n";
    for (stClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n\n";
}

void PrintTotalBalancesClientRecord(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    // cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    // cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintTotalBalances(const vector<stClient> &vClients)
{
    double sum = 0;
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n\n";
    cout << "| " << left << setw(15) << "Accout Number";
    // cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    // cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n\n";
    for (stClient Client : vClients)
    {
        PrintTotalBalancesClientRecord(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n\n";
    for (const stClient &i : vClients)
    {
        sum += i.AccountBalance;
    }

    cout << "\t\t\t Total Balances = " << sum << "\n";
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

// Searching Section
bool IsClientExists(const vector<stClient> &vClients, string TargetAccountNum)
{
    for (const stClient &i : vClients)
    {
        if (i.AccountNumber == TargetAccountNum)
        {
            return true;
        }
    }
    return false;
}

bool FindClientByAccountNumber(string AccountNumber, const vector<stClient> &vClients, stClient &Client)
{
    for (const stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void FindClient(const vector<stClient> &vClients)
{
    string TargetNum;
    stClient Client;
    cout << "Please Enter Account Number To Search For? \n";
    getline(cin, TargetNum);

    if (FindClientByAccountNumber(TargetNum, vClients, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "Not Found\n";
    }
}

// Adding Section
stClient ReadNewClient()
{
    stClient newClient;
    vector<stClient> vClients = LoadCleintsDataFromFile();
    do
    {
        cout << "Enter Account Number?\n";
        getline(cin, newClient.AccountNumber);
        if (IsClientExists(vClients, newClient.AccountNumber))
        {
            cout << "Client with Account Number (" << newClient.AccountNumber << ") already Exists, Enter Another Number\n";
        }
    } while (IsClientExists(vClients, newClient.AccountNumber));

    cout << "Enter pinCode?\n";
    getline(cin, newClient.PinCode);

    cout << "Enter Name?\n";
    getline(cin, newClient.Name);

    cout << "Enter phone?\n";
    getline(cin, newClient.Phone);

    cout << "Enter Account Balance?\n";
    cin >> newClient.AccountBalance;

    cin.ignore(1000, '\n');

    return newClient;
}

void AddDataLineToFile(string dataLine)
{
    fstream MyFile;

    MyFile.open(ClientsFileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << dataLine << "\n";
        MyFile.close();
    }
}

void addNewClient()
{
    cout << "\nPlease Enter Client Data: \n\n";
    stClient Client = ReadNewClient();

    string dataLine = ConvertRecordToLine(Client);

    AddDataLineToFile(dataLine);
}

void addClients()
{
    char addMore;
    do
    {
        addNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> addMore;
        cin.ignore(1000, '\n');
    } while (toupper(addMore) == 'Y');
}

// Delete Section
bool ConfirmOP(string OP)
{
    char Confirm;
    cout << "Are You Sure You Want To " << OP << " This Client? Y/N\n";
    cin >> Confirm;

    cin.ignore(1000, '\n');
    return (toupper(Confirm) == 'Y');
}

void SaveClientsDataToFile(const vector<stClient> &vClients)
{
    fstream MyFile;
    MyFile.open(ClientsFileName, ios::out);

    if (MyFile.is_open())
    {
        for (const stClient &C : vClients)
        {
            MyFile << ConvertRecordToLine(C) << endl;
        }
        MyFile.close();
    }
}

void DeleteClientRecord(vector<stClient> &vClients, stClient ClientToDelete)
{
    for (int i = 0; i < vClients.size(); i++)
    {
        if (ClientToDelete.AccountNumber == vClients[i].AccountNumber)
        {
            vClients.erase(vClients.begin() + i);
            SaveClientsDataToFile(vClients);
            cout << "Deleted Succesfully\n";
            break;
        }
    }
}

void DeleteClient(vector<stClient> &vClients)
{
    string TargetNum;
    stClient Client;
    do
    {
        cout << "Enter Account Number To Delete?\n";
        getline(cin, TargetNum);
    } while (!IsClientExists(vClients, TargetNum));

    FindClientByAccountNumber(TargetNum, vClients, Client);
    PrintClientCard(Client);
    if (ConfirmOP("Delete"))
    {
        DeleteClientRecord(vClients, Client);
    }
}

// Update Section
void UpdateClientRecord(vector<stClient> &vClients, stClient &ClientToUpdate)
{
    cout << "\n\nEnter PinCode? ";
    getline(cin, ClientToUpdate.PinCode);

    cout << "Enter Name? ";
    getline(cin, ClientToUpdate.Name);

    cout << "Enter Phone? ";
    getline(cin, ClientToUpdate.Phone);

    cout << "Enter AccountBalance? ";
    cin >> ClientToUpdate.AccountBalance;
    cin.ignore(1000, '\n');
}

void UpdateClientByAccountNumber(vector<stClient> &vClients)
{
    string TargetNum;
    stClient Client;
    do
    {
        cout << "Enter Account Number To Update?\n";
        getline(cin, TargetNum);
    } while (!IsClientExists(vClients, TargetNum));
    FindClientByAccountNumber(TargetNum, vClients, Client);
    PrintClientCard(Client);
    if (ConfirmOP("Update"))
    {
        UpdateClientRecord(vClients, Client);
        for (stClient &C : vClients)
        {
            if (C.AccountNumber == TargetNum)
            {
                C = Client;
                break;
            }
        }
        SaveClientsDataToFile(vClients);
    }
}

// Deposite
void DepositeFunc(vector<stClient> &vClients)
{
    stClient Client;
    string TargetNum;
    double Amount;
    cout << "Enter Account Number? \n";
    getline(cin, TargetNum);
    while (!FindClientByAccountNumber(TargetNum, vClients, Client))
    {
        cout << "Wrong Number, Please Enter Account Number?\n";
        getline(cin, TargetNum);
    }
    PrintClientCard(Client);

    cout << "Please Enter Deposite Amount?\n";
    cin >> Amount;
    Client.AccountBalance += Amount;
    if (ConfirmOP("Deposite"))
    {
        for (stClient &i : vClients)
        {
            if (i.AccountNumber == TargetNum)
            {
                i = Client;
                SaveClientsDataToFile(vClients);
                cout << "\n\nDone Successfully. New balance is: " << Client.AccountBalance;
            }
        }
    }
}

// Withdraw
void WithdrawFunc(vector<stClient> &vClients)
{
    stClient Client;
    string TargetNum;
    double Amount;
    cout << "Enter Account Number? \n";
    getline(cin, TargetNum);
    while (!FindClientByAccountNumber(TargetNum, vClients, Client))
    {
        cout << "Wrong Number, Please Enter Account Number?\n";
        getline(cin, TargetNum);
    }
    PrintClientCard(Client);

    cout << "\nYour Current Balance is: " << Client.AccountBalance << endl;
    do
    {
        cout << "Please Enter Withdraw Amount? ";
        cin >> Amount;
        if (Amount > Client.AccountBalance)
            cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
    } while (Amount > Client.AccountBalance);

    Client.AccountBalance -= Amount;
    if (ConfirmOP("Withdraw"))
    {
        for (stClient &i : vClients)
        {
            if (i.AccountNumber == TargetNum)
            {
                i = Client;
                SaveClientsDataToFile(vClients);
                cout << "\n\nDone Successfully. New balance is: " << Client.AccountBalance;
            }
        }
    }
}

// Transactions Manger
void TransactionsManger(vector<stClient> &vClients)
{
    short TransChoice;
    ShowTransactionMenu();
    cin >> TransChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    enTransactionsMenuNumber TransNum = static_cast<enTransactionsMenuNumber>(TransChoice);
    switch (TransNum)
    {
    case enTransactionsMenuNumber::Deposite:
        system("clear");
        DepositeFunc(vClients);
        GoBackToMainMenu();
        break;
    case enTransactionsMenuNumber::Withdraw:
        system("clear");
        WithdrawFunc(vClients);
        GoBackToMainMenu();
        break;
    case enTransactionsMenuNumber::TotalBalances:
        system("clear");
        PrintTotalBalances(vClients);
        GoBackToMainMenu();
        break;
    case enTransactionsMenuNumber::MainMenu:
        system("clear");
        return;

    default:
        break;
    }
}

// Start And End
void EndScreen()
{
    system("clear");
    cout << "======================================================\n";
    cout << "\t Program Ends :-)\n";
    cout << "======================================================\n\n";
}

enMenuNumber Start()
{
    short Choice;
    ShowMainMenu();
    cin >> Choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    enMenuNumber MenuOption = static_cast<enMenuNumber>(Choice);
    vector<stClient> vClients = LoadCleintsDataFromFile();
    switch (MenuOption)
    {
    case enMenuNumber::Show:
        system("clear");
        cout << "--- Show Client List Screen ---\n";
        PrintAllClientsData(vClients);
        GoBackToMainMenu();
        break;
    case enMenuNumber::Add:
        system("clear");
        cout << "--- Add Client Screen ---\n";
        addClients();
        GoBackToMainMenu();
        break;
    case enMenuNumber::Delete:
        system("clear");
        cout << "--- Delete Client Screen ---\n";
        DeleteClient(vClients);
        GoBackToMainMenu();
        break;
    case enMenuNumber::Update:
        system("clear");
        cout << "--- Update Client Screen ---\n";
        UpdateClientByAccountNumber(vClients);
        GoBackToMainMenu();
        break;
    case enMenuNumber::Find:
        system("clear");
        cout << "--- Find Client Screen ---\n";
        FindClient(vClients);
        GoBackToMainMenu();

        break;
    case enMenuNumber::Transaction:
        system("clear");
        ;
        TransactionsManger(vClients);
        break;
    case enMenuNumber::Exit:
        EndScreen();
        break;

    default:
        break;
    }
    return MenuOption;
}

void StartProgram()
{
    enMenuNumber Choice;
    while (Choice != enMenuNumber::Exit)
    {
        system("clear");
        Choice = Start();
    }
}

int main()
{
    StartProgram();

    return 0;
}