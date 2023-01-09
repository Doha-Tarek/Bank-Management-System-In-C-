#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"Account.h"
using namespace std;

void write_account();
void display_account(int n);
void display_all();
void deposit_withdraw(int n, int option);
void delete_account(int n);

int main()
{

    int ch,account_n;

    system("cls");
    do{
        system("cls");
		cout<<"\n\n1. Create New Account";
		cout<<"\n\n2. Deposit";
		cout<<"\n\n3. Withdraw";
		cout<<"\n\n4. Account Details";
		cout<<"\n\n5. Delete an Account";
		cout<<"\n\n6. EXIT";
		cout<<"\n\n\tSelect Your Option (1-6) ";
		cin>>ch;
		system("cls");

		switch(ch)
		{
        case 1:
            write_account();
            break;

        case 2:

            cout<<"\n\nEnter The Account Number : "; cin>>account_n;
            deposit_withdraw(account_n,1);
            break;

        case 3:
            cout <<"\n\nEnter The Account Number : "; cin>>account_n;
            deposit_withdraw(account_n,2);
            break;

        case 4:
            cout <<"\n\nEnter The Account Number : "; cin>>account_n;
            display_account(account_n);
            break;




        case 5:
            cout<<"\n\nEnter The account No. : "; cin>>account_n;
            delete_account(account_n);
            break;
        case 6:
            cout << "Thank You For Banking Us\n";
            break;

        default:
            cout<<"\n\nWrong Option";



		}


    }while(ch==7);

}


void write_account()
{
    Account client;
    ofstream outfile;
    outfile.open("account.dat",ios::binary|ios::app);
    client.create_account();
    outfile.write((char *) &client, sizeof(Account));
    outfile<<endl;
    outfile.close();

}

void display_account(int n)
{
    Account client;
    int flag=0;
    ifstream infile;
    infile.open("account.dat",ios::binary);
    if (!infile)
    {
        cout << "File could not be open!!\n";
        return;
    }
    cout << "\nBalance Details\n";

    while(infile.read((char *) &client, sizeof(Account)))
    {
        if (client.return_account_num()==n)
        {
            client.show_account();
            flag=1;
        }
    }
    infile.close();
    if(flag==0)
        cout << "\nAccount number does not exist\n";
}



void deposit_withdraw(int n, int option)
{
	long amt;
	int found=0;
	Account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(File.read((char *) &ac, sizeof(Account)) && found==0)
	{
		if(ac.return_account_num()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited: ";
				cin>>amt;
				ac.deposit(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw: ";
				cin>>amt;
				ac.withdraw(amt);
		      }
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(Account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	 }
    File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

void delete_account(int n)
{
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(Account)))
	{
		if(ac.return_account_num()!=n)
		{
			outFile.write((char *) &ac, sizeof(Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}


