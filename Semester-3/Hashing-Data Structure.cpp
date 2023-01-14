#include<iostream>
using namespace std;


class LinearProbing {

public:
	int HashTableSize;


	LinearProbing()
	{
		HashTableSize=0;
	}
	int CheckNearestPrimeNumber(int key)

	{
		for(int k = key;;k++)              	{

			bool flag=0;
			int m=k/2;
			int i = 2;
			while ( i <= m)  
			{  
				if(k % i == 0)  
				{

					flag=1;  
					break;  
				}
				i++;
			}  
			if (flag==0)  
				return k;  
		}

	}
	int sizeOfNumber( long long int A)
	{
		int counter=0;
		if(A<=0)
		{
			return 0;
		}
		while(A!=0)
		{
			A=A/10;
			counter++;
		}
		return counter;
	}


	int HashFunction(long long int key)
	{
		long long int firstFiver = key;
		long long int Last7 = key;

		int mid1 = key%1000000;
		int mid2 = key%10000000;

		firstFiver=firstFiver/10000000;
		Last7=Last7%100000000;


		int A = (firstFiver*Last7)%HashTableSize;

		return A;
	}
	int probe(long long int H[],long long int key)
	{
		int index=HashFunction(key);
		int i=0;

		while(H[(index+i)%HashTableSize]!=0)
		{		
			i++;
		}
		return (index+i)%HashTableSize;
	}
	void Insert(long long int H[],long long int key)
	{
		static int counter=1;

		int index=HashFunction(key);

		if(H[index]!=0)
		{
			cout<<"Space not Found(Collision): "<<key<< "  "<<counter++<<endl;
			index=probe(H,key);
		}
		H[index]=key;
	}
	int Search(long long int H[],long long int key)
	{
		int index=HashFunction(key);

		int i=0;

		while(H[(index+i)%HashTableSize]!=key && i!=HashTableSize  )
		{

			if(H[(index+i)%HashTableSize]==0)
			{
				cout<<"Empty Space Found: Key Not Found"<<endl;
				return NULL;
			}
			if(H[(index+i)%HashTableSize]==-1)
			{
				cout<<"Key Deleted"<<endl;
				return NULL;
			}


			i++;

		}
		if(i==HashTableSize)
		{
			cout<<"Whole Table Searched Value Not Found: "<<endl;
			return -1;
		}
		return (index+i)%HashTableSize;
	}

	int Delete(long long int H[],long long int key)
	{
		int index=HashFunction(key);
		int i=0;


		while(H[(index+i)%HashTableSize]!=key && i!=HashTableSize  )
		{

			if(H[(index+i)%HashTableSize]==0)
			{
				cout<<"Empty Space Found: Key Not Found"<<endl;
			}

			i++;

		}
		if(i==HashTableSize)
		{
			cout<<"Whole Table Searched Value Not Found: "<<endl;
			return 0;
		}

		else
		{
			H[(index+i)%HashTableSize]=-1;
			cout<<"Key Successfully Deleted: "<<endl;
		}
	}

	void PrintAllHashTable(long long int H[])
	{
		for(int i = 0 ; i<HashTableSize ; i++)
		{

			cout<<"["<<i<<"]"<<"\t"<<H[i]<<endl;
		}
	}
};


long long myRand(const long long Max, const long long Min = 0)
{
	return rand()/(float)RAND_MAX * (Max-Min) + Min ;
}


class Node
{
public:
	long long int data;
	Node *next;
	Node()
	{
		data=0;
		next=NULL;
	}
};

// Chaining
class Hashing{
public:

	Node *HT[11];

	Hashing()
	{
		for(int i=0;i<11;i++)
			HT[i]=NULL;
	}
	void Insert( Node *&Head,long long x)
	{
		static int count=0;

		Node *newNode;
		newNode = new Node;
		newNode->data = x;
		if(Head==NULL)
		{
			newNode->next = Head;
			Head = newNode;
		}
		else
		{

			Node *newNode;
			newNode = new Node;
			newNode->data = x;
			newNode->next = NULL;

			Node *temp = Head;
			while(temp->next != NULL){
				temp = temp->next;
			}

			temp->next = newNode;

		}
	}

	Node *Search(Node *p,long long int key)
	{
		while(p!=NULL)
		{
			if(key==p->data)
			{
				cout<<"Value Found: "<<endl;
				return p;
			}
			p=p->next;
		}
		{
			cout<<"Value Not Found: "<<endl;
			return NULL;
		}

	}


