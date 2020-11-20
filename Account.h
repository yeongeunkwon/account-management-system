#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Account {
public: 
	Account();
	void displayPortfolio();
	void random();
	string displayTime();
	double validInput();
	double cashBalance = 10000;	
	double totalValue;

	struct Stock {
		string symbol; string company; int number; double price;
	};
	vector <Stock> myStocks;

	ifstream randomStocks;
	string randomStockSymbol, randomStockCompany;
	double randomStockPrice;

	ifstream getCashBalance;
	ofstream setCashBalance;
};

#endif 