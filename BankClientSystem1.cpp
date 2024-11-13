/// _______________________ Project 1 ___________________________
// Subject : Bank 1

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
const string BankFileName = "BankClientFile.txt";

enum enOperation {eList=1, eNew=2, eDelete=3, eUpdate=4, eFind=5, eExit=6};

struct stClients {
	string AccountNumber;
	int PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

string ReadString(string Message) {
	string Sentence;
	cout << Message;
	getline(cin >> ws, Sentence);
	return Sentence;
}

char ReadChar(string Message) {
	char Character;
	cout << Message;
	cin >> Character;
	cin.ignore(0, '\n');
	return Character;
}

short ReadNumberBetween(string Message, short From, short To) {
	short Num = 0;
	do {
		cout << Message;
		cin >> Num;
	} while (Num < From || Num > To);
	cin.ignore(0, '\n');

	return Num;
}

string Tabs(short Num) {
	string tabs = "";
	for (short i = 0; i < Num; i++) {
		tabs += "\t";
	}
	return tabs;
}

void PrintClientCard(stClients C) {
	cout << "\n----------------------------------";
	cout << "\nAccount Number  : " << C.AccountNumber;
	cout << "\nPin Code        : " << C.PinCode;
	cout << "\nName            : " << C.Name;
	cout << "\nPhone           : " << C.Phone;
	cout << "\nAccount Balance : " << C.AccountBalance;
	cout << "\n----------------------------------" << endl;
}

bool SearchIfAccountNumberInFile(vector<stClients> &vClients, string AccountNumber, stClients& Client, bool Delete = false) {
	for (stClients& C : vClients) {
		if (C.AccountNumber == AccountNumber) {

			Client = C;

			if (Delete == true) {
				C.MarkForDelete = true;
			}

			return true;

		}
	}
	return false;
}

stClients ReadClientInformations(vector<stClients> &vClient, bool WithAccountNumber = true) {
	stClients Client;
	
	if (WithAccountNumber) {
		cout << "Enter Account Number? ";
			cin >> Client.AccountNumber;

			while (SearchIfAccountNumberInFile(vClient, Client.AccountNumber, Client)) {
				cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
				cin >> Client.AccountNumber;
			};
	}
	
	cout << "Enter Pin Code? ";
	cin >> Client.PinCode;

	cout << "Enter Name? ";
	getline(cin >> ws, Client.Name);

	cout << "Enter Phone? ";
	cin >> Client.Phone;

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

vector<string> SplitString(string Line, string Delim) {
	short pos;
	vector<string> vString;
	string sWord = "";
	
	while ((pos = Line.find(Delim)) != std::string::npos) {
		sWord = Line.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		Line.erase(0, pos + Delim.length());
	}
	if (Line != "") {
		vString.push_back(Line);
	}
	return vString;
}

stClients ConvertLineToRecord(string Line, string Seperator) {
	stClients Client;
	vector<string> vString = SplitString(Line, Seperator);

	Client.AccountNumber = vString[0];
	Client.PinCode = stoi(vString[1]);
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stod(vString[4]);

	return Client;
}

string ConvertRecordToLine(stClients Client, string Seperator) {
	string Line = "";

	Line += Client.AccountNumber + Seperator;
	Line += to_string(Client.PinCode) + Seperator;
	Line += Client.Name + Seperator;
	Line += Client.Phone + Seperator;
	Line += to_string(Client.AccountBalance);

	return Line;
}

void SaveClientDataToFile(vector<stClients> & vClient, string FileName) {
	fstream MyFile;
	string Line = "";
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		for (stClients& C : vClient) {

			if (!C.MarkForDelete) {
				Line = ConvertRecordToLine(C, "#//#");
				MyFile << Line << endl;
			}

		}
		MyFile.close();
	}
}

vector<stClients> LoadClientDataFromFile(string FileName) {
	vector<stClients> vClients;
	fstream MyFile;
	string Line = "";
	stClients Client;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line, "#//#");
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

void DeleteClientByAccountNumber(vector<stClients> vClient) {
	stClients Client;
	char isSure = 'n';
	string AccountNumber = "";
	cout << "\n\nPlease enter Account Number? " << endl;
	cin >> AccountNumber;

	while (!SearchIfAccountNumberInFile(vClient, AccountNumber, Client, true)) {
		cout << "Account Number [" << AccountNumber << "] is Not exists, Please Enter another Number? ";
		cin >> AccountNumber;
	}
	cout << "\nThe following are the client details: ";
	PrintClientCard(Client);

	cout << "\n\n\nAre You sure you want to delete this client? y/n ?";
	cin >> isSure;
	if (tolower(isSure) == 'y') {
		SaveClientDataToFile(vClient, BankFileName);

		cout << "\n\n\nClient Deleted Successfully!  " << endl;
	}
}

void AddClient(string FileName, stClients AddClient) {
	fstream MyFile;
	string Line = "";

	MyFile.open(FileName, ios::in | ios::app);

	if (MyFile.is_open()) {
		Line = ConvertRecordToLine(AddClient, "#//#");
		MyFile << Line << endl;

		MyFile.close();
	}
}

void AddClients() {
	char PlayAgain = 'y';
	stClients Client;
	vector<stClients> vClients = LoadClientDataFromFile(BankFileName);

	cout << "Adding New Clients: \n\n";
	
	while (tolower(PlayAgain) == 'y') {
		Client = ReadClientInformations(vClients);
		AddClient(BankFileName, Client);

		cout << "\n\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> PlayAgain;
	}
}

void UpdateClient(vector<stClients> vClients) {
	char Char = 'n';
	string AccountNumber = "";


	cout << "\nPlease Enter Account Number? ";
	cin >> AccountNumber;

	for (stClients& C : vClients) {
		if (AccountNumber == C.AccountNumber) {
			
			cout << "The following are the client details: \n";
			PrintClientCard(C);

			cout << "\n\n\nAre you sure you want update this client? y/n ? ";
			cin >> Char;
			if (tolower(Char) == 'y') {
				cout << "\n\n\n";
				C = ReadClientInformations(vClients, false);
				C.AccountNumber = AccountNumber;
				cout << "\n\nClient Updated Successfully. " << endl;
				break;
			}
		}
	}

	SaveClientDataToFile(vClients, BankFileName);
	
}

void FindClient(vector<stClients> vClients) {
	string AccountNumber = "";
	stClients Client;

	cout << "\nPlease Enter Account Number? ";
	cin >> AccountNumber;

	while (!SearchIfAccountNumberInFile(vClients, AccountNumber, Client)) {
		cout << "Account Number [" << AccountNumber << "] is Not exists, Please Enter another Number? ";
		cin >> AccountNumber;
	}

	cout << "The following are the client details: \n";
	PrintClientCard(Client);
}

void GoBackToMainMenu() {
	cout << "\n\n\nPress any key to go back to Main Menu...";
	system("pause > 0");
}

void PrintMainMenuScreen() {
	cout << "==============================================\n";
	cout << Tabs(2) << "Main Menu Screen\n";
	cout << "==============================================\n";
	cout << Tabs(1) << "[1] Show Client List. \n";
	cout << Tabs(1) << "[2] Add New Client. \n";
	cout << Tabs(1) << "[3] Delete Client. \n";
	cout << Tabs(1) << "[4] Update Client Info. \n";
	cout << Tabs(1) << "[5] Find Client. \n";
	cout << Tabs(1) << "[6] Exit. \n";
	cout << "==============================================" << endl;
}

void PrintClientList(vector<stClients> vClients) {
	for (stClients& Client : vClients) {

		cout << "|=| " << setw(17) << left << Client.AccountNumber;
		cout << "|=| " << setw(15) << left << Client.PinCode;
		cout << "|=| " << setw(26) << left << Client.Name;
		cout << "|=| " << setw(17) << left << Client.Phone;
		cout << "|=| " << setw(10) << left << Client.AccountBalance;
		cout << endl;
	}
}

void PrintListScreen() {
	system("cls");
	vector<stClients> vClients = LoadClientDataFromFile(BankFileName);

	cout << Tabs(4) << "Client List (" << vClients.size() << ") Clients(s).\n";
	cout << "________________________________________________________________________________________________________\n\n";
	cout << "|=| " << setw(17) << left << "Account Number";
	cout << "|=| " << setw(15) << left << "Pin Code";
	cout << "|=| " << setw(26) << left << "Client Name";
	cout << "|=| " << setw(17) << left << "Phone";
	cout << "|=| " << setw(10) << left << "Balance";
	cout << "\n________________________________________________________________________________________________________\n\n";
	PrintClientList(vClients);
	cout << endl;
	cout << "_________________________________________________________________________________________________________\n\n\n";
	GoBackToMainMenu();
}

void PrintNewClientScreen() {
	system("cls");
	
	cout << "=========================================\n";
	cout << Tabs(2) << "Add New Clients Screen\n";
	cout << "=========================================\n";
	AddClients();

	GoBackToMainMenu();
}

void PrintDeleteClientScreen() {
	vector<stClients> vClients = LoadClientDataFromFile(BankFileName);
	system("cls");
	cout << "==============================================\n";
	cout << Tabs(2) << "Delete Client Screen\n";
	cout << "==============================================\n";
	DeleteClientByAccountNumber(vClients);

	GoBackToMainMenu();
}

void PrintUpdateClientScreen() {
	vector<stClients> vClients = LoadClientDataFromFile(BankFileName);
	system("cls");
	cout << "==============================================\n";
	cout << Tabs(2) << "Update Client Screen\n";
	cout << "==============================================\n";
	UpdateClient(vClients);
	

	GoBackToMainMenu();
}

void PrintFindClientScreen() {
	system("cls");
	vector<stClients> vClients = LoadClientDataFromFile(BankFileName);
	cout << "==============================================\n";
	cout << Tabs(2) << "Find Client Screen\n";
	cout << "==============================================\n";
	FindClient(vClients);

	GoBackToMainMenu();
}

void PrintProgramEnd() {
	cout << "\n-----------------------------------\n";     
	cout << "\tProgram Ends :-)";     
	cout << "\n-----------------------------------\n";
}

void MainScreen() {
	bool PlayAgain = true;

	while (PlayAgain) {
		system("cls");
		PrintMainMenuScreen();
		enOperation OpType = (enOperation)ReadNumberBetween("Choose what do you want to do? [1 to 6]? ", 1, 6);
		switch (OpType) {
			case enOperation::eList: {
				PrintListScreen();
				break;
			}
			case enOperation::eNew: {
				PrintNewClientScreen();
				break;
			}
			case enOperation::eDelete: {
				PrintDeleteClientScreen();
				break;
			}
			case enOperation::eUpdate: {
				PrintUpdateClientScreen();
				break;
			}
			case enOperation::eFind: {
				PrintFindClientScreen();
				break;
			}
			case enOperation::eExit: {
				PlayAgain = false;
				break;
			}
			default: {
				PlayAgain = false;
			}
		}
	}
	PrintProgramEnd();
}

int main() {

	MainScreen();

	return 0;
}

