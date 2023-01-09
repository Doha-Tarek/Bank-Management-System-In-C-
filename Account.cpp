#include "Account.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

Account::Account()
{
    //ctor
}

Account::~Account()
{
    //dtor
}

void Account::create_account()
{
    cout << "\nEnter Account Number: ";
    cin >> account_num;
    cout << "\n\nEnter The Name of Account Holder: ";
    fflush(stdin);
	gets(name);
	cout << "\nEnter The Balance: ";
	cin >> balance;
	cout<<"\n\n\nAccount Created..\n";
}

void Account::show_account()
{
    cout << "\nAccount Number: "<<account_num;
    cout << "\nAccount Holder Name: "<<name;
    cout << "\nBalance Amount: "<<balance;
}
void Account::deposit(int deposit_amount)
{
    balance+=deposit_amount;
}
void Account::withdraw(long Withdraw_amount)
{
    if (Withdraw_amount<=balance)
    {
        balance-=Withdraw_amount;

    }
    else
        cout<<"Less Balance.....\n";
}

int Account::return_account_num()
{
    return account_num;
}
