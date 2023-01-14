/*

Name:	Muhammad Anas
RollNo: 20L-1306
Email:	l201306@lhr.nu.edu.pk


*/

#include<iostream>
#include<string>
using namespace std;

class CentralBank;	

class Database;

class Node
{
public:

	Database *d1;
	Node*Arr[10];
	Node()
	{
		for(int i = 0 ; i<10 ; i++)
		{
			Arr[i] = NULL;
		}
	}
};

class Database
{
public:
	string branchCode;
	string Gender;
	string AccountType;
	int accountNumber;
	int depositMoney;
	string TransactionHistory[6];
	int counter;
	char IDList[100];
	int coupon;
	string getAccType()
	{
		return AccountType;
	}
	Database()
	{
		accountNumber = 0;
		depositMoney = 0;
		counter = 0;
		coupon=0;
	}
	string getGender()
	{
		return Gender;
	}
	bool RemoveFundMoney(int funds)
	{
		if(depositMoney<funds)
		{
			cout<<"Insufficient Balance: "<<endl;
			return false;
		}
		else
		{
			depositMoney -=funds;
			return true;
		}
	}
	Database(char *str)
	{
		coupon=0;
		counter= 0;
		//-----------------Set Branch Code--------------//
		branchCode = str[0];

		branchCode += str[1];

		branchCode += str[2];

		// Set Gender

		int genFinder = int(str[3])-48;
		if( genFinder==0 || genFinder==1 || genFinder==2 || genFinder==3 || genFinder==4)
			Gender = "Male";
		else if(genFinder==5 || genFinder==6 || genFinder==7 || genFinder==8 || genFinder==9 )
			Gender = "Female";
		// AccType
		int accType = int(str[4])-48;
		if(accType==0)
			AccountType = "Current";
		else if(accType==1)
			AccountType = "Saving";
		else if(accType==2)
			AccountType = "Salary";
		else if(accType==3)
			AccountType = "Education";
		else if(accType==4)
			AccountType = "IT";
		else if(accType==5)
			AccountType = "Government";
		else if(accType==6)
			AccountType = "Bonds";
		else if(accType==7)
			AccountType = "Foreign";
		else if(accType==8)
			AccountType = "Agriculture";
		else if(accType==9)
			AccountType = "Ehsas";

		// AccNumber
		accountNumber = int(str[5])-48;
		accountNumber*=10;
		accountNumber += int(str[6])-48;
		accountNumber*=10;
		accountNumber += int(str[7])-48;
		accountNumber*=10;
		accountNumber += int(str[8])-48;
		depositMoney = 0;
	}

	void print()
	{
		{
			cout<<"Gender: "<<Gender<<endl;
			cout<<"Branch Code: "<<branchCode<<endl;
			cout<<"Bank Type: "<<AccountType<<endl;
			cout<<"Account Number: "<<accountNumber<<endl;
			cout<<"Deposit Money: "<<depositMoney<<endl;
			cout<<"Coupons: "<<coupon<<endl;
			cout<<"Transaction History:\t";
			for(int i = 0 ; i<counter;i++)
			{
				cout<<TransactionHistory[i]<<"\t";
			}
			cout<<endl<<endl;
		}
	}
	void DepositMoney(int money)
	{
		depositMoney += money;
		GetCoupon(money);

		if(counter>=5)
		{
			counter=4;
		}
		TransactionHistory[counter++]="+"+to_string(money);	
		if(counter>0)
			RightShift();

		cout<<"MoneyAdded SuccessFully: "<<endl;
	}

	void GetCoupon(int money)
	{
		if(money>5000)
		{
			coupon = 250;
			cout<<"Congratulations! Coupon is Transferred to your Account: "<<endl;
		}

	}

	void WithDrawalMoney(int money)
	{
		if(depositMoney<=0)
		{
			cout<<"Insufficient Balance: "<<endl;
		}

		else
			depositMoney -= money;
		if(counter>=5)
		{
			counter=4;
		}
		TransactionHistory[counter++]="-"+to_string(money);	
		if(counter>0)
			RightShift();

		cout<<"MoneyWithDrawal SuccessFully: "<<endl;
	}
	string getBranchCode()
	{
		return branchCode;
	}

	void PrintTransactionHistory()
	{
		cout<<"Transaction History:\t";
		if(counter==0)
		{
			cout<<"No Transaction has been Made: "<<endl;
		}
		else{
			for(int i = 0 ; i<counter;i++)
			{
				cout<<TransactionHistory[i]<<"\t";
			}
			cout<<endl<<endl;
		}
	}
	void RightShift()
	{
		string temp=TransactionHistory[counter-1];

		for(int i=counter-1;i>0;i--)
		{
			TransactionHistory[i]=TransactionHistory[i-1];
		}
		TransactionHistory[0] = temp;
	}




};

class CentralBank
{
	long int hugeAmount;
	int x;
public:
	CentralBank()
	{
		hugeAmount = 999999;

		x = 0;
	}

	void MoneyDeposit(int depMoney)
	{
		hugeAmount-=depMoney;
	}

	void withDrawalMoney(int wdrawal)
	{
		hugeAmount+=wdrawal;
	}

	long int getMoney()
	{
		return hugeAmount;
	}

	void PrintCentralBankStat()
	{
		cout<<"Central Bank Reserves: "<<hugeAmount<<endl;
	}
	friend class Tree;
};

class Tree
{
	Node*root;
	CentralBank obj;
	int s;
public:
	Tree()
	{
		s = 0;
		root = NULL;
	}


	void insertData(char*str)
	{

		int counter = 0;
		int level;

		if(root==NULL)
			root = new Node;

		Node*temp=root;
		int size = strlen(str);
		while (counter< size)
		{
			level = (int)str[counter] - 48;


			if(temp->Arr[level]==NULL)
			{
				temp->Arr[level] = new Node;
			}

			temp = temp->Arr[level];

			counter++;

			if(counter==9 && temp!=NULL)
			{
				temp->d1 = new Database(str);
			}



		}

	}



	Node* Searching( char*str)
	{
		bool flag = true;
		int counter = 0;
		int level;
		Node*temp=root;

		while (counter<9)
		{
			level = (int)str[counter] - 48;

			if(temp->Arr[level]==NULL)
			{
				cout<<"\n\n----------------------Not Existed:---------------------- "<<endl;
				break;
			}
			temp = temp->Arr[level];
			counter++;

			if(counter==9 && temp!=NULL)
			{

				flag= false;
				cout<<"Found"<<endl<<endl;

				if(temp->d1!=NULL)
					return temp;
				return NULL;
			}
		}
		if(flag)
		{
			cout<<"----------------------Not Found:---------------------- "<<endl;
		}

	}


	Node*GetRoot()
	{
		return root;
	}


	void Deletion(char* str)
	{
		Node*  temp = Searching(str);
		delete temp->d1;
		temp->d1 = NULL;	


	}

	void DepositMoney(char* ID,int money)
	{
		Node* A = Searching(ID);
		A->d1->DepositMoney(money);
		obj.MoneyDeposit(money);
	}

	void WithDrawalMoney(char* ID,int money)
	{
		Node* A = Searching(ID);
		A->d1->WithDrawalMoney(money);
		obj.withDrawalMoney(money);
	}

	void print(char* ID)
	{
		Node*temp = Searching(ID);
		if(temp->d1!=NULL){
			temp->d1->print();
			obj.PrintCentralBankStat();
			cout<<"\n-------------------------------------"<<endl;
		}
		else
		{
			cout<<"No Data Existed: "<<endl;
		}

	}
	void TransFerDeposit(int fund,char*Id1,char*Id2)
	{
		Node*temp = Searching(Id1);
		Node*temp2 = Searching(Id2);

		if(temp->d1->RemoveFundMoney(fund))
		{
			temp->d1->WithDrawalMoney(fund);
			temp2->d1->DepositMoney(fund);

			cout<<"Funds TransFer Successfully: "<<endl;
		}
	}

	void printCommonBranch(Node *root,string branchcode)
	{
		if (!root  )
			return;

		if (!root->Arr[0] && !root->Arr[1]&& !root->Arr[2]&& !root->Arr[3]&& !root->Arr[4]&& !root->Arr[5] && !root->Arr[6]&& !root->Arr[7]&& !root->Arr[8]&& !root->Arr[9] && root->d1->getBranchCode()==branchcode && root->d1!=NULL)
		{
			if(root->d1!=NULL){
				root->d1->print();
				return;
			}

		}
		if (root->Arr[0] && root->Arr[0]->d1!=NULL)
			printCommonBranch(root->Arr[0],branchcode);

		if (root->Arr[1] && root->Arr[1]->d1!=NULL)
			printCommonBranch(root->Arr[1],branchcode);
		if (root->Arr[2]&& root->Arr[2]->d1!=NULL )
			printCommonBranch(root->Arr[2],branchcode);
		if (root->Arr[3]&& root->Arr[3]->d1!=NULL)
			printCommonBranch(root->Arr[3],branchcode);
		if (root->Arr[4]&& root->Arr[4]->d1!=NULL)
			printCommonBranch(root->Arr[4],branchcode);
		if (root->Arr[5]&& root->Arr[5]->d1!=NULL)
			printCommonBranch(root->Arr[5],branchcode);
		if (root->Arr[6]&& root->Arr[6]->d1!=NULL)
			printCommonBranch(root->Arr[6],branchcode);
		if (root->Arr[7]&& root->Arr[7]->d1!=NULL )
			printCommonBranch(root->Arr[7],branchcode);
		if (root->Arr[8]&& root->Arr[8]->d1!=NULL)
			printCommonBranch(root->Arr[8],branchcode);
		if (root->Arr[9]&& root->Arr[9]->d1!=NULL)
			printCommonBranch(root->Arr[9],branchcode); 
	}

	void PrintSameBranchCode(string branchCode)
	{
		printCommonBranch(root,branchCode);
	}


	void printMaleOnly(Node *root,string gender)
	{
		if (!root)
			return;

		if (!root->Arr[0] && !root->Arr[1]&& !root->Arr[2]&& !root->Arr[3]&& !root->Arr[4]&& !root->Arr[5] && !root->Arr[6]&& !root->Arr[7]&& !root->Arr[8]&& !root->Arr[9] && root->d1->getGender()==gender)
		{
			if(root->d1!=NULL){
				root->d1->print();
			}
			else
			{
				cout<<"No Data Existed: "<<endl;
			}
			return;

		}
		if (root->Arr[0]&& root->Arr[0]->d1!=NULL)
			printMaleOnly(root->Arr[0],gender);

		if (root->Arr[1]&& root->Arr[1]->d1!=NULL)
			printMaleOnly(root->Arr[1],gender);
		if (root->Arr[2]&& root->Arr[2]->d1!=NULL)
			printMaleOnly(root->Arr[2],gender);
		if (root->Arr[3]&& root->Arr[3]->d1!=NULL)
			printMaleOnly(root->Arr[3],gender);
		if (root->Arr[4]&& root->Arr[4]->d1!=NULL)
			printMaleOnly(root->Arr[4],gender);
		if (root->Arr[5]&& root->Arr[5]->d1!=NULL)
			printMaleOnly(root->Arr[5],gender);
		if (root->Arr[6]&& root->Arr[6]->d1!=NULL)
			printMaleOnly(root->Arr[6],gender);
		if (root->Arr[7]&& root->Arr[7]->d1!=NULL)
			printMaleOnly(root->Arr[7],gender);
		if (root->Arr[8]&& root->Arr[8]->d1!=NULL)
			printMaleOnly(root->Arr[8],gender);
		if (root->Arr[9]&& root->Arr[9]->d1!=NULL)
			printMaleOnly(root->Arr[9],gender); 
	}

	void PrintAllMale(string gender)
	{
		printMaleOnly(root,gender);
	}

	//-------------------------------------------------------------


	void printMaleBranchSpecific(Node *root,string branchcode)
	{
		if (!root)
			return;

		if (!root->Arr[0] && !root->Arr[1]&& !root->Arr[2]&& !root->Arr[3]&& !root->Arr[4]&& !root->Arr[5] && !root->Arr[6]&& !root->Arr[7]&& !root->Arr[8]&& !root->Arr[9] && root->d1->getBranchCode()==branchcode && root->d1->getGender()=="Male")
		{
			if(root->d1!=NULL){
				root->d1->print();
			}
			else
			{
				cout<<"No Data Existed: "<<endl;
			}
			return;

		}
		if (root->Arr[0] && root->Arr[0]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[0],branchcode);

		if (root->Arr[1]&& root->Arr[1]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[1],branchcode);
		if (root->Arr[2]&& root->Arr[2]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[2],branchcode);
		if (root->Arr[3]&& root->Arr[3]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[3],branchcode);
		if (root->Arr[4]&& root->Arr[4]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[4],branchcode);
		if (root->Arr[5]&& root->Arr[5]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[5],branchcode);
		if (root->Arr[6]&& root->Arr[6]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[6],branchcode);
		if (root->Arr[7]&& root->Arr[7]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[7],branchcode);
		if (root->Arr[8]&& root->Arr[8]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[8],branchcode);
		if (root->Arr[9]&& root->Arr[9]->d1!=NULL)
			printMaleBranchSpecific(root->Arr[9],branchcode); 
	}

	void PrintMaleBranchCommon(string branchCode)
	{
		printMaleBranchSpecific(root,branchCode);
	}

	//------------------------------Salary Specific Account--------------------------------

	void SalarySpecific(Node *root,string AccType)
	{
		if (!root)
			return;

		if (!root->Arr[0] && !root->Arr[1]&& !root->Arr[2]&& !root->Arr[3]&& !root->Arr[4]&& !root->Arr[5] && !root->Arr[6]&& !root->Arr[7]&& !root->Arr[8]&& !root->Arr[9] && root->d1->getAccType()==AccType )
		{
			if(root->d1!=NULL){
				root->d1->print();
			}
			else
			{
				cout<<"No Data Existed: "<<endl;
			}
			return;

		}
		if (root->Arr[0]&& root->Arr[0]->d1!=NULL)
			SalarySpecific(root->Arr[0],AccType);

		if (root->Arr[1]&& root->Arr[1]->d1!=NULL)
			SalarySpecific(root->Arr[1],AccType);
		if (root->Arr[2]&& root->Arr[2]->d1!=NULL)
			SalarySpecific(root->Arr[2],AccType);
		if (root->Arr[3]&& root->Arr[3]->d1!=NULL)
			SalarySpecific(root->Arr[3],AccType);
		if (root->Arr[4]&& root->Arr[4]->d1!=NULL)
			SalarySpecific(root->Arr[4],AccType);
		if (root->Arr[5]&& root->Arr[5]->d1!=NULL)
			SalarySpecific(root->Arr[5],AccType);
		if (root->Arr[6]&& root->Arr[6]->d1!=NULL)
			SalarySpecific(root->Arr[6],AccType);
		if (root->Arr[7]&& root->Arr[7]->d1!=NULL)
			SalarySpecific(root->Arr[7],AccType);
		if (root->Arr[8]&& root->Arr[8]->d1!=NULL)
			SalarySpecific(root->Arr[8],AccType);
		if (root->Arr[9]&& root->Arr[9]->d1!=NULL)
			SalarySpecific(root->Arr[9],AccType); 
	}

	void PrintSalarySpecific(string branchCode)
	{
		SalarySpecific(root,branchCode);
	}

	void PrintTransactionHistory(char* ID)
	{
		Node*temp = Searching(ID);
		if(temp->d1!=NULL){
			temp->d1->PrintTransactionHistory();
		}
		else
		{
			cout<<"No Data Existed: "<<endl;
		}
	}
};


void main()
{
	Tree obj;
	char buffer[80];
	int opt;

	while(1)
	{
		cout<<"Enter 1 to insert Data:\nEnter 2 to Delete Account Number:\nEnter 3 to Print Data:\nEnter 4 to Deposit Money:\nEnter 5 to Withdrawal Money:\nEnter 6 to Transfer Funds between Two Accounts"<<endl;
		cout<<"\tEnter 7 to print SameBranch Account:\n\tEnter 8 to print Male Accounts Only:\n\tEnter 9 to Print Male Branch Specific Account:\n\tEnter 10 to Print Salary Type Account:\n\t Enter 11 to Display Transaction History "<<endl;
		cout<<"----------------^^^^^^^^^^^^^^^^^^^--------------------------"<<endl<<endl;
		cin>>opt;
		switch(opt)
		{
		case 1:
			{
				cout<<"Enter Account Number for Insertion"<<endl;
				cin>>buffer;
				if(strlen(buffer)>9 || strlen(buffer)<9)
					cout<<"Enter Valid Account Number: "<<endl;
				else{
					obj.insertData(buffer);
					cout<<"Successfully Added: "<<endl;
				}

				break;
			}
		case 2:
			{
				cout<<"Enter Account Number for Deletion"<<endl;
				cin>>buffer;
				if(strlen(buffer)>9 || strlen(buffer)<9)
					cout<<"Enter Valid Account Number: "<<endl;
				else
					obj.Deletion(buffer);
				cout<<"Successfully Deleted: "<<endl;
				break;
			}
		case 3:
			{
				cout<<"Enter Account Number for Display"<<endl;
				cin>>buffer;
				if(strlen(buffer)>9 || strlen(buffer)<9)
					cout<<"Enter Valid Account Number: "<<endl;
				else
					obj.print(buffer);
				break;
			}

		case 4:
			{
				int money;
				cout<<"Enter Account Number for Deposit Money"<<endl;
				cin>>buffer;
				if(strlen(buffer)>9 || strlen(buffer)<9)
					cout<<"Enter Valid Account Number: "<<endl;
				else{
					cout<<"Enter Money to Deposit: "<<endl;
					cin>>money;
					obj.DepositMoney(buffer,money);
				}
				break;
			}
		case 5:
			{
				int money;
				cout<<"Enter Account Number for WithDrawal Money"<<endl;
				cin>>buffer;
				if(strlen(buffer)>9 || strlen(buffer)<9)
					cout<<"Enter Valid Account Number: "<<endl;
				else{
					cout<<"Enter Money to Withdrawal: "<<endl;
					cin>>money;
					obj.WithDrawalMoney(buffer,money);
				}
				break;

			}
		case 6:
			{
				char Buffer2[80];
				int money;
				cout<<"Enter Account Number For Funds Transfer"<<endl;
				cin>>buffer;
				cout<<"Enter 2nd account Number where Funds to Transfer"<<endl;
				cin>>Buffer2;

				if(strlen(buffer)>9 || strlen(buffer)<9)
					cout<<"Enter Valid Account Number: "<<endl;
				else{
					cout<<"Enter Money to Transfer: "<<endl;
					cin>>money;
					obj.TransFerDeposit(money,buffer,Buffer2);
				}
				break;
			}
		case 7:
			{
				cout<<"Enter Branch Code to Check All Accounts of that Branch: "<<endl;
				cin>>buffer;
				obj.PrintSameBranchCode(buffer);
				break;
			}
		case 8:
			{			
				string A = "Male";
				obj.PrintAllMale(A);
				break;
			}
		case 9:
			{
				cout<<"Enter Branch Code to Check All Accounts  of male accounts on that Branch: "<<endl;
				cin>>buffer;
				obj.PrintMaleBranchCommon(buffer);
				break;
			}
		case 10:
			{

				string B = "Salary";
				obj.PrintSalarySpecific(B);
				break;
			}
		case 11:
			{
				cout<<"Enter Account Number to Display the History: "<<endl;
				cin>>buffer;
				obj.PrintTransactionHistory(buffer);
			}
		default:
			break;
		}
	}
	system("pause");
}