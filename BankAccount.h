#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "Account.h"
#include <fstream>
#include <string>

class BankAccount : public Account {
public:
	BankAccount();
	~BankAccount();
	void main();
	void bankMenu();
	void depositMoney();
	void withdrawMoney();
	void displayBankHistory();

	ofstream bankHistory;
	string BHaction, BHdate, BHtime;
	double BHamount, BHcashBalance; 
private:
};

#endif 