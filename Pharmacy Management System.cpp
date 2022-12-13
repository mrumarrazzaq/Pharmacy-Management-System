#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

void Add_Medicines();
void Delete_Medicines();
void Update_Medicines();
void Display_Medicines();
int int_length(int num);
int length(string str);
int id=1;

struct Medicines_Details
{
	int medicine_id;
	string medicine_name;
	int total_stock;
	float price;
	int total_pils;
	int total_price;
	string status;
	int id_len;
	int price_len;
	int stock_len;
	int pils_len;
	int medicine_len;
	int total_price_len;
}m[100];
void writefile(int i)
{
	ofstream file;
		file.open("Pharmacy Record.csv",fstream::app);
		file<<m[i].medicine_id<<"\t"<<m[i].medicine_name<<"\t"<<m[i].total_stock
		<<"\t"<<m[i].price<<"\t"<<m[i].total_pils<<"\t"<<m[i].total_price<<"\t"<<m[i].status<<endl;
		file.close();
}
void readfile()
{
	char ch;
	ifstream file;
	file.open("Pharmacy Record.csv");
	if(!file.is_open())
	{
		cout<<"\n Error while opening the file \n";
	}
	file.get(ch);
	while(!file.eof())
	{
		cout<<ch;
		file.get(ch);
	}
	file.close();
}
void home()
{
	cout<<"\t===========WELCOME===========\n";
	cout<<"\t ____________________________\n";
	cout<<"\t| Pharmacy Management System |\n";
	cout<<"\t|____________________________|\n";
}
void menu()
{
	char choice;
	cout<<"------------------------------------------\n";
	cout<<"Press A =>  For Add	 Medicines Details\n";
	cout<<"Press D =>  For Delete 	 Medicines Details\n";
	cout<<"Press U =>  For Update	 Medicines Details\n";
	cout<<"Press O =>  For Display	 Current   Medicines Details\n";
	cout<<"Press P =>  For Display	 Previous  Medicines Details\n";
	cout<<"Press C =>  For Clear Screen \n";
	cout<<"Press E =>  For Exit the Program \n";
	cout<<"------------------------------------------\n";
	cout<<"Please Enter your choice : ";
//	choice=getch();
	cin>>choice;
	cout<<"........................................\n";
	switch(choice)
	{
		case 'A':
			Add_Medicines();
			menu();
			break;
		case 'D':
			Delete_Medicines();
			menu();
			break;
		case 'U':
			Update_Medicines();
			menu();
			break;
		case 'O':
			Display_Medicines();
			menu();
			break;
		case 'C':
			system("CLS");
			menu();
			break;
		case 'P':
			cout<<"\n_________________________________________________________________\n";
			cout<<"All Medicine Record \n";
			readfile();
			cout<<"\n_________________________________________________________________\n";
			menu();
		case 'E':
			cout<<"\n Thanks for using this software ! \n";
			break;
		default:
			cout<<"-> Please Enter Corrrect Option ! \n";
			menu();
			break;
	}
}
void Add_Medicines()
{
	cin.ignore();
	cout<<"Enter Medicine Name            : ";getline(cin,m[id].medicine_name);
	cout<<"Enter Total Stock              : ";cin>>m[id].total_stock;
	if(m[id].total_stock!=0)
	{
		m[id].status="Available";
	}
	else
	{
		m[id].status="Not Available";
	}
	cout<<"Enter one Unit Price           : ";cin>>m[id].price;
	cout<<"Enter Totlal Unit in one Pack  : ";cin>>m[id].total_pils;
	m[id].medicine_id=id;
	m[id].total_price=m[id].price*m[id].total_pils;
	//----------------------
	m[id].id_len=int_length(id);
	m[id].medicine_len=length(m[id].medicine_name);
	m[id].price_len=int_length(m[id].price);
	m[id].stock_len=int_length(m[id].total_stock);
	m[id].pils_len=int_length(m[id].total_pils);
	m[id].total_price_len=int_length(m[id].total_price);
	writefile(id);
	id++;
	cout<<"\n Medicine  Destails Added Successfully ! \n";
	
}
void Delete_Medicines()
{
	int new_id;
	cout<<"\n---------------------------------------------\n";
	cout<<"\nEnter Medicine Id to Delete medicine record: ";cin>>new_id;
	cout<<"---------------------------------------------\n";
	if(new_id>id-1||new_id<1)
	{
		cout<<"No! Record Found \n";
		Delete_Medicines();
	}
	else
	{
		m[new_id].medicine_name="NULL";
		m[new_id].total_stock=0;
		m[new_id].price=0.0;
		m[new_id].total_pils=0;
		m[new_id].status="Not Available";
		writefile(new_id);
		cout<<"\n Medicine  Destails Delete Successfully ! \n";
		m[new_id].total_price=m[new_id].price*m[new_id].total_pils;
		//----------------------
		m[new_id].id_len=int_length(new_id);
		m[new_id].medicine_len=length(m[new_id].medicine_name);
		m[new_id].price_len=int_length(m[new_id].price);
		m[new_id].stock_len=int_length(m[new_id].total_stock);
		m[new_id].pils_len=int_length(m[new_id].total_pils);
		m[new_id].total_price_len=int_length(m[new_id].total_price);
	}
}
void Update_Medicines()
{
	
	int new_id;
	int start,choice2;
	Display_Medicines();
	cout<<"\n---------------------------------------------\n";
	cout<<"\nEnter Medicine Id to update medicine : ";cin>>new_id;
	cout<<"---------------------------------------------\n";
	if(new_id>id-1||new_id<1)
	{
		cout<<"No! Record Found \n";
		Update_Medicines();
	}
	else
	{
		start:
		cout<<"What you want to Update \n";
		cout<<"------------------------------------------\n";
		cout<<" PRESS  1 FOR ->  All Record     \n ";
		cout<<"PRESS  2 FOR ->  Medicine Name  \n ";
		cout<<"PRESS  3 FOR ->  Total Stock    \n ";
		cout<<"PRESS  4 FOR ->  One Unit Price \n ";
		cout<<"PRESS  5 FOR ->  Total Unit in one pack \n";
		cout<<"------------------------------------------\n";
		cout<<"Please Enter your choice : ";
		cin>>choice2;
		cout<<"........................................\n";
		cin.ignore();
		switch(choice2)
		{
			case 1:
				cout<<"Enter Medicine Name                : ";getline(cin,m[new_id].medicine_name);
				cout<<"Enter Total Stock                  : ";cin>>m[new_id].total_stock;
				if(m[new_id].total_stock!=0)
				{
					m[new_id].status="Available";
				}
				else
				{
					m[new_id].status="Not Available";
				}
					cout<<"Enter one Unit Price               : ";cin>>m[new_id].price;
					cout<<"Enter Totlal Unit in one Pack      : ";cin>>m[new_id].total_pils;
					writefile(new_id);
					m[new_id].total_price=m[new_id].price*m[new_id].total_pils;
					//----------------------
					m[new_id].id_len=int_length(new_id);
					m[new_id].medicine_len=length(m[new_id].medicine_name);
					m[new_id].price_len=int_length(m[new_id].price);
					m[new_id].stock_len=int_length(m[new_id].total_stock);
					m[new_id].pils_len=int_length(m[new_id].total_pils);
					m[new_id].total_price_len=int_length(m[new_id].total_price);
				break;
			case 2:
				cout<<"Enter Medicine Name                : ";getline(cin,m[new_id].medicine_name);
				m[new_id].medicine_len=length(m[new_id].medicine_name);
				writefile(new_id);
				break;
			case 3:
				cout<<"Enter Total Stock                  : ";cin>>m[new_id].total_stock;
				m[new_id].stock_len=int_length(m[new_id].total_stock);
				if(m[new_id].total_stock!=0)
				{
					m[new_id].status="Available";
				}
				else
				{
					m[new_id].status="Not Available";
				}
				writefile(new_id);
				break;
			case 4:
				cout<<"Enter one Unit Price               : ";cin>>m[new_id].price;
				m[new_id].price_len=int_length(m[new_id].price);
				writefile(new_id);
				break;
			case 5:
				cout<<"Enter Totlal Unit in one Pack      : ";cin>>m[new_id].total_pils;
				m[new_id].pils_len=int_length(m[new_id].total_pils);
				writefile(new_id);
				break;
			default:
				cout<<"-> Please Enter Corrrect Option ! \n";
				goto start;
				break;
		}
		cout<<"\n Medicine  Destails Update Successfully ! \n";
	}
}
void space(int size)
{
	for(int i=0;i<size;i++)
	cout<<" ";
}
void Display_Medicines()
{
//				12			      25                  12				15		   12			12
	cout<<"Medicine id |Medicine Name            |Total Stock |One Unit Price |Total Units |Total Price | Status \n";
	for(int i=1;i<id;i++)
	{
		
		cout<<m[i].medicine_id;space(12-m[i].id_len);cout<<"|"<<m[i].medicine_name;space(25-m[i].medicine_len);cout<<"|"<<m[i].total_stock;space(12-m[i].stock_len);
		cout<<"|"<<m[i].price;space(15-m[i].price_len);cout<<"|"<<m[i].total_pils;space(12-m[i].pils_len);cout<<"|"<<m[i].total_price;space(12-m[i].total_price_len);
		cout<<"|"<<m[i].status<<endl;
		
	}
}

int main()
{
	home();
	menu();
	return 0;
}



int int_length(int num)
{
	int digit=0;
	while(num!=0)
	{
		num=num/10;
		digit++;
	}
	return digit;
}
int length(string str)
{
	int length=0;
	for(int i=0;i<=length;i++)
	{
		if(str[i]!='\0')
		length++;
	}
	return length;
}