	int hashFunction(long long int key)
	{

		long long firstFiver = key;
		long long Last7 = key;



		int mid1 = key%1000000;
		int mid2 = key%10000000;



		firstFiver=firstFiver/10000000;
		Last7=Last7%100000000;
		int res = firstFiver%Last7;

		int A = (firstFiver*Last7)%11;

		return A;
	}
	void Insert( long long int key)
	{
		static int counter=0;

		int index=hashFunction(key);
		if(HT[index]!=NULL)
		{
			cout<<"Collision has been Occured: "<<++counter<<endl;
		}
		Insert(HT[index],key);
	}
	void deleteion(Node *p,long long key)
	{

		Node* temp = p;
		Node* prev = NULL;


		if (temp != NULL && temp->data == key)
		{
			p = temp->next;
			delete temp;
			temp=nullptr;
			return;
		}

		else
		{
			while (temp != NULL && temp->data != key)
			{
				prev = temp;
				temp = temp->next;
			}
			if (temp == NULL)
				return;


			prev->next = temp->next;

			delete temp;
			temp=nullptr;
		}
	}
	void Printing(Node*Head)
	{
		Node*t = Head;
		while(t)
		{
			cout<<t->data<<endl;
			cout<<endl;
			t = t->next;
		}

	}
	void WrapperPrint()
{
	for(int i = 0 ; i<11 ; i++)
	{
		cout<<"temp["<<i<<"]"<<endl;
		Printing(HT[i]);
		cout<<"\n-------------------"<<endl;
	}
}
	

	long long myRand(const long long Max, const long long Min = 0)
	{
		return rand()/(float)RAND_MAX * (Max-Min) + Min ;
	}

	void InputData()
	{
		const long long MAX = 9999999999990;
		const long long MIN = 1000000000000;
		int size;
		cout<<"Enter Total Numbers of ID card to be Generated(Chaining): "<<endl;
		cin>>size;

		for(int i = 0; i < size; i++)
		{
			long long int random= myRand(MAX,MIN);
			cout<<random<<endl;
			Insert(random);
		}

	}

	int sizeOfNumber( long long int A)
	{
		int counter=0;
		if(A<=0)
		{
			return 0;
		}
		while(A!=0)
		{
			A=A/10;
			counter++;
		}
		return counter;
	}


	void SearchWrapper()
	{

		bool checkFormat=true;

		cout<<"Enter Number to find: "<<endl;
		long long int input;

		while(checkFormat)
		{
			cin>>input;

			if(sizeOfNumber(input)!=13 || input<=0)
			{
				cout<<"Wrong Number Enter, is not 13!!  Enter Again: "<<endl;
				continue;
			}
			checkFormat=false;
		}	

		Node*temp=Search(HT[hashFunction(input)],input);  // index of 22 and particular key to be Searched
		if(temp==NULL)
		{
			cout<<"Value Has been Deleted: "<<endl;
		}
		else
			cout<<"Value is found!!: "<<temp->data<<endl;
	}

	void deleteNode()
	{
		cout<<"Enter Number to Delete: "<<endl;
		bool checkFormat=true;
		long long int input;

		while(checkFormat)
		{
			cin>>input;

			if(sizeOfNumber(input)!=13 || input<=0)
			{
				cout<<"Wrong Number Enter, is not 13!!  Enter Again: "<<endl;
				continue;
			}
			checkFormat=false;
		}	

		Node*temp=Search(HT[hashFunction(input)],input);
		deleteion(HT[hashFunction(input)],input);
		cout<<"\n------------------------"<<endl<<endl;
	}

	void PrintAll()
	{
		for(int i = 0 ; i<11 ; i++)
		{
			cout<<"\n\n----------------------HashTable["<<i<<"]----------------------"<<endl;
			Printing(HT[i]);
			cout<<"---------------"<<endl<<endl;
		}

	}


};

//---------------------------------------AVL-chaining--------------------------------------------

class NodeAVL
{
public:
	long long int key;
	NodeAVL *left;
	NodeAVL *right;
	int height;
};

int max(int a, int b);

