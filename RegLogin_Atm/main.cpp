#include <iostream>
#include <fstream>
using namespace std;

bool IsLoggedIn(){
	string username,password,un,pw;
	cout<<"Enter username:"; cin>>username;
	cout<<"Enter password:"; cin>>password;

	ifstream read("Login\\" + username + ".txt");
	getline(read,un);
	getline(read,pw);

	if (un == username && pw == password)
	{
		return true;
	}
	else{
		return false;
	}
}

void atm(){
	double balance,depositAmount,withdrawAmount;
    int option;
	bool withdrawStatus = true;
	string code;
	cout<< "Enter the code with which you'll access the atm:"; cin>> code;
	
	ifstream myFile("userBalance\\" + code +".txt");
	if (!myFile.is_open())
	{
		balance = 500;
		ofstream myFile;
		myFile.open("userBalance\\" + code + ".txt");
		myFile<<balance;
		myFile.close();
	}

    choice:cout<<"Account balance: "<< balance<<endl<<"Choose 1. for deposit, 2. for withdraw."; cin >> option;
    if (balance < -10000)
	{
		system("cls");
		cout<<"Your account balance is too low, you may only deposit money from now on."<<endl;
		withdrawStatus = false;
	}

	if (option == 1)
    {
		ifstream read("userBalance\\" + code + ".txt");
		myFile>>balance;
		
        cout<<"Balance:"<<balance<<endl<<"Deposit amount: "; cin>> depositAmount;
        balance = balance + depositAmount;

		ofstream myFile;
		myFile.open("userBalance\\" + code + ".txt");
		myFile<<balance;
		myFile.close();

        system("cls");
        goto choice;
		if (balance > -10000)
		{
			withdrawStatus = true;
		}
		
    }
    else if (option == 2)
    {
		if (withdrawStatus)
		{
			ifstream read("userBalance\\" + code + ".txt");
			myFile>>balance;
		
			cout<<"Balance:"<<balance<<endl<<"Withdraw amount: "; cin>> withdrawAmount;
			balance = balance - withdrawAmount;

			ofstream myFile;
			myFile.open("userBalance\\" + code + ".txt");
			myFile<<balance;
			myFile.close();

			system("cls");
			goto choice;
		}
    }
    else{
        system("cls");
        cout<<"Please choose 1 or 2."<<endl; goto choice;
    }
}


int main()
{
	int choice;
	cout<<"1.Register"<<endl<<"2.Login"<<endl<<"Your choice:"; cin>>choice;
	if (choice == 1)
	{
		string username,password;
		cout<<"Enter a username:"; cin>> username;
		cout<<"Enter a password:"; cin>> password;
		ofstream file;
		file.open("Login\\" + username + ".txt");
		file<<username<<endl<<password;
		file.close();
		system("cls");
		main();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn();

		if (status)
		{
			system("cls");
			cout<<"Successful login."<<endl;
			atm();
			main();
		}
		else{
			system("cls");
			cout<<"Unsuccessful login."<<endl;
			main();
		}
	}
	else{
		system("cls");
		cout<<"Please choose 1. or 2.";
		main();
	}	
	
}