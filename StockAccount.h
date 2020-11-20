#pragma once
#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H
#include "Account.h"
#include <fstream>
#include <string>

class StockAccount : public Account {
public:
	StockAccount();
	void main();
	void stockMenu();
	void displayStockPrice();
	void buyStock();
	void sellStock();
	void displayStockHistory();
	string mySymbol;
	int myNumber;
	double myPrice;
	
	ofstream stockHistory;
	string action; string symbol; int shares; double price; string time;
};

#endif