int height(NodeAVL *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

NodeAVL*& newNode(long long int key)
{
	NodeAVL* node = new NodeAVL();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

NodeAVL *& rightRotate(NodeAVL *&y)
{
	NodeAVL *x = y->left;
	NodeAVL *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	return x;
}


NodeAVL *&leftRotate(NodeAVL *&x)
{
	NodeAVL *y = x->right;
	NodeAVL *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	return y;
}

int getBalance(NodeAVL *&N)
{
	if (N == NULL)
		return 0;
	return height(N->left) -
		height(N->right);
}

NodeAVL* insert(NodeAVL *&node, long long int key)
{

	if (node == NULL)
	{
		return(newNode(key));
	}

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;


	node->height = 1 + max(height(node->left),
		height(node->right));
	int balance = getBalance(node);


	if (balance > 1 && key < node->left->key)
		return rightRotate(node);


	if (balance < -1 && key > node->right->key)
		return leftRotate(node);


	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}



NodeAVL *& minValueNode(NodeAVL*& node)
{
	NodeAVL* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

NodeAVL* deleteNode(NodeAVL*& root, long long int key)
{
	static int counter = 0;



	if (root == NULL)
		return root;
	if ( key < root->key )
		root->left = deleteNode(root->left, key);
	else if( key > root->key )
		root->right = deleteNode(root->right, key);


	else
	{
		if( (root->left == NULL) ||
			(root->right == NULL) )
		{
			NodeAVL *temp = root->left ?
				root->left :
			root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else 
				*root = *temp; 
			free(temp);
		}
		else
		{
			NodeAVL* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,
				temp->key);
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + max(height(root->left),
		height(root->right));

	int balance = getBalance(root);


	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


void preOrder(NodeAVL *root)
{
	if(root != NULL)
	{
		cout << root->key << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

void WrapperPrint(NodeAVL**temp)
{
	for(int i = 0 ; i<11 ; i++)
	{
		cout<<"temp["<<i<<"]"<<endl;
		preOrder(temp[i]);
		cout<<"\n-------------------"<<endl;
	}
}

NodeAVL* Search(NodeAVL* root, long long int key)
{
	if (root == NULL || root->key == key)
		return root;

	if (root->key < key)
		return Search(root->right, key);

	return Search(root->left, key);
}

int hashFunction(long long int key)
{

	long long firstFiver = key;
	long long Last7 = key;

	int mid1 = key%1000000;
	int mid2 = key%10000000;



	firstFiver=firstFiver/10000000;
	Last7=Last7%10000000;

	int A = (firstFiver+Last7)%11;

	return A;
}


void main()
{
	const long long MAX = 9999999999999;
	const long long MIN = 1000000000000;
	long long int size;
	long long int * HashTable=NULL;
	int opt;
	LinearProbing obj;

	cout<<"Press 1 for Linear Probing\nPress 2 for Linked-List Chaining\nPress 3 for AVL-Chaining"<<endl<<endl;
	cin>>opt;
	switch(opt)
	{
	case 1:

		{
			int loopBreaker=0;
			int internalopt;

			while(loopBreaker==0)
			{
				cout<<"\tPress 1 for Randomly Genrate ID card\n\tPress 2 for Searching\n\tPress 3 Deleting\n\tPress 4 to Print HashTable"<<endl<<endl;
				cin>>internalopt;

				switch (internalopt)
				{
				case 1:
					{



						cout<<"Enter Total Number of ID cards to be Randomly Generated(13-Digits)"<<endl<<endl;
						cin>>size;

						obj.HashTableSize = obj.CheckNearestPrimeNumber(size);

						cout<<"Size of HashTable would be: "<<obj.HashTableSize<<endl;

						HashTable = new long long int[obj.HashTableSize];

						for(int i = 0 ; i<obj.HashTableSize;i++)
						{
							HashTable[i] = 0;
						}


						for(int i = 0; i < size; i++)
						{

							long long int random= myRand(MAX,MIN);
							cout<<random<<endl;
							obj.Insert(HashTable,random);
						}

						break;
					}
				case 2:
					{
						bool checkFormat=true;

						cout<<"Enter Number to find: "<<endl;
						long long int input;

						while(checkFormat)
						{
							cin>>input;

							if(obj.sizeOfNumber(input)!=13 || input<=0)
							{
								cout<<"Wrong Number Enter, is not 13!!  Enter Again: "<<endl;
								continue;
							}
							checkFormat=false;
						}
						if(HashTable==NULL)
						{
							cout<<"Value not exist: "<<endl;
							break;
						}


						if(obj.Search(HashTable,input)==0)
						{
							cout<<"Key is deleted Already: "<<endl<<endl;
						}
						else
							cout<<"Key is found at"<<obj.Search(HashTable,input);

						break;
					}
				case 3:
					{
						cout<<"\nEnter Number to find for deletion "<<endl;
						long long int input;
						bool checkFormat=true;
						while(checkFormat)
						{
							cin>>input;
							if(obj.sizeOfNumber(input)!=13 || input<=0)
							{
								cout<<"Wrong Number Enter, is not 13!!  Enter Again: "<<endl;
								continue;
							}
							checkFormat=false;
						}

						if(HashTable==NULL)
						{
							cout<<"Value not exist: "<<endl;
							break;
						}
						obj.Delete(HashTable,input);

						break;
					}
				case 4:
					{
						if(HashTable==NULL)
						{
							cout<<"Value not exist: "<<endl;
							break;
						}
						obj.PrintAllHashTable(HashTable);

						break;
					}


				default:
					break;
				}
				cout<<"\nPress any Number to Exit or Zero for Continue;"<<endl<<endl;
				cin>>loopBreaker;

			}
		}

	case 2:
		{
			Hashing obj;
			int loopBreaker=0;
			int internalopt;

			while(loopBreaker==0)
			{
				cout<<"\tPress 1 for Randomly Genrate ID card(Chaining)\n\tPress 2 for Searching(Chaining)\n\tPress 3 Deleting(Chaining)\n\tPress 4 to Print All"<<endl<<endl;
				cin>>internalopt;

				switch (internalopt)
				{
				case 1:
					{
						obj.InputData();		// Insertion has beeen done
						break;
					}
				case 2:
					{
						cout<<endl;
						obj.SearchWrapper();
						break;
					}
				case 3:
					{
						obj.deleteNode();
						break;
					}
				case 4:
					{
						obj.WrapperPrint();
						break;
					}


				default:
					break;
				}
				cout<<"\nPress any Number to Exit or Zero for Continue;"<<endl<<endl;
				cin>>loopBreaker;

			}
		}  
	case 3:
		{
			int loopBreaker=0;
			int internalopt;
			NodeAVL*HT[11]={NULL};

			while(loopBreaker==0)
			{
				cout<<"\tPress 1 for Randomly Genrate ID card(AVL-Chaining)\n\tPress 2 for Searching(AVL-Chaining)\n\tPress 3 Deleting(AVL-Chaining)\n\tPress 4 to Print All"<<endl<<endl;
				cin>>internalopt;

				switch (internalopt)
				{
				case 1:
					{

						for(int i = 0 ; i<11 ; i++)
						{
							HT[i] = NULL;
						}
						int size;
						cout<<"Enter Number of ID cards to Generate: "<<endl;
						cin>>size;

						for(int i = 0; i < size; i++)
						{
							static int counter=0;
							long long int random= myRand(MAX,MIN);
							int index = hashFunction(random);
							cout<<random<<endl;
							if(HT[index]!=NULL)
							{
								cout<<"Collision has been Occured: "<<++counter<<endl;
							}
							HT[index]=insert(HT[index],random);
						}


						break;
					}
				case 2:
					{
						cout<<"Enter Number to Input: "<<endl;
						long long int input;
						bool checkFormat=true;
						while(checkFormat)
						{
							cin>>input;
							if(obj.sizeOfNumber(input)!=13 || input<=0)
							{
								cout<<"Wrong Number Enter, is not 13!!  Enter Again: "<<endl;
								continue;
							}
							checkFormat=false;
						}
						NodeAVL*temp=Search(HT[hashFunction(input)],input);  // index of 22 and particular key to be Searched
						if(temp==NULL)
						{
							cout<<"Value Not Found: "<<endl;
						}
						else
							cout<<"\nValue Found:!!! "<<temp->key<<endl<<endl;
						break;
					}
				case 3:
					{
						cout<<"Delete the values from above List: "<<endl<<endl;
						long long int input1;

						bool checkFormat=true;
						while(checkFormat)
						{
							cin>>input1;
							if(obj.sizeOfNumber(input1)!=13 || input1<=0)
							{
								cout<<"Wrong Number Enter, is not 13!!  Enter Again: "<<endl;
								continue;
							}
							checkFormat=false;
						}
						HT[hashFunction(input1)]==NULL;
						break;

						NodeAVL*temp1=deleteNode(HT[hashFunction(input1)],input1);  // index of 22 and particular key to be Searched
						if(temp1==NULL)
						{
							cout<<"Value Not Found: "<<endl;
						}
						else
							cout<<"Value Found"<<endl;
						break;
					}
				case 4:
					{

						if(HT[0] = NULL)
						{
							cout<<"Table Not Existed: "<<endl;
							break;
						}
						WrapperPrint(HT);
						break;
					}


				default:
					break;
				}
				cout<<"\nPress any Number to Exit or Zero for Continue;"<<endl<<endl;
				cin>>loopBreaker;

			}
			break;
		} 

	default:
		break;
	}


	system("pause");
}