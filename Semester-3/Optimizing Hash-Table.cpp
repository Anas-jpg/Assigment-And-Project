#include<iostream>
using namespace std;


/*

For Even , ODD data set Quadratic Hashing Works Best and for Prime Case Double Hashing works best and
for Quadratic there is no clustring so  grouping decreases  and Same case for Double Hashing but for prime numbers they can use another hash function to work best
for Double Hashing.
Linear is worst in all cases due to clustering.

*/


bool PrimeNumber(int n)
{
	int i;
	bool flag = true;

	if (n == 0 || n == 1) {
		flag = false;
	}

	for (i = 2; i <= n/2; ++i) {
		if (n % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}



// for linear probing
class LinearHashing
{
	int TotalSearches;
public:
	LinearHashing()
	{
		TotalSearches=0;
	}

	int getTotalSearches()
	{
		return TotalSearches;
	}
	void TotalSearchesInitalize(int i)
	{
		TotalSearches = i;
	}

	int HashFunction(int key)
	{
		int Key = 101 * ( float (key*0.61) - int (key*0.61));
		return Key;

	}
	int probe(int H[],int key)
	{
		int index=HashFunction(key);
		int i=0;
		while(i<101){
		if(H[(index+i)%101]!=0)
			i++;
		else
		return (index+i)%101;

		}
	}
	void Insert(int H[],int key)
	{
		int index=HashFunction(key);

		if(H[index]!=0)
			index=probe(H,key);
		H[index]=key;
	}
	int Search(int H[],int key)
	{
		int index=HashFunction(key);

		int i=0;


		for(;i<101;i++)
		{	
			if(H[(index+i)%101]==key)
			{
				TotalSearches+= i;
				//cout<<"Total Searches: "<<TotalSearches<<endl;
				return (index+i)%101;
			}

		}


		//cout<<"Value not Found: "<<endl;
		return 0;
	}
};


// for Quadratic
class Quadratic
{
	int totalSearches;
public:

	Quadratic()
	{
		totalSearches=0;
	}

	int getTotalSearches()
	{
		return totalSearches;
	}
	void TotalSearchesInitalize(int i)
	{
		totalSearches = i;
	}

	int HashFunction(int key)
	{
		int Key = 101 * ( float (key*0.61) - int (key*0.61));
		return Key;

	}
	int probe( int H[], int key)
	{
		//static int counter=1;
		int index=HashFunction(key);
		int i=0;

		while(H[(index+i*i)%101]!=0)
		{		
			i++;
		}
		return (index+i*i)%101;
	}
	void Insert(int H[], int key)
	{

		int index=HashFunction(key);

		if(H[index]!=0)
		{
			index=probe(H,key);
		}
		H[index]=key;
	}
	int Search( int H[], int key)
	{
		int index=HashFunction(key);

		int i=0;

		while(H[(index+i*i)%101]!=key && i!=101  )
		{

			if(H[(index+i*i)%101]==0)
			{
				return NULL;
			}
			if(H[(index+i*i)%101]==-1)
			{
				return NULL;
			}


			i++;

		}
		if(i==101)
		{
			//cout<<"Whole Table Searched Value Not Found: "<<endl;
			return -1;
		}
		
		if(i==0)
			i=1;
		totalSearches+=i;

		return (index+i*i)%101;
	}
};

//-------------------------------------------------------------------------------------------------


class DoubleHashing
{
	int totalSearches;
public:

	DoubleHashing()
	{
		totalSearches=0;
	}

	int getTotalSearches()
	{
		return totalSearches;
	}
	void TotalSearchesInitalize(int i)
	{
		totalSearches = i;
	}

	int HashFunction1(int key)
	{
		int Key = 101 * ( float (key*0.61) - int (key*0.61));
		return Key;

	}
	int HashFunction2(int key)
	{
		int Key = 97-(key%97);
		return Key;
	}


	int probe(int H[],int key)
	{


		int i=0;

		for(; i<101;i++)
		{
			int index=HashFunction1(key)+i*HashFunction2(key);
			if (H[(index)%101]==0)
				return (index)%101;
		}
	}
	void Insert(int H[],int key)
	{
		int index=HashFunction1(key);

		if(H[index]!=0)
			index=probe(H,key);
		H[index]=key;
	}
	int Search(int H[],int key)
	{
		int index=HashFunction1(key);

		int i=0;


		for(;i<101;i++)
		{
			int index=HashFunction1(key)+i*HashFunction2(key);
			if(H[(index)%101]==key)
			{
				totalSearches+= i;
				return (index)%101;
			}

		}
		return 0;
	}
};





void main()
{
	LinearHashing A;
	int counter=0;

	int PrimeArr[100];
	int OddNumber[100];
	int EvenNumber[100];

	int HashTablePrime[101]={0};
	int HashTableOdd[101] = {0};
	int HashTableEven[101]= {0};


	for(int i = 0 ;counter<100 ; i++){
		int random = 1+ (rand() % 1000);

		if(PrimeNumber(random))
		{
			PrimeArr[counter] = random;
			cout<<PrimeArr[counter]<<"\t";
			counter++;

			if(counter==10 ||counter==20 || counter==30 ||counter ==40||counter ==50||counter ==60||counter ==70||counter ==80||counter ==90)
				cout<<endl;

		}

	}
	cout<<"\n\n-----------------------ODD-NUMBER----------------------------"<<endl<<endl;

	counter=0;
	while(counter<100)
	{
		int random = 1+ (rand() % 300);
		//	cout<<random<<endl;
		if(random%2!=0)
		{
			OddNumber[counter] = random;
			cout<<OddNumber[counter]<<"\t";
			counter++;
			if(counter==10 ||counter==20 || counter==30 ||counter ==40||counter ==50||counter ==60||counter ==70||counter ==80||counter ==90)
				cout<<endl;

		}

	}

	cout<<"\n\n-----------------------Even-NUMBER----------------------------"<<endl<<endl;

	counter=0;
	while(counter<100)
	{
		int random = 1+ (rand() % 300);
		//	cout<<random<<endl;
		if(random%2==0)
		{
			EvenNumber[counter] = random;
			cout<<EvenNumber[counter]<<"\t";
			counter++;
			if(counter==10 ||counter==20 || counter==30 ||counter ==40||counter ==50||counter ==60||counter ==70||counter ==80||counter ==90)
				cout<<endl;

		}

	}

	// Insering Prime Number
	counter=0;

	for(int i = 0 ;counter<100 ; i++)
	{		
		A.Insert(HashTablePrime,PrimeArr[counter]);		// Insertion using linear Probing
		counter++;

	}

	// Insering ODD Number
	counter=0;

	for(int i = 0 ;counter<100 ; i++)
	{		
		A.Insert(HashTableOdd,OddNumber[counter]);		// Insertion using linear Probing
		counter++;

	}
	// Insering Even Number
	counter=0;

	for(int i = 0 ;counter<100 ; i++)
	{		
		A.Insert(HashTableEven,EvenNumber[counter]);		// Insertion using linear Probing
		counter++;

	}




	int key=50;

	for(int i = key ;key<101 ; i++){

		int random = PrimeArr[i];
		{
			key++;
			A.Search(HashTablePrime,random);
		}

	}

	cout<<"\nTotal Prime Number-(50) Searches for Linear Probing: "<<A.getTotalSearches()<<endl;
	cout<<"\Average Prime Number-(50) Searches for Linear Probing: "<<A.getTotalSearches()/50<<endl;

	A.TotalSearchesInitalize(0);

	key=50;

	for(int i = key ;key<101 ; i++){
		int random = OddNumber[i];

		key++;
		A.Search(HashTableOdd,random);

	}

	cout<<"\nTotal ODD Number (50) Searches for Linear Probing: "<<A.getTotalSearches()<<endl;
	cout<<"\Average ODD Number-(50) Searches for Linear Probing: "<<A.getTotalSearches()/50<<endl;

	A.TotalSearchesInitalize(0);


	key=50;

	for(int i = key ;key<101 ; i++){
		int random = EvenNumber[i];

		key++;
		A.Search(HashTableEven,random);

	}
	cout<<"\nTotal Even Number (50) Searches for Linear Probing: "<<A.getTotalSearches()<<endl;
	cout<<"\Average Even Number-(50) Searches for Linear Probing: "<<A.getTotalSearches()/50<<endl;

	A.TotalSearchesInitalize(0);

	//--------------------------------------------------------------------------------------------









	cout<<"\n\n-----------------Quadratic-------------------------------"<<endl<<endl;

	Quadratic obj;
	int counter2=0;

	int PrimeQuadraticTable[101]={0};
	int ODDQuadraticTable[101] = {0};
	int EvenQuadraticTable[101] = {0};

	for(int i = 0 ;counter2<100 ; i++){

		obj.Insert(PrimeQuadraticTable,PrimeArr[counter2]);		// Insertion using Quadratc
		counter2++;

	}

	counter2=0;

	for(int i = 0 ;counter2<100 ; i++){

		obj.Insert(ODDQuadraticTable,OddNumber[counter2]);		// Insertion using Quadratic
		counter2++;

	}

	counter2=0;

	for(int i = 0 ;counter2<100 ; i++){

		obj.Insert(EvenQuadraticTable,EvenNumber[counter2]);		// Insertion using Quadratic
		counter2++;
	}

	key=50;

	for(int i = key ;key<100 ; i++){
		int random = PrimeArr[i];
		{
			key++;
			obj.Search(PrimeQuadraticTable,random);
		}

	}

	cout<<"\n\n Total Prime Searches for Quadratic: "<<obj.getTotalSearches()<<endl;
	cout<<"\Average Prime Number-(50) Searches for Quadratic: "<<(float)obj.getTotalSearches()/50<<endl;

	obj.TotalSearchesInitalize(0);

	key=50;

	for(int i = key ;key<100 ; i++){
		int random = OddNumber[i];
		{
			key++;
			obj.Search(ODDQuadraticTable,random);
		}

	}

	cout<<"\n\n Total Odd Searches for Quadratic: "<<obj.getTotalSearches()<<endl;
	cout<<"\Average Odd Number-(50) Searches for Quadratic: "<<(float)obj.getTotalSearches()/50<<endl;

	obj.TotalSearchesInitalize(0);

	key=50;

	for(int i = key ;key<100 ; i++){

		int random = EvenNumber[i];
		{
			key++;
			obj.Search(EvenQuadraticTable,random);
		}

	}

	cout<<"\n\n Total Even Searches for Quadratic: "<<obj.getTotalSearches()<<endl;
	cout<<"\Average Even Number-(50) Searches for Quadratic: "<<(float)obj.getTotalSearches()/50<<endl;

	obj.TotalSearchesInitalize(0);

	cout<<"\n\n---------------------------------Double Hashing---------------------------------"<<endl<<endl;

	DoubleHashing db;
	int counter3=0;

	int PrimeDoubleTable[101]={0};
	int OddDoubleTable[101] = {0};
	int EvenDoubleTable[101] = {0};

	for(int i = 0 ;counter3<100 ; i++){

		db.Insert(PrimeDoubleTable,PrimeArr[counter3]);		// Insertion using Double Hashing
		counter3++;

	}

	counter3=0;
	for(int i = 0 ;counter3<100 ; i++){

		db.Insert(OddDoubleTable,OddNumber[counter3]);		// Insertion using Double Hashing
		counter3++;

	}

	counter3=0;
	for(int i = 0 ;counter3<100 ; i++){

		db.Insert(EvenDoubleTable,EvenNumber[counter3]);		// Insertion using Double Hashing
		counter3++;

	}

	key=50;

	for(int i = key ;key<100 ; i++){
		//int random = 1+ (rand() % 1000);
		int random = PrimeArr[i];
		{
			key++;
			db.Search(PrimeDoubleTable,random);
		}

	}

	cout<<"\nTotal Searches Prime for Double Hashing: "<<db.getTotalSearches()<<endl;
	cout<<"\Average Prime Number-(50) Searches for Double Hashing: "<<(float)db.getTotalSearches()/50<<endl;

	db.TotalSearchesInitalize(0);

	key=50;

	for(int i = key ;key<100 ; i++){
		//int random = 1+ (rand() % 1000);
		int random = OddNumber[i];
		{
			key++;
			db.Search(OddDoubleTable,random);
		}

	}

	cout<<"\nTotal Searches Odd for Double Hashing: "<<db.getTotalSearches()<<endl;
	cout<<"\Average Odd Number-(50) Searches for Double Hashing: "<<(float)db.getTotalSearches()/50<<endl;

	db.TotalSearchesInitalize(0);

	key=50;

	for(int i = key ;key<100 ; i++){

		int random = EvenNumber[i];
		{
			key++;
			db.Search(EvenDoubleTable,random);
		}

	}

	cout<<"\nTotal Searches Even for Double Hashing: "<<db.getTotalSearches()<<endl;
	cout<<"\Average Even Number-(50) Searches for Double Hashing: "<<(float)db.getTotalSearches()/50<<endl;

	db.TotalSearchesInitalize(0);


	system("pause");
}