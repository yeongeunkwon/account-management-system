#include "Account.h"
#include "StockAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

StockAccount::StockAccount() { 
	//accountCashPtr = &stockCashBalance;
	//cout << "stockaccountCashPtr is " << accountCashPtr << endl;
	stockHistory.close();
	stockHistory.open("stock_transaction_history.txt");
}

void StockAccount::main() {
	bool x = true;
	while (x) {
		stockMenu();
		int selection;
		cin >> selection;
		cout << endl;
		switch (selection) {
		case 1:
			displayStockPrice();
			cout << endl;	break;
		case 2:
			buyStock();
			cout << endl;	break;
		case 3:
			sellStock();
			cout << endl;	break;
		case 4:
			displayPortfolio();
			cout << endl;	break;
		case 5:
			displayStockHistory();
			break;
		case 6:	default: 
			x = false;	break;
}}}

void StockAccount::stockMenu() {
	cout << "Please select an option " << endl;
	cout << "	1. Display current price for a stock symbol " << endl;
	cout << "	2. Buy stock " << endl;
	cout << "	3. Sell stock " << endl;
	cout << "	4. Display current portfolio " << endl;
	cout << "	5. Display transactions history " << endl;
	cout << "	6. Return to main menu " << endl;
	cout << "	Your selection: ";
}

void StockAccount::displayStockPrice() {
	cout << "Enter stock symbol for checking price: ";
	cin >> mySymbol;
	cout << endl;
	random(); 
	while (randomStocks >> randomStockSymbol >> randomStockCompany >> randomStockPrice) {
		if (mySymbol == randomStockSymbol) {
			cout << setw(10) << left << randomStockSymbol << setw(30) << left << randomStockCompany << setw(10) << left << randomStockPrice << displayTime() << endl;
			return;
		}
	}
	cout << "Stock not available. " << endl;
}

void StockAccount::buyStock() { //could use overloaded +
	cout << "Enter buy options: ";
	cin >> mySymbol >> myNumber >> myPrice;
	random(); 
	while (randomStocks >> randomStockSymbol >> randomStockCompany >> randomStockPrice) {    
		if (mySymbol == randomStockSymbol && myPrice >= randomStockPrice) {
			cashBalance -= (myNumber * myPrice);
			for (unsigned int a = 0; a < myStocks.size(); a++) {  // if I already have the stock
				if (mySymbol == myStocks[a].symbol) {
					myStocks[a].number += myNumber;
					return;
			}}
			Stock newStock;
			newStock.symbol = randomStockSymbol;
			newStock.company = randomStockCompany;
			newStock.number = myNumber;
			newStock.price = 0;
			myStocks.push_back(newStock);
			stockHistory << "Buy" << "	" << mySymbol << "	" << myNumber << "	" << myPrice << "	" << displayTime() << endl;
			return;
	}}
	cout << "Cannot process transaction. " << endl;
}

void StockAccount::sellStock() { // could use overloaded -
	cout << "Enter selling options: ";
	cin >> mySymbol >> myNumber >> myPrice; 
	random(); 
	for (unsigned int a = 0; a < myStocks.size(); a++) {
		if (mySymbol == myStocks[a].symbol) {
			while (randomStocks >> randomStockSymbol >> randomStockCompany >> randomStockPrice) {
				if (mySymbol == randomStockSymbol && myPrice <= randomStockPrice && myNumber <= myStocks[a].number) {
					cashBalance += (myNumber * myPrice);
					stockHistory << "Sell" << "	" << mySymbol << "	" << myNumber << "	" << myPrice << "	" << displayTime() << endl;
					if (myNumber < myStocks[a].number) {
						myStocks[a].number -= myNumber;
						return;
					}
					if (myNumber = myStocks[a].number) {
						myStocks.erase(myStocks.begin() + a); 
						return;
	}}}}}
	cout << "Cannot process transaction. " << endl;
} 

void StockAccount::displayStockHistory() {
	cout << setw(10) << left << "Action" << setw(10) << left << "Symbol" << setw(10) << left << "Shares" << setw(10) << left << "Price" << setw(10) << left << "Time" << endl;
	ifstream readStockHistory("stock_transaction_history.txt");
	while (readStockHistory >> action >> symbol >> shares >> price >> time)
		cout << setw(10) << left << action << setw(10) << left << symbol << setw(10) << left << shares << setw(10) << left << price << setw(10) << left << time << endl;
	cout << endl;
}