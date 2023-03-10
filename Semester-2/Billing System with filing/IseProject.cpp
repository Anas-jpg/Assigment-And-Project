#include<string.h>
#include"ANAS.h"
#include<iostream>
#include<fstream>
using namespace std;

void getch()
{
	int qwerty;
	printf("\n\nSince getch() is not included in standard libraries of C in Linux,\n Hit 0 and press Enter to continue ");
	scanf("%d", &qwerty);
}
void login();
void registr();
void forgot();

void registr()
{
	string reg_user, reg_pass;
	system("cls");
	std::cout << "Enter the username : " << '\n';
	std::cin >> reg_user;
	std::cout << "Enter the password : " << '\n';
	std::cin >> reg_pass;

	ofstream reg("database.txt", ios::app);
	reg << reg_user << " " << reg_pass << endl;
	system("cls");
	std::cout << "Registration Succesful " << '\n';

}

void login()
{
	int exist;
	std::string user, pass, u, p;
	system("cls");
	std::cout << "Enter the username : " << '\n';
	std::cin >> user;
	std::cout << "Enter the password : " << '\n';
	std::cin >> pass;
	ifstream input("database.txt");

	while (input >> u >> p)
	{
		if (u == user && p == pass)
		{
			exist = 1;
		}
	}
	input.close();
	if (exist == 1)
	{
		std::cout << "Hello " << user << '\n' << "We're glad that you're here" << "\n";
		cin.get();
		cin.get();
		system("cls");

	}
	else
	{
		std::cout << "Sorry, Login error .  " << '\n';
		cin.get();
		cin.get();
		system("cls");

	}
}

void forgot()
{
	int ch;
	system("cls");
	std::cout << "1. Search your account by username " << '\n';
	std::cout << "2. Search your account by password " << '\n';
	std::cout << "3. Main Menu " << '\n';
	std::cout << "Enter your choice : " << '\n';
	std::cin >> ch;

	switch (ch)
	{
	case 1:
	{    int ex = 0;
	string search_user, su, sp;
	std::cout << "Enter your remembered username :" << '\n';
	std::cin >> search_user;

	ifstream search_user_file("database.txt");
	while (search_user_file >> su >> sp)
	{
		if (su == search_user)
		{
			ex = 1;
			break;
		}
	}

	search_user_file.close();
	if (ex == 1)
	{
		std::cout << "Hurray !  Account found !" << '\n';
		std::cout << "Your password is " << sp << '\n';
		std::cout << "Your username is " << su << '\n';
		cin.get();
		cin.get();
		system("cls");
	}
	else
	{
		std::cout << "Sorry, Your accountis not found " << '\n';
		cin.get();
		cin.get();

	}

	}    break;
	case 2:
	{
		int exi = 0;
		string search_pass, su2, sp2;
		std::cout << "Enter your remembered password :" << '\n';
		std::cin >> search_pass;

		ifstream search_user_pass("database.txt");
		while (search_user_pass >> su2 >> sp2)
		{
			if (sp2 == search_pass)
			{
				exi = 1;
				break;
			}
		}

		search_user_pass.close();
		if (exi == 1)
		{
			std::cout << "Hurray !  Account found !" << '\n';
			std::cout << "Your userName is " << su2 << '\n';
			std::cout << "Your password is " << sp2 << '\n';
			cin.get();
			cin.get();
			system("cls");
		}
		else
		{
			std::cout << "Sorry, Your account not found " << '\n';
			cin.get();
			cin.get();
		}

		break;
	}
	case 3:
	{
		break;
	}
	default:
	{
		std::cout << "You have given a wrong choice. Press any key to try again. " << '\n';
		cin.get();
		cin.get();
		forgot();
	}
	}

}


struct Record {
	int id;
	char name[30];
	float first;
	float second;
	float third;
	float units;
	float amount;
};

float first, second, third;

void showParameters()
{
	printf("\n Electricity Bill is being calculate be the following parameters\n");
	printf("\n\tFirst 100 Units @\t Rs. %.2f/Unit", first);
	printf("\n\tThe next 100 Units @\t Rs. %.2f/Unit", second);
	printf("\n\tThe remaining units @\t Rs. %.2f/Unit", third);
	cout << "The peak time Units charges are " << first + 15 << endl;
	printLine(50);
}
void loadParameters()
{
	FILE* fp1 = fopen("first.txt", "r");
	FILE* fp2 = fopen("second.txt", "r");
	FILE* fp3 = fopen("third.txt", "r");
	fscanf(fp1, "%f", &first);
	fscanf(fp2, "%f", &second);
	fscanf(fp3, "%f", &third);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
void calculateBill()
{
	int domestic, commericial;
	int phase;
	int id;
	char name[30], choice;
	loadParameters();
	showParameters();
	float units = 0.0, amount = 0.0;
	printf("Enter ID ");
	scanf("%d", &id);
	printf("Enter name ");
	scanf("%s", name);

level1:
	printf("Enter units of electricity consumed ");
	scanf("%f", &units);

	cout << "Select 1 for single phase" << endl;
	cout << "Select 2 for 3 phase" << endl;
	cin >> phase;
	if (phase == 1)
	{
		cout << "Press 1 for Domestic Customer" << endl;
		cout << "Press 2 for Commercial Customer" << endl;
		cin >> phase;
		if (phase == 1)
		{
			printf("Enter units of electricity consumed ");
			scanf("%f", &units);
			if (units < 0)
				goto level1;
			amount = units * 5;
		}
		else if (phase == 2)
		{
			printf("Enter units of electricity consumed ");
			scanf("%f", &units);
			if (units < 0)
				goto level1;
			amount = units * 5;
		}
	}
	printf("Calculated Electricity Bill is Rs %.2f/-", amount);
	printf("\n\nDo you want to save it? (Y|N) ");
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y')
	{
		FILE* fp = fopen("data.txt", "a+");
		if (fprintf(fp, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", id, name, first, second, third, units, amount) > 0)
			printf("Saved Successfully");
		else printf("Oops, faced some errors while saving. ");
		fclose(fp);
	}
	getch();
}
void setBillingParameters()
{
	loadParameters();
	showParameters();

	char choice;
	printf("Do you want to update calculation parameters?(Y|N) ");
	scanf(" %c", &choice);
	float temp1, temp2, temp3;
	if (choice == 'y' || choice == 'Y')
	{
		printf("Enter the rate of first 100 units of electricity ");
		scanf("%f", &temp1);
		printf("Enter the rate of the next 150 units of electricity ");
		scanf("%f", &temp2);
		printf("Enter the rate of the remaining units of electricity ");
		scanf("%f", &temp3);
		FILE* fp;
		fp = fopen("first.txt", "w+");
		fprintf(fp, "%.2f", temp1);
		fclose(fp);
		fp = fopen("second.txt", "w+");
		fprintf(fp, "%.2f", temp2);
		fclose(fp);
		fp = fopen("third.txt", "w+");
		fprintf(fp, "%.2f", temp3);
		fclose(fp);
		printf("Successfully Updated Parameters.");
		getch();
	}
}
void ViewWholeDataBase()
{
    loadParameters();
	showParameters();
	char ch;
	struct Record record[50];
	int i;
	FILE* fp = fopen("data.txt", "r");
	//Reading from file
	for (i = 0;;i++)
	{
		if (fscanf(fp, "%d%s%f%f%f%f%f", &record[i].id, record[i].name, &record[i].first, &record[i].second, &record[i].third, &record[i].units, &record[i].amount) == -1)
			break;
	}
	fclose(fp);
	int number = i, flag = 0;
	//Display Records
	printf("\t\tDisplaying previously saved records... :)\n");
	printLine(100);
	printf("\nID\tName\t T.V Tax\tAdd. Surcharges\tPeak Hours\tUnits Consumed\tAmount");
	printLine(100);

	//printing the records list
	for (i = 0;i < number;i++)
	{
		printf("\n%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", record[i].id, record[i].name, record[i].first, record[i].second, record[i].third, record[i].units, record[i].amount);
	}
}
void editBill()
{
	loadParameters();
	showParameters();
	char ch;
	struct Record record[50];
	int i;
	FILE* fp = fopen("data.txt", "r");
	//Reading from file
	for (i = 0;;i++)
	{
		if (fscanf(fp, "%d%s%f%f%f%f%f", &record[i].id, record[i].name, &record[i].first, &record[i].second, &record[i].third, &record[i].units, &record[i].amount) == -1)
			break;
	}
	fclose(fp);
	int number = i, flag = 0;
        //Display Records
	printf("\t\tDisplaying previously saved records... :)\n");
	printLine(100);
	printf("\nID\tName\t T.V Tax\tAdd. Surcharges\tPeak Hours\tUnits Consumed\tAmount");
	printLine(100);

	//printing the records list
	for (i = 0;i < number;i++)
	{
		printf("\n%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", record[i].id, record[i].name, record[i].first, record[i].second, record[i].third, record[i].units, record[i].amount);
	}

	int id;
	printf("\nEnter ID of the bill which you want to edit ");
	scanf("%d", &id);

	for (i = 0;i < number;i++)
	{
		if (record[i].id == id)
		{
			printf("\nEnter name ");
			scanf("%s", record[i].name);
			//level2:
			fflush(stdin);
			printf("\nEnter units of electricity consumed ");
			scanf("%f", &record[i].units);
			record[i].first = first;
			record[i].second = second;
			record[i].third = third;
			if (record[i].units > 200)
			{
				record[i].amount = (100 * first) + (100 * second) + ((record[i].units - 200) * third);
			}
			else if (record[i].units > 100 && record[i].units <= 200)
			{
				record[i].amount = (100 * first) + ((record[i].units - 100) * second);
			}
			else if (record[i].units <= 100)
			{
				record[i].amount = record[i].units * first;
			}
			printf("Calculated Electricity Bill is Rs %.2f/-", record[i].amount);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("\nNo match found in our database.");
	}
	//Save
	fflush(stdin);
	printf("\nDO YOU WANT TO MAKE CHANGES TO THE DATABASE? (Y|N) ");
	scanf(" %c", &ch);
	flag = 0;
	if (ch == 'Y' || ch == 'y')
	{
		FILE* fp = fopen("data.txt", "w");
		for (i = 0;i < number;i++)
		{
			if (fprintf(fp, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", record[i].id, record[i].name, record[i].first, record[i].second, record[i].third, record[i].units, record[i].amount) < 0)
			{
				flag = 1;
				break;
			}
		}
		fclose(fp);
		if (flag == 1)
		{
			printf("\nSorry for inconvenience.");
		}
		else {
			printf("\nOur records have been successfully updated. Have a nice day. :) ");
		}
	}
}
int _number=0;
void reviewDatabase()
{
	struct Record record[50];
	struct Record tmp;
	int i;
	int ch;
	FILE* fp = fopen("data.txt", "r");
	//Reading from file
	for (i = 0;;i++)
	{
		if (fscanf(fp, "%d%s%f%f%f%f%f", &record[i].id, record[i].name, &record[i].first, &record[i].second, &record[i].third, &record[i].units, &record[i].amount) == -1)
			break;
	}
	fclose(fp);
	int number = i;
	_number = number;
	printf("\n\t1. Sort by Name\n\t2. Sort by Amount or Units Consumed \n\t3. Sort by ID\n\t4. Sort by Input");
	fflush(stdin);
	printf("\nEnter Choice ");
	scanf("%d", &ch);
	printLine(30);
	printf("\t\tDisplaying previously saved records... :)\n");
	printLine(100);
	printf("\nID\tName\t@1st 100 units\t@Next 100 Units\t@Remaining Units\tUnits Consumed\tAmount");
	printLine(100);
	if (ch == 1)
	{
		for (int j = 0;j < number - 1;j++)
		{
			for (i = 0;i < number - 1;i++)
			{
				if (strcmp(record[i].name, record[i + 1].name) == 1)
				{
					tmp = record[i];
					record[i] = record[i + 1];
					record[i + 1] = tmp;
				}
			}
		}
	}
	else if (ch == 2)
	{
		//Sorting by Amount or Units Consumed
		for (int j = 0;j < number - 1;j++)
		{
			for (i = 0;i < number - 1;i++)
			{
				if (record[i].amount > record[i + 1].amount)
				{
					tmp = record[i];
					record[i] = record[i + 1];
					record[i + 1] = tmp;
				}
			}
		}
	}
	else if (ch == 3)
	{
		//sort by ID
		for (int j = 0;j < number - 1;j++)
		{
			for (i = 0;i < number - 1;i++)
			{
				if (record[i].id > record[i + 1].id)
				{
					tmp = record[i];
					record[i] = record[i + 1];
					record[i + 1] = tmp;
				}
			}
		}
	}

	//printing the records list
	for (i = 0;i < number;i++)
	{
		printf("\n%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", record[i].id, record[i].name, record[i].first, record[i].second, record[i].third, record[i].units, record[i].amount);
	}

	getch();
}
void DisplayWholeDataBase()
{
    struct Record record[50];
	struct Record tmp;
    	FILE* fp = fopen("data.txt", "r");
    int i,number;
    for (i = 0;;i++)
	{
		if (fscanf(fp, "%d%s%f%f%f%f%f", &record[i].id, record[i].name, &record[i].first, &record[i].second, &record[i].third, &record[i].units, &record[i].amount) == -1)
			break;
	}
	number = i;
    for (i = 0;i < number;i++)
	{
		printf("\n%d\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t\t%.2f\t\t%.2f", record[i].id, record[i].name, record[i].first, record[i].second, record[i].third, record[i].units, record[i].amount);
	}
}
void creditsAndTroubleshooting()
{
	printCredits();
	printf("ANAS");
	getch();
}
void choiceError()
{
	printf("Please enter a valid output");
}
void printTitle(char* arr)
{
	printLineSp(50, '*');
	printLine(50);
	puts(arr);
	printLine(50);
	printLineSp(50, '*');
}
void printMenu()
{
	int op;
	int i, ch;
	for (i = 0;i < 10;i++)
	{
		printf("\n");
	}
	printTitle("\tElectricity Billing System");
	cout << "Press 1 to Access Employee Profile" << endl;
	cout << "Press 2 to Access Customer Profile" << endl;
	cin >> op;
	if (op == 1)
	{
		int choice;
		std::cout << "***********************************LOGIN**********************************" << '\n';
		std::cout << "1. Login" << '\n';
		std::cout << "2. Register" << '\n';
		std::cout << "3. Forgot Credentials" << '\n';
		std::cout << "4. Exit" << '\n';
		std::cout << "Enter your choice : " << '\n';
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int x;
			login();

			printf("\n\n 1.\tCalculate Bill\n 2.\tSet Billing Parameters\n3.\tEdit Bill from the database\n 4.\tReview Database\n 5. View DataBase");
			cin >> x;
			switch (x)
			{
			case 1:
				calculateBill();
				break;
			case 2:
				setBillingParameters();
				break;
			case 3:
				editBill();
				break;
			case 4:
				reviewDatabase();
				break;
            case 5:
				DisplayWholeDataBase();
				break;

			default:
				choiceError();
			}
		}

		case 2:
			registr();
			break;
		case 3:
			forgot();
			break;
		case 4:
			std::cout << "Thanks for using the login page" << '\n';
			break;
		default:
			std::cout << "Sorry, wrong choice selected" << '\n';
		}
	}
	else if (op == 2)
	{
		cout << "Press 1 to Calculate Bill" << endl;
		cout << "Press 2 to Edit Bill" << endl;
		cout << "Press 3 to Review DataBase" << endl;
		cout << "Press 4 to  View Whole DataBase" << endl;
		printf("\n\nEnter Choice ");
		cin >> ch;
		switch (ch)
		{
		case 1:
			calculateBill();
			break;
		case 2:
			editBill();
			break;
		case 3:
			reviewDatabase();
			break;
		case 4:
			ViewWholeDataBase();
			break;
		default:
			choiceError();
		}
	}
}
int main()
{
	while (1)
	{
		printMenu();
	}
	return 0;
}
