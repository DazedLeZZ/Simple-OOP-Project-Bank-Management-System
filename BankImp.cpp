// BANK MANAGEMET SYSTEM : IMPLEMENTATION FILE

#include<iostream>
#include<iomanip>
#include<cstdlib> // To use rand()
#include<string>
#include"BankSpec.h"

using namespace std;

void account::create_account(string t) {
	cout << "\t\t\t\t  Automatically Generated Account No: ";
	acc_no = (rand() % 500) + 1;
	cout << acc_no;
	cout << endl << endl;
	cout << "\t\t\t\t  Enter First Name of Account Holder: ";
	cin >> name;
	cout << endl;
	cout << "\t\t\t\t  Enter Initial Amount: ";
	cin >> deposit;
	cout << endl;
	acc_type = t;
	cout << "\t\t\t\t  Account Created Successfully... " << endl;
	cout << endl << endl;
	system("pause");

}
void account::show_account(int j) const {
	if (j == acc_no) {
		cout << endl;
		cout << "\t\t\t\t Account Holder Name: " << name << endl;
		cout << "\t\t\t\t Account Type: " << acc_type << endl << endl;
		cout << "\t\t\t\t Account Balance: " << deposit << endl;
	}
	cout << endl << endl;
}
void account::modify(string t, int j) {
	acc_no = j;
	string temp;
	temp = acc_type;
	acc_type = t;
	T_acc = T_acc - 1;
	cout << "\t\t\t\t Modify Account Holder Name: ";
	cin >> name;
	cout << endl;
	cout << "\t\t\t\t Modify Account Initial Amount: ";
	cin >> deposit;
	cout << endl << endl;

}
void account::close(int j) {
	if (j == acc_no) {
		acc_no = 0;
		name = "Nil";
		acc_type = "Nil";
		deposit = 0;
		T_acc = T_acc - 1;
	}
}
void account::deposits(int x, int j) {
	if (j == acc_no) {
		deposit = deposit + x;
	}
}
void account::withdraws(int x, int j) {
	if (j == acc_no) {
		deposit = deposit - x;
		cout << "\t\t\t\t Amount Withdrawed Successfully..." << endl;
	}
}
void Checking_acc::withdraws(int x, int j) {
	if (j == acc_no) {
		if (x > deposit) {
			int balance;
			balance = deposit - x;
			balance = -balance;
			if (balance < draft) {
				cout << "\t\t\t\t ---Entered Amount is More than Amount in Bank Account---" << endl << endl << endl;
				cout << "\t\t\t\t Overdrafting............." << endl << endl << endl;
				system("pause");
				cout << endl << "\t\t\t\t Overdrafted Amount: " << balance << " Rs" << endl;
				draft = draft - balance;
				deposit = 0;
				cout << endl;
				cout << "\t\t\t\t Amount Withdrawed Successfully..." << endl;
			}
			else if (balance > draft) {
				cout << "\t\t\t\t ---Overdrafting Limit Reached---" << endl << endl;
				cout << "\t\t\t\t Amount Can Not be Withdrawed..." << endl;
			}
			cout << endl;
		}
		else if (x <= deposit) {
			deposit = deposit - x;
			cout << "\t\t\t\t Amount Withdrawed Successfully..." << endl;
		}
	}
}
void Saving_acc::withdraws(int x, int j) {
	if (j == acc_no) {
		if (x > deposit) {
			cout << "\t\t\t\t ---Entered Amount is More Than Amount in Bank Account---" << endl << endl;
			cout << "\t\t\t\t Amount Can Not be Withdrawed..." << endl;
			cout << endl;
		}
		else if (x <= deposit) {
			deposit = deposit - x;
			cout << "\t\t\t\t Amount Withdrawed Successfully..." << endl;
		}
	}
}
void account::display() const {
	cout << "\t\t\t  " << acc_no << "\t\t  " << name << "\t\t   " << acc_type << "\t\t" << deposit << " Rs" << endl;

}
int account::getA_no() const {
	return acc_no;
}
int account::getDep() const {
	return deposit;
}
string account::getType() const {
	return acc_type;
}
int account::getT_acc() {  //const not used here because static data member
	return T_acc;
}

int account::T_acc = 0; //initializing the static int

void Main_Menu() {
	char slct; //SELECT
	account* obj1[100]; //Arrays of Pointers to Objects Concept

Menu: {
	system("CLS");
	cout << "\t\t\t                         *" << endl;
	cout << "\t\t\t                    ***********" << endl;
	cout << "\t\t\t              ***********************" << endl;
	cout << "\t\t\t      ---------------------------------------" << endl;
	cout << "\t\t\t               BANK MANAGEMENT SYSTEM" << endl;
	cout << "\t\t\t      ---------------------------------------" << endl;
	cout << "\t\t\t       ****       ****        ****      ****" << endl;
	cout << "\t\t\t       ****       ****        ****      ****" << endl;
	cout << "\t\t\t       ****       ****        ****      ****" << endl;
	cout << "\t\t\t       ****       ****        ****      ****" << endl;
	cout << "\t\t\t       ****       ****        ****      ****" << endl;
	cout << "\t\t\t      ---------------------------------------" << endl;
	cout << "\t\t\t  -----------------------------------------------" << endl;
	cout << "\t\t\t\t\t  +++MAIN MENU+++" << endl;
	cout << "\t\t\t  -----------------------------------------------" << endl;
	cout << endl;
	cout << "\t\t\t 1.  CREATE ACCOUNTS" << endl;
	cout << "\t\t\t 2.  DEPOSIT AMOUNT" << endl;
	cout << "\t\t\t 3.  WITHDRAW AMOUNT" << endl;
	cout << "\t\t\t 4.  CHECK ACCOUNT BALANCE" << endl;
	cout << "\t\t\t 5.  DISPLAY ALL ACCOUNT DETAILS" << endl;
	cout << "\t\t\t 6.  MODIFY ACCOUNT DETAILS" << endl;
	cout << "\t\t\t 7.  CLOSE ACCOUNT" << endl;
	cout << "\t\t\t 8.  EXIT" << endl;
	cout << endl;
	cout << "\t\t\t SELECT OPTION (1-8): ";
	cin >> slct;

	switch (slct)
	{
	case '1':
		system("CLS");
		int n;
		cout << "\t\t\t\t  ---------------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t     NUMBER OF ACCOUNTS" << endl;
		cout << "\t\t\t\t  ---------------------------------------------------" << endl << endl;
		cout << endl;
		cout << "\t\t\t\t  Enter the Number of Accounts you want to Create:  ";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++) {
			string type;
			cout << endl;
			system("CLS");
			cout << "\t\t\t\t  ------------------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t      CREATE ACCOUNT" << endl;
			cout << "\t\t\t\t  ------------------------------------------------------" << endl << endl;
			do {
				cout << endl;
				cout << "\t\t\t\t  Enter Account Type (saving/checking):  ";
				cin >> type;
				cout << endl;
				if (type == "checking") {
					obj1[i] = new Checking_acc;
					obj1[i]->create_account(type);
				}
				else if (type == "saving") {
					obj1[i] = new Saving_acc;
					obj1[i]->create_account(type);
				}
				else {
					cout << endl;
					cout << "\t\t\t\t  Invalid Account Type, Please try again......" << endl;
				}
			} while (type != "checking" && type != "saving");
		}
		goto Menu;
		break;
	case '2':
		system("CLS");
		if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "\t\t\t\t   -------No Accounts Created Yet-------" << endl << endl << endl;
		}
		else {
			for (int i = 0; i < 1; i++) {
				int j, amnt;
				cout << endl;
				cout << "\t\t\t\t------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t     DEPOSIT AMOUNT" << endl;
				cout << "\t\t\t\t------------------------------------------------------" << endl << endl << endl;
				cout << "\t\t\t\t Enter Account Number to Deposit Amount:  ";
				cin >> j;
				cout << endl;
				cout << "\t\t\t\t Enter Deposit Amount:  ";
				cin >> amnt;
				cout << endl;
				for (int i = 0; i < n; i++) {
					obj1[i]->deposits(amnt, j);
				}
			}
			cout << endl << "\t\t\t\t  Amount Deposited Successfully......" << endl;
		}
		cout << endl;
		system("pause");
		goto Menu;
		break;
	case '3':
		system("CLS");
		if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "\t\t\t\t   -------No Accounts Created Yet-------" << endl << endl << endl;
		}
		else {
			for (int k = 0; k < 1; k++) {
				int j, amnt;
				cout << endl;
				cout << "\t\t\t\t------------------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t     WITHDRAW AMOUNT" << endl;
				cout << "\t\t\t\t------------------------------------------------------" << endl << endl << endl;
				cout << "\t\t\t\t Enter Account Number to Withdraw Amount:  ";
				cin >> j;
				cout << endl;
				cout << "\t\t\t\t Enter Amount To Be Withdrawed:  ";
				cin >> amnt;
				cout << endl;
				for (int i = 0; i < n; i++) {
					obj1[i]->withdraws(amnt, j);
				}
			}
		}
		cout << endl;
		system("pause");
		goto Menu;
		break;
	case '4':
		system("CLS");
		if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "\t\t\t\t   -------No Accounts Created Yet-------" << endl << endl << endl;
		}
		else {
			for (int k = 0; k < 1; k++) {
				int j;
				cout << "\t\t\t\t-----------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t    ACCOUNT DETAILS" << endl;
				cout << "\t\t\t\t-----------------------------------------------" << endl << endl;
				cout << "\t\t\t\t Enter Account Number to Show Details:  ";
				cin >> j;
				for (int i = 0; i < n; i++) {
					obj1[i]->show_account(j);
				}
			}
		}
		cout << endl;
		system("pause");
		goto Menu;
		break;
	case '5':
		system("CLS");
		cout << endl << endl;
		if (account::getT_acc() == 0) {
			cout << "\t\t\t\t -------No Accounts Created Yet-------" << endl;
		}
		else {
			cout << "\t\t\t\t  -----------------------------------------------" << endl;
			cout << "\t\t\t\t\t\t ALL ACCOUNT DETAILS" << endl;
			cout << "\t\t\t\t  -----------------------------------------------" << endl << endl << endl;
			cout << "\t\t\t Account No" << "      " << "Account Name" << "      " << "Account type" << "         " << "Balance" << endl;
			cout << "\t\t\t=================================================================" << endl;
			for (int i = 0; i < n; i++) {
				obj1[i]->display();
				cout << "\t\t\t-----------------------------------------------------------------" << endl;
			}
			cout << endl;
			cout << "\t\t\t=================================================================" << endl;
			cout << "\t\t\tTotal Number of Accounts in Bank =  " << account::getT_acc() << endl;
			cout << "\t\t\t-----------------------------------------------------------------" << endl;
			cout << endl << endl;
		}
		cout << endl;
		system("pause");
		goto Menu;
		break;
	case '6':
		system("CLS");
		if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "\t\t\t\t   -------No Accounts Created Yet-------" << endl << endl << endl;
		}
		else {
			for (int k = 0; k < 1; k++) {
				cout << "\t\t\t\t-----------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t   MODIFY DETAILS" << endl;
				cout << "\t\t\t\t-----------------------------------------------" << endl << endl << endl;
				int j;
				string type;
				cout << endl;
				cout << "\t\t\t\t Enter Account Number to Modify Details:  ";
				cin >> j;
				cout << endl;
				for (int i = 0; i < n; i++) {
					if (j == obj1[i]->getA_no()) {
						do {
							cout << "\t\t\t\t Modify Account Type (saving/checking):  ";
							cin >> type;
							cout << endl;
							if (type == "checking") {
								obj1[i] = new Checking_acc;
								obj1[i]->modify(type, j);
							}
							else if (type == "saving") {
								obj1[i] = new Saving_acc;
								obj1[i]->modify(type, j);
							}
							else {
								cout << endl;
								cout << "\t\t\t\t  Invalid Account Type, Please try again......" << endl;
							}
						} while (type != "checking" && type != "saving");
					}
				}
				cout << "\t\t\t\t Account Modified Successfully.....  " << endl << endl;
			}
		}
		cout << endl;
		system("pause");
		goto Menu;
	case '7':
		system("CLS");
		if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "\t\t\t\t   -------No Accounts Created Yet-------" << endl << endl << endl;
		}
		else {
			for (int k = 0; k < 1; k++) {
				int j;
				cout << "\t\t\t\t-----------------------------------------------" << endl;
				cout << "\t\t\t\t\t\t   DELETE ACCOUNT" << endl;
				cout << "\t\t\t\t-----------------------------------------------" << endl << endl << endl;
				cout << endl;
				cout << "\t\t\t\t Enter Account Number to Delete Account:  ";
				cin >> j;
				cout << endl;
				for (int i = 0; i < n; i++) {
					obj1[i]->close(j);
				}
				cout << "\t\t\t\t Account Deleted Successfully...  " << endl << endl;
			}
		}
		cout << endl;
		system("pause");
		goto Menu;
		break;
	case '8':
		system("CLS");
		cout << endl;
		cout << "\t\t\t\t -----------------------------------------------" << endl;
		cout << "\t\t\t\t\t\t    SYSTEM EXIT" << endl;
		cout << "\t\t\t\t -----------------------------------------------" << endl << endl;
		cout << "\t\t\t\t SIMPLE OOP PROJECT: BANK MANAGEMENT SYSTEM " << endl;
		cout << "\t\t\t\t ================================================ " << endl;
		cout << endl << endl << endl;
		system("pause");
		break;

	}
	}
}