#include<iostream>
#include<fstream>
using namespace std;

void user()
{
	int pass = 123, id;
	cout << "\t\t\t\t***********************************************" << endl;
	cout << "\t\t\t\tWELCOME TO THE ONLINE FOOD DELIVERY APPLICATION" << endl;
	cout << "\t\t\t\t***********************************************"<<endl;
	do{
			cout << "Enter Your ID: ";
			cin >> id;
			cout << "Enter Your Password: ";
			cin >> pass;
		if (id != 844 || pass != 123)
				{
					cout << "\t\t\t\t***********************************************" << endl;
					cout << "\t\t\t\t\t  Inavild id or Password :" << endl;
				}
			} while ((pass != 123) || (id != 844));

		if (pass == 123)
			{
			cout << "\t\t\t\t***********************************************" << endl;
			cout << "\t \t \t \t \t You're login with User id : " << id << endl;
			cout << "\t\t\t\t***********************************************" << endl;
			}
}


void add_to_cart(int Item_Price,int & count,int final[],int final_copy[],int &sum)
{
	ifstream fin("finalBill.txt");
	ofstream fout("finalBill.txt");
	int sum2 = 0;

	char contineu,order_placing;

	for (int i = 0; i <= count; i++)
	{
		final[count] = Item_Price;
	}
	for (int i = 0; i <= count; i++)
	{
		sum2 += final[i];
	}
	count++;
	cout << "\t\t\t\t***********************************************" << endl;
	cout << " \t \t \t \t Wanna add something in your meal? (Y/N)";
	cin >> contineu;
	if (contineu == 'Y' || contineu == 'y')
	{
		return;
	}
		cout << "\t\t\t\t(*******Do you want to confirm your order? (Y/N):********)" << endl;
		cin >> order_placing;
		if (order_placing == 'Y' || order_placing == 'y')
		{
			cout << "\t\t\t\t***********************************************" << endl;
			cout << "\t\t\t\tTOTAL PAYMENT:  " << sum2 << endl;
			fout << "TOTAL PAYMENT:  " << sum2 << endl;
		}
		else if (order_placing == 'N' || order_placing == 'n')
		{
			cout << "\t\t\t\t***********************************************" << endl;
			cout << "\t\t\t\tOrder Canaclled ";
			cout << "\t\t\t\t***********************************************" << endl;
		}
}
void snacksdrinks(char filefive[], ifstream& fin5, int&count, int final[], int final_copy[], int &sum){
	char* snack = NULL;
	snack = new char[150];

	int* price = NULL;
	price = new int[30];

	int i = 0,n=0;
	int confirm, Item_Price;
	fin5.open(filefive);

	if (!fin5.is_open())
	{
		cout << "File not Found: ";
	}

	else
	{
		cout<<"\t\t\t\t***********************************************" << endl;
		while (!fin5.eof())
		{
			fin5.getline(snack, 49, '.');

			fin5 >> price[i];
			cout<< snack << " ";
			cout << price[i] << endl;
			i++;
			cout << endl;	
		}

		cout << "Enter the item you want to add to cart: ";
		cin >> confirm;
		Item_Price = price[confirm - 1];
		cout << "\t\t\t\t***********************************************" << endl;
		cout << "\t\t\t\tItem Price  " << Item_Price << "\n\n";
		add_to_cart(Item_Price, count, final, final_copy, sum);
	}
	fin5.close();
	
}

void midnight(char filefour[], ifstream&fin4, int&count, int final[], int final_copy[], int &sum)
{
	char* mid = NULL;
	mid = new char[150];

	int* price = NULL;
	price = new int[30];

	int i = 0;
	int confirm, Item_Price;
	fin4.open(filefour);

	if (!fin4.is_open())
	{
		cout << "File not Found: ";
	}

	else
	{
		cout << "\t\t\t\t***********************************************" << endl;

		while (!fin4.eof())
		{
			fin4.getline(mid, 149, '#');

			fin4 >> price[i];
			cout<< mid << " ";
			cout << price[i] << endl;
			i++;
			cout << endl;
		}
		cout << "\t\t\t\t***********************************************" << endl;
		cout << "\t\t\t\tEnter the item you want to add to cart: ";
		cin >> confirm;
		Item_Price = price[confirm - 1];
		cout << "Item Price  " << Item_Price << "\n\n";
		add_to_cart(Item_Price, count, final, final_copy, sum);
	}
	
	fin4.close();
	}


void familydeals(char filethree[], ifstream&fin3,int&count,int final[], int final_copy[], int &sum)
{

	char* family = NULL;
	family = new char[150];

	int* price = NULL;
	price = new int[30];

	int i = 0;
	int confirm, Item_Price;
	fin3.open(filethree);

	if (!fin3.is_open())
	{
		cout << "File not Found: ";
	}

	else
	{
		cout << "\t\t\t\t***********************************************" << endl;

		for (int i = 0; i < 3; ++i)
		{
			fin3.getline(family, 149, '#');

			fin3 >> price[i];
			cout<< family << " ";
			cout << price[i] << endl;
		}
		cout << "\t\t\t\t***********************************************" << endl;
		cout << "\t\t\t\tEnter the item you want to add to cart: ";
		cin >> confirm;
		Item_Price = price[confirm - 1];
		cout << "Item Price  " << Item_Price << "\n\n";
		add_to_cart(Item_Price, count, final, final_copy, sum);
	}

	fin3.close();
}

	


void deal(char filetwo[], ifstream&fin2, int&count,int final[],int final_copy[],int &sum)
{
	char* single = NULL;
	single = new char[50];

	int* price = NULL;
	price = new int[30];
	int i = 0;
	int confirm, Item_Price;

	fin2.open(filetwo);

	if (!fin2.is_open())
	{
		cout << "File not Found: ";
	}

	else
	{
		cout << "\t\t\t\t***********************************************" << endl;

		while (!fin2.eof())
		{
			fin2.getline(single, 49, '.');

			fin2 >> price[i];
			cout<< single << " ";
			cout << price[i] << endl;
			i++;
		}
		cout << "\t\t\t\t***********************************************" << endl;
		cout << "\t\t\t\tEnter the item you want to add to cart: ";
		cin >> confirm;
		Item_Price = price[confirm - 1];
		cout << "Item Price:  " << Item_Price << "\n\n";
		add_to_cart(Item_Price,count,final,final_copy,sum);
		
	}
	
	fin2.close();
}


void seller(char fileone[], ifstream&fin1, int&count,int final[],int final_copy[],int&sum)
{

	char* burger = NULL;
	burger = new char[50];
	
	int* price = NULL;
	price = new int[30];
	int confirm, Item_Price;
	int i = 0;
	fin1.open(fileone);

	if (!fin1.is_open())
	{
		cout << "File not Found: ";
	}
	
	else
	{
		cout << "\t\t\t\t***********************************************" << endl;

		while (!fin1.eof())
		{
			fin1.getline(burger, 49,'.');

			fin1 >> price[i];
			cout<< burger << " ";
			cout << price[i] << endl;
			i++;
		}
		cout << "Enter the item you want to add to cart: ";
		cin >> confirm;
		Item_Price = price[confirm - 1];
		cout << "Item Price  " << Item_Price << "\n\n";
		add_to_cart(Item_Price,count,final,final_copy,sum);
		
	}
	fin1.close();
}

void read(int final[], int final_copy[], int sum )
{
	char fileone[20] = "best_sellers.txt";
	char filetwo[15] = "deals.txt";
	char filethree[15] = "famdeals.txt";
	char filefour[15] = "midnight.txt";
	char filefive[20] = "snacks&bevgs.txt";
	char choice,input;
	int count=0;
	
	ifstream fin1,fin2,fin3,fin4,fin5;
	
	do{
		cout << "\t \t \t \t  \t SELECT ONE OF THE FOLLOWING " << endl;
		cout << "Enter A for Best Seller Deals: \nEnter B for Single Person Deals \nEnter C for Family Deals \nEnter D for Midnight \nEnter E for Snacks & Beverages: ";
		cin >> choice;
		if (choice == 'A' || choice == 'a')
		{
			seller(fileone, fin1, count,final,final_copy,sum);
			cout << "\t\t\t\t***********************************************" << endl;
			cout << "\n \t \t \t \t Enter Y for Contnue and N for Exit ";
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				continue;
			}
			else if (input == 'N' || input == 'n')
			{
				break;
			}
		}
		else if(choice == 'B' || choice == 'b')
		{
			deal(filetwo, fin2, count,final,final_copy,sum);
			cout << "\t\t\t\t***********************************************" << endl;
			cout << "\n \t \t \t \t Enter Y for Contnue and N for Exit ";
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				continue;
			}
			else if (choice == 'N' || choice == 'n')
			{
				break;
			}
		}
		else if (choice == 'C' || choice == 'c')
		{
			familydeals(filethree, fin3, count,final, final_copy, sum);
			cout << "\t\t\t\t***********************************************" << endl;
			cout << "\n \t \t \t \t Enter Y for Contnue and N for Exit ";
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				continue;
			}
			else if (choice == 'N' || choice == 'n')
			{
				break;
			}
		}
		else if (choice == 'D' || choice == 'd')
		{
			midnight(filefour, fin4, count,final, final_copy, sum);
			cout << "\t\t\t\t***********************************************" << endl;
			cout << "\n \t \t \t \t Enter Y for Contnue and N for Exit ";
			cin >> input;
			if (input == 'Y' || input == 'y')
			{
				continue;
			}
			else if (input == 'N' || input == 'n')		
			{
				break;
			}

		}
			else if (choice == 'E' || choice == 'e')
		{
				snacksdrinks(filefive, fin5, count, final, final_copy, sum);
				cout << "\t\t\t\t***********************************************" << endl;
				cout << "\n \t \t \t \t Enter Y for Contnue and N for Exit ";
				cin >> input;
				if (input == 'Y' || input == 'y')
				{
					continue;
				}
				else if (input == 'N' || input == 'n')
				{
					break;
				}
		}	
	} while ((choice != 'A' || choice != 'a') || (choice != 'B' || choice != 'b') || (choice != 'C' || choice != 'c') || (choice != 'D' || choice != 'd') || (choice != 'E' || choice != 'e'));

	cout << "\n\t\t\t\t***********************************************" << endl;
	cout << "\t\t\t\t  THANKS FOR ONLINE FOOD DELIVERY APPLICATION" << endl;
	cout << "\t\t\t\t***********************************************" << endl;

}
	


int main()
{

	int sum = 0; 
	int finale[10] = {};
	int final_copy[10] = {};

	user();
	read(finale,final_copy,sum);

	


	system("pause");
	return 0;
}
