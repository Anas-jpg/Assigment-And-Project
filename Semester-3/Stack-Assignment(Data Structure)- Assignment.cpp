#include<iostream>
using namespace std;
#include<string>
class Node
{
public:
	Node * Next;
	Node*Head;
	char data;
public:
	Node(int size)
	{	
		Next=NULL;
	}
	Node()
	{
		Head=NULL;
		Next=NULL;
	}
	void push(char element)
	{
		Node*t = new Node;
		if(t==NULL)
		{
			cout<<"Stack OverFlow: "<<endl;
		}
		else
		{
			t->data = element;
			t->Next = Head;
			Head = t;
		}
	}
	int pop()
	{
		Node*p;
		char x = -1;
		if(Head==NULL)
		{
			cout<<"Stack UnderFlow: "<<endl;
		}
		else{
			p = Head;
			Head = Head = Head->Next;
			x = p->data;
			delete p;
		}
		return x;
	}
	bool isEmpty()
	{
		if(Head==NULL)
		{
			return true;
		}
		else
			return false;
	}

	void Display()
	{
		Node*temp= Head;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->Next;
		}
	}

	int checkPrecedent(char str)
	{
		if(str=='+' || str=='-')
		{
			return 1;
		}
		else if(str=='*' || str=='/')
		{
			return 2;
		}
		else if (str=='(' ||  str==')')
		{
			return 3;
		}
		else return 0;
	}

	bool isOperand(char str)
	{
		if(str=='+' || str=='-' || str=='*' || str=='/' || str==')'|| str=='(' || str=='^')
		{
			return false;
		}
		else
			return true;
	}

	bool isOperandNew(char str)
	{
		if(str=='+' || str=='-' || str=='*' || str=='/' )
		{
			return true;
		}
		else if(str==')'|| str=='(' || str=='^')
		{
			return false;
		}
		else
			return false;
	}



	int Eval(char *postfix)
	{
		string table;
		char Table[20];
		int i=0;
		int x1,x2,r=0 ;
		int k = 0;
		for(i=0;postfix[i]!='\0';i++)
		{
			if(isOperand(postfix[i]))
			{				
				push(postfix[i]-'0');
				table += postfix[i];

			}
			else
			{
				table+='\n';				
				x2=pop();
				x1=pop();
				table = table+std::to_string(x1);
				table +='\t';
				table = table+std::to_string(x2);

				switch(postfix[i])
				{

				case '+':
					{r=x1+x2;
					table +='\t';
					table +='+';
					table +='\t';
					break;
					}
				case '-':r=x1-x2; 
						 {
							 table +='\t';
							 table +='-';
							 table +='\t';

							 break;
						 }
				case '*':r=x1*x2;
						 {
							 table +='\t';
							 table +='*';
							 table +='\t';

							 break;
						 }
				case '/':
					{
						table +='\t';
						table +='/';
						table +='\t';

						r=x1/x2;
						break;
					}
				case '^':
					{
						table +='\t';
						table +='^';
						table +='\t';
						r = pow(x1,x2); 
						break;
					}
				}

				push(r);
				table = table+std::to_string(r);
				table +='\n';

			}
		}
		cout<<"--------------Stack Printed:------------------"<<endl;
		cout<<table<<endl;

		return Head->data;
	}

	int prec(char str)
	{
		if(str=='^')
		{
			return 3;
		}
		else if(str=='*' || str=='/')
		{
			return 2;
		}
		else if (str=='+' ||  str=='-')
		{
			return 1;
		}
		else return -1;
	}

	char* infixtoPostFix(char*s)
	{
		int k = 0;
		int size = strlen(s);
		char* res  = new char[size+2];
		for(int i = 0 ; s[i]!='\0' ; i++)
		{

			if((s[i]>='a'&&s[i]<='z')|| (s[i]>='A'&&s[i]<='Z'))
			{
				res[k++]=s[i];
			}
			else if(s[i]=='(')
			{
				push(s[i]);
			}
			else if(s[i]==')')
			{
				while(!isEmpty() && Head->data!='(')
				{
					res[k++]=Head->data;
					pop();
				}
				if(!isEmpty())
				{
					pop();
				}
			}
			else
			{
				while(!isEmpty() && prec(Head->data)>prec(s[i]))
				{
					res[k++]=Head->data;
					pop();
				}
				push(s[i]);

			}

		}
		while(!isEmpty())
		{
			res[k++]=Head->data;
			pop();
		}
		res[k] = '\0';
		return res;


	}
	bool identifyInfix(char*str)
	{
		for(int i=0;str[i]!='\0';i++)
		{
			if(isOperandNew(str[i]))
			{
				int k = i;
				if(isOperandNew(str[k+1]))
				{
					cout<<"Not Matched: "<<endl;
					return false;
				}
			}
			else if((str[i]>='a'&&str[i]<='z')|| (str[i]>='A'&&str[i]<='Z'))
			{
				int k = i;
				if((str[k+1]>='a'&&str[k+1]<='z')|| (str[k+1]>='A'&&str[k+1]<='Z'))
				{
					cout<<"Not Matched: "<<endl;
					return false;
				}
			}
		}
		cout<<"Matched: "<<endl;
		return true;
	}



};

void main()
{
	int choice;
	cout<<"Enter 1 to convert infix to PostFix: "<<endl;
	cout<<"Enter 2 to Evalue the PostFix: "<<endl;

	cin>>choice;
	switch(choice)
	{
	case 1:
		{
			char*b = "A*B+C*D";
			char*a = "623+-382/+*2^3+";
			Node  A;

			if(A.identifyInfix(b)){
				char* AB=A.infixtoPostFix(b);
				cout<<"PostFix: "<<AB<<endl<<endl;
			}
			break;
		}
	case 2:
		{
			char*a = "23*54*+";
			Node  A;
			cout<<"\n--------------------------------------"<<endl;
			cout<<"\n-----for Evaluation---------"<<endl;
			{
				cout<<"\n The Evaluation Result is: "<<A.Eval(a)<<endl;
			}
			break;
		}
	default:
		break;
	}

	system("pause");
}