#include "Account.h"
#include "BankAccount.h"
#include "StockAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void menu();

int main() {
	Account account;
	StockAccount stockAccount;
	BankAccount bankAccount;

	//account.accPtr = &bankAccount;

	//stock1.cin.getline(symbol, 5);
		//cout << symbol << " " << company << "  " << price << endl;
	//getline(cin, company);
	/*if (stock1.is_open())
		cout << "is open " << endl;*/

	cout << "Welcome to the Account Management System. " << endl;
	bool y = true;
	while (y) {
		menu();
		int selection;
		cin >> selection;
		cout << endl;
		switch (selection) {
		case 1:
			stockAccount.main();	break;
		case 2: 
			bankAccount.main();	break;
		case 3:	default:
			cout << "Program Terminated. " << endl;
			y = false;	break;
	}}

	system("pause");
	return 0;
}

void menu() {
	cout << "Please select an account to access " << endl;
	cout << "	1. Stock Portfolio Account " << endl;
	cout << "	2. Bank Account " << endl;
	cout << "	3. Exit " << endl;
	cout << "	Your selection: ";
} 