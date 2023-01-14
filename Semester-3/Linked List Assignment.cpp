#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
	string name;
	 long long int ID;
	string Role;
	float salary;
	Node*next;

};

Node*head = NULL;

void insertNewRecord(long long int id,string name,string Designation,float salary)
{
	Node*newNode;
	Node*currNode;
	Node*prevNode;

			newNode = new Node;
			newNode->ID   = id;
			newNode->name = name;
			newNode->Role = Designation;
			newNode->salary=salary;

			newNode->next=nullptr;

			if(!head)
			{
				head=newNode;
			}
			else
			{
				currNode=head;
				if(id<head->ID)
				{
					newNode->next=head;
					head=newNode;
				}
				else
				{
					while(currNode &&currNode->ID<id){
						prevNode=currNode;
						currNode=currNode->next;
					

					}
					if(!currNode)
					{
						prevNode->next=newNode;
					}
					else
					{
						newNode->next=currNode;
						prevNode->next=newNode;
					}
				}
			}		

		cout<<"\t-----\"Record SuccessFully Added:\"-----"<<endl;

}

void ShowRecord()
{
	Node*Show = head;
	
	if(Show==NULL)
	{
		cout<<"-------\"No Record Available:\"-------"<<endl;
	}

	while(Show!=NULL)
	{
		cout<<"ID:\t"<<Show->ID<<endl;
		cout<<"Role:\t"<<Show->Role<<endl;
		cout<<"Name:\t"<<Show->name<<endl;
		cout<<"Salary:\t"<<Show->salary<<endl;
		cout<<"-------------------------------"<<endl;
		Show = Show->next;
	}
}

void deleteEmployeeData(int empID)
{
	int pos=0;
	// Creating the Record

	Node*Show = head;
	
	if(Show==NULL)
	{
		cout<<"-------\"No Record Available:\"-------"<<endl;
		return;
	}
		Node*location = head;

		// this loop will check the accurate position by comparing the id will all previous records until end
		
		
		while(location!=NULL)
		{
			
			if(location->ID==empID)
			{
				break;
			}
				pos++;
			location = location->next;
		}

		if(pos==0)
		{
			Node*p = head;
			head = head->next;
			delete p;
		}
		else
		{
			Node*p = head;
			Node*q = NULL;

			for(int i = 0 ; i<pos&& p ; i++)
			{
				q=p;
				p = p->next;
			}
			if(p)
			q->next = p->next;
			delete p;
		}	
}

void updateEmployeeData(int empID)
{
	string updatedRole;

		Node*location = head;

		Node*Show = head;
	
	if(Show==NULL)
	{
		cout<<"-------\"No Record Available:\"-------"<<endl;
		return;
	}
		
		// this loop will check the accurate position by comparing the id will all previous records until end
		
		
		while(location!=NULL)
		{
			
			if(location->ID==empID)
			{
				cout<<"Employee Found!!: "<<endl;
				break;
			}
			location = location->next;
		}

		cout<<"Enter New Role of employee: "<<endl;
		cin>>updatedRole;
		location->Role = updatedRole;
		cout<<"\n\t-----\"Role Updated SuccessFully:\" "<<endl;

}
void main()
{
	string name,role;
	float salary;
	long long int id=0;
	int key =0;
	Node*head = NULL;
	while(1)
	{		
		cout<<"\n \"Enter 0 to exit\"\n \"Enter 1 to Insert New Record\"\n \"Enter 2 to Delete Record\"\n \"Enter 3 to Update the Record\"\n \"Enter 9 to display\"\"\n"<<endl;
		cin>>key;
		cout<<"\n------------------\n"<<endl;

		if(key==0)
		{
			break;
		}
		else if(key==1)
		{
			cin.ignore();
			cout<<"Enter Name: "<<endl;
			getline(cin,name);
			cout<<"Enter Role: "<<endl;
			getline(cin,role);
			cout<<"Enter Salary: "<<endl;
			cin>>salary;
			cout<<"Enter ID: "<<endl;
			cin>>id;
			insertNewRecord(id,name,role,salary);
			
		}
		else if(key==2)
		
		{
			cout<<"Enter ID: "<<endl;
			cin>>id;
			deleteEmployeeData(id);
		}
		
		else if(key==3)
		
		{
			cout<<"Enter ID: "<<endl;
			cin>>id;
			updateEmployeeData(id);
		
		}
		
		else if(key==9)
		{
			ShowRecord();
		}
	}
	
	system("pause");
}