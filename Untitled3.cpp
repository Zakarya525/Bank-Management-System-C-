#include <iostream>
#include "header.h"
#include <fstream>
#include <conio.h>
using namespace::std;
	void Bank::menu(){
		int a;
		do{
				cout<<"\n\n--Bank MAnagement system vai Object-Oriented Programming, saving it to file--\n\n";
		cout<<"1)Create new account\n2)View an account\n3)Edit an account\n4)Transaction of money\n5)Erase an account\n6)Exit\n\n\tEnter your choice: ";
	    cin>>a;
	    switch(a){
	    	case 1:{
	    		new_acc();
				break;
			}
	    	case 2:{
	    		check_an_acc();
				break;
			}
	    	case 3:{
	    		edit();
				break;
			}
	    	case 4:{
	    		transact();
				break;
			}
	    	case 5:{
	    		erase();
				break;
			}
	    
		}
	}while(a != 6);
	}
	
	void Bank::new_acc(){
		ofstream out;
		out.open("Bank record.dat",ios::app);
		int a;
		cout<<"How many accounts you want to create: ";
		cin>>a;
		for(int i = 1; i <= a; i++){
			cout<<"\nNo."<<i;
			cout<<"\nEnter your name: ";
			cin>>name;
			cout<<"Enter your birth date: ";
			cin>>DOB;
			cout<<"Enter your citizen ship number: ";
			cin>>csn;
			cout<<"Enter your address: ";
			cin>>address;
			cout<<"Enter phone number: ";
			cin>>ph;
			cout<<"Enter your amount to add to your account: ";
			cin>>amount;
			out<<endl<<name<<endl<<DOB<<endl<<csn<<endl<<address<<endl<<ph<<endl<<amount<<endl;
		}
		cout<<"\nAccounts has been added\n";
		out.close();
		getch();
		system("cls");
	}
	void Bank::check_an_acc(){
	    long int no;
	    int b = 1;
		ifstream in("Bank record.dat");
		cout<<"Enter your Ph.No: ";
		cin>>no;
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		while(!in.eof()){
			if(no == ph){
			cout<<"\nName: "<<name;
			cout<<"\nBirth date: "<<DOB;
			cout<<"\nCitizen ship number: "<<csn;
			cout<<"\nAddress: "<<address;
			cout<<"\nPhone number: "<<ph;
			cout<<"\nTotal Amount: "<<amount;
		    b++;
			}
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		}
		if(b == 1)
		cout<<"\nSorry! There is no Account with that number\n";
	
		in.close();
		getch();
		system("cls");
		
	}
	
	void Bank::edit(){
		long int no;
	    int b = 1;
	    double amount1;
	    char name1[39];
		char address1[20];
		long int ph1;
		long int csn1;
		char DOB1[20];
		cout<<"Enter your Ph.No: ";
		cin>>no;
		ifstream in("Bank record.dat");
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		ofstream out("new.dat");
		while(!in.eof()){
			if(no != ph){
				out<<endl<<name<<endl<<DOB<<endl<<csn<<endl<<address<<endl<<ph<<endl<<amount<<endl<<endl;		}
		else{
			cout<<"\nEnter your name: ";
			cin>>name1;
			cout<<"Enter your birth date: ";
			cin>>DOB1;
			cout<<"Enter your citizen ship number: ";
			cin>>csn1;
			cout<<"Enter your address: ";
			cin>>address1;
			cout<<"Enter phone number: ";
			cin>>ph1;
			cout<<"Enter your amount to add to your account: ";
			cin>>amount1;
			out<<endl<<name1<<endl<<DOB1<<endl<<csn1<<endl<<address1<<endl<<ph1<<endl<<amount1<<endl;
			cout<<"\nThe account successfully updated\n";
			}
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		}
		
		
		in.close();
		out.close();
	    remove("Bank record.dat");
	    rename("new.dat", "Bank record.dat" );
		getch();
		system("cls");
		
	
	}
	void Bank::erase(){
		int no,b = 1;
		cout<<"Enter your Ph.No: ";
		cin>>no;
		ifstream in("Bank record.dat");
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		ofstream out("new.dat");
		while(!in.eof()){
			if(no != ph){
		    out<<endl<<name<<endl<<DOB<<endl<<csn<<endl<<address<<endl<<ph<<endl<<amount<<endl;
		    b++;
		   }
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		}
		if(b > 1)
		cout<<"\nThe account deleted\n";
		in.close();
		out.close();
		remove("Bank record.dat");
	    rename("new.dat", "Bank record.dat" );
		getch();
		system("cls");
	}
	
	void Bank::transact(){
		long int no;
	    int b = 1;
	    int c;
		ifstream in("Bank record.dat");
		cout<<"Enter your Ph.No: ";
		cin>>no;
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		ofstream out;
		out.open("Bank record.dat");
		while(!in.eof()){
			if(no == ph){
			cout<<"\nName: "<<name;
			cout<<"\nBirth date: "<<DOB;
			cout<<"\nCitizen ship number: "<<csn;
			cout<<"\nAddress: "<<address;
			cout<<"\nPhone number: "<<ph;
			cout<<"\nTotal Amount: "<<amount;
			cout<<"\n1.Deposit\n2.Withdraw\nEnter : ";
			cin>>c;
			if(c == 1){
				cout<<"How many you want to deposit: ";
				cin>>dep;
				amount = amount + dep;
				cout<<"\nDeposition completed\n";
			}
			if(c == 2){
				cout<<"How many you want to withdraw: ";
				cin>>withd;
				amount = amount - withd;
				cout<<"\nWithdrawal completed\n";
			}
		    b++;
			}
		out<<endl<<name<<endl<<DOB<<endl<<csn<<endl<<address<<endl<<ph<<endl<<amount<<endl;
		in >> name;
		in >> DOB;
		in >> csn;
		in >> address;
		in >> ph;
		in >> amount;
		}
		if(b == 1)
		cout<<"\nSorry! There is no Account with that number\n";
	
		in.close();
		getch();
		system("cls");
	}
	
