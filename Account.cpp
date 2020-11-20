#include "Account.h"
#include "StockAccount.h"
#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

Account::Account() {
	setCashBalance.close();
	setCashBalance.open("cash_balance.txt");
	setCashBalance << 10000;
}

void Account::random() {
	srand(time(0));
	randomStocks.close();
	int random = rand() % 2 + 1;
	string name = "stock" + to_string(random) + ".txt";
	randomStocks.open(name);
}

string Account::displayTime() {
	time_t UTC = time(0) % 86400;
	int sec = UTC % 60;
	int min = ((UTC - sec) / 60) % 60;
	int hour = (((UTC - sec) / 60) - min) / 60;
	string secs = to_string(sec);
	string mins = to_string(min);
	string hours = to_string(hour);
	return hours + ":" + mins + ":" + secs;
}

void Account::displayPortfolio() {
	cout << "Cash balance = $" << cashBalance << endl << endl;
	cout << setw(10) << left << "Symbol" << setw(30) << left << "Company" << setw(10) << left << "Number" << setw(10) << left << "Price" << setw(10) << left << "Total" << endl;
	random();
	while (randomStocks >> randomStockSymbol >> randomStockCompany >> randomStockPrice) { 
		for (unsigned int a = 0; a < myStocks.size(); a++) {
			if (myStocks[a].symbol == randomStockSymbol) {
				myStocks[a].price = randomStockPrice;  
				break;
	}}}
	totalValue = cashBalance;
	for (unsigned int a = 0; a < myStocks.size(); a++) {
		cout << setw(10) << left << myStocks[a].symbol << setw(30) << left << myStocks[a].company << setw(10) << left << myStocks[a].number << setw(10) << left << myStocks[a].price << setw(10) << left << myStocks[a].number * myStocks[a].price << endl;
		totalValue += (myStocks[a].number * myStocks[a].price); 
	} 
	cout << endl;
	cout << "Total portfolio value = $" << totalValue << endl; 
}

double Account::validInput() {
	double number;
	while ((!(cin >> number)) || number < 0) {
		cout << "Invalid input. Enter new number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return number;
} 