#include "Account.h"
#include "BankAccount.h" 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

BankAccount::BankAccount() {
	//double *bankCashPtr = &testCashBalance;
	//accountCashPtr = bankCashPtr;
	//accountCashPtr = &bankCashBalance;
	bankHistory.close();
	bankHistory.open("bank_transaction_history.txt");
}

BankAccount::~BankAccount() {
}

void BankAccount::main() {
	bool x = true;
	while (x) {
		bankMenu();
		int bankMenuSelection;
		cin >> bankMenuSelection;
		cout << endl;
		switch (bankMenuSelection) {
		case 1:
			displayPortfolio();
			cout << endl;
			break;
		case 2:
			depositMoney();
			cout << endl;
			break;
		case 3:
			withdrawMoney();
			cout << endl;
			break;
		case 4:
			displayBankHistory();
			break;
		case 5:	default:
			x = false;
			break;
}}}

void BankAccount::bankMenu() {
	cout << "Please select an option " << endl;
	cout << "	1. View account balance " << endl;
	cout << "	2. Deposit money " << endl;
	cout << "	3. Withdraw money " << endl;
	cout << "	4. Display transactions history " << endl;
	cout << "	5. Return to main menu " << endl;
	cout << "	Your selection: ";
} 

void BankAccount::depositMoney() {
	double deposit;
	cout << "Enter the amount to be deposited: ";
	deposit = validInput();

	setCashBalance.close();
	setCashBalance.open("cash_balance.txt");
	
	
	cashBalance += deposit;
	bankHistory << "Deposit" << "	" << deposit << "	" << cashBalance << "	" << "05/07/2017" << "	" << displayTime() << endl;
	cout << "Depositing $" << deposit << " to bank account" << endl << endl; 
	displayPortfolio();
}

void BankAccount::withdrawMoney() {
	double withdrawal;
	cout << "Enter the amount to be withdrawn: ";
	withdrawal = validInput();
	if (withdrawal <= cashBalance) {
		cashBalance -= withdrawal;
		bankHistory << "Withdraw" << "	" << withdrawal << "	" << cashBalance << "	" << "05/07/2017" << "	" << displayTime() << endl;
		cout << "Withdrawing $" << withdrawal << " from bank account" << endl << endl; 
		displayPortfolio();
	}
	else
		cout << "Invalid input " << endl;
}

void BankAccount::displayBankHistory() {
	cout << setw(10) << left << "Action" << setw(10) << left << "Amount" << setw(17) << left << "Cash Balance" << setw(14) << left << "Date" << setw(10) << left << "Time" << endl;
	ifstream readBankHistory("bank_transaction_history.txt");
	while (readBankHistory >> BHaction >> BHamount >> BHcashBalance >> BHdate >> BHtime)
		cout << setw(10) << left << BHaction << setw(10) << left << BHamount << setw(17) << left << BHcashBalance << setw(14) << left << BHdate << setw(10) << left << BHtime << endl;
	cout << endl; 
}