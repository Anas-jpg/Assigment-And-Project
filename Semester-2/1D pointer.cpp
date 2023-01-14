#include<iostream>
using namespace std;

int* InputArray(int& ArrSize);                           // Exercise # 1 of Lab 2
void OutputArray(int* myArray, const int& ArrSize);      // Exercise # 2 of Lab 2
int* CompressArray(int* Arrayptr, int& ArrSize);         // Exercise # 3 of Lab 2
int* Intersection(int* setA, int ArrSize1, int* setB, int& ArrSize2, int& ArrSize3);  // Exercise # 4 of Lab 2

int main()
{
	cout<<"---------------------------------Lab No.1----------------------------------"<<endl<<endl;
	cout<<"---------------------------------Exercise#3-------------------------------------"<<endl;

	int num1, num2, sum;
	int* xptr;
	int* yptr;
	int* sumptr;
	
	num1 = 5;
	num2 = 7;
	sum = 0;
	xptr = nullptr;					    // xptr point to NULL
	yptr = nullptr;                     
	sumptr = nullptr;
	cout <<"Num1 ="<< num1 << endl;
	cout << "Num2 =" << num2 << endl;

	cout << "Address of Num1 =" << &num1 << endl;
	cout << "Address of Num2 =" << &num2 << endl;
	xptr = &num1;                                            // Storing the Address of Num1 
	yptr = &num2;
	sumptr = &sum;
	cout << "*xptr = " << *xptr<<endl;
	cout << "*yptr = " << *yptr << endl;
	cout << "*sumptr = " << *sumptr<<endl;
	sum = *xptr + *yptr;
	cout << "*sumptr = " << *sumptr<<endl;
	cout << "xptr = " << xptr << endl;
	cout << "yptr = " << yptr << endl;

	cout<<endl<<endl<<"-----------------------------------Expanded Array(Exercise#4)-----------------------"<<endl<<endl;

	int size = 5;
	int NewSize = size;
	int PrintSize = size;
	int counter = 0;
	int digit;
	
	int *aptr;
	int *bptr;
	int ConditionChecker=0;

	int ptrTracker = 0;
	int *Arr = new int[size];
	cout<<"Enter Numbers till -1: "<<endl;
	int i = 0;
	while(cin>>digit)
	{
		*(Arr+counter) = digit;
		counter++;
		if(counter<size && digit==-1)                          // To check if the inputted numbers are less than given size and user pressed "-1"
		{
			cout<<"Numbers in Reverse Order are: "<<endl;
			for(int i = counter-2; i>=0 ; i--)
			{
				cout<<*(Arr+i)<<" ";
			}
			ConditionChecker = 1;
			break;
		}
		if(digit==-1)
		{
			break;
		}
		if(counter>=size)
		{
			NewSize=size+size;
			int *newARR = new int[NewSize];
			for(int j = 0; j<size ; i++, j++)
			{
				*(newARR+i) = *(Arr+j);
			}
			aptr = newARR;
			size=size+size;
			delete[] Arr;                                        //  Deleting the previous Array when limit is reached
			Arr = new int[size];
			counter = 0;

		}

	}
	if(ConditionChecker==0)
	{
		cout<<"Numbers in Reverse Order are: "<<endl;
		for(int i = counter-2; i>=0 ; i--)
		{
			cout<<*(Arr+i)<<" ";
			ptrTracker = 1;
		}

	}	
	for(int i = PrintSize-1 ; i>=0 ;i--)
	{
		cout<<aptr[i]<<" ";
	}

	// 2nd Lab started

	cout<<endl<<endl<<"---------------------------------------------------Lab-No # 2 --------------------------------------"<<endl<<endl;
	cout<<"------------------------------------Exercise # 3 Compressed Array-----------------------------------"<<endl<<endl;

	int sizeofArr1,sizeofArr2;
	int sizeofArr3=0;

	cout << "Enter ArrSize: "<<endl;
	cin >> sizeofArr1;

	int *Arrayptr=InputArray(sizeofArr1);
	cout << "Data:\t";
	OutputArray(Arrayptr, sizeofArr1);

	cout <<endl << "Array after Elements of Compression: ";
	int* CompressedArr = CompressArray(Arrayptr, sizeofArr1);
	OutputArray(CompressedArr, sizeofArr1);
	cout<<endl;

	cout << endl << "------------------------------------------------------" << endl;
	cout<<endl<<"------------------------Exercise # 4 Intersection of Array Array---------------------------------"<<endl<<endl;
	
	cout << "Enter ArrSize of 1st Array: " << endl;
	cin >> sizeofArr1;
	
	int* Arr1 = InputArray(sizeofArr1);                     
	cout << "Enter ArrSize of 2nd Array: " << endl;
	cin >> sizeofArr2;
	cout << "Enter Elements of 2nd Array: " << endl;
	
	int* Arr2 = InputArray(sizeofArr2);
	int* intersection = Intersection(Arr1, sizeofArr1, Arr2, sizeofArr2, sizeofArr3);
	cout << "The intersection is: "<<endl<<endl;
	OutputArray(intersection, sizeofArr3);

	system("pause");
}

// Exercise 1 [Input Array]

int* InputArray(int &ArrSize)  
{
	cout<<"Enter Elements of Array: "<<endl;
	int* tempArray = new int[ArrSize];                                                       // Dynamically Created 1-D Array of Given Size
	int* i = tempArray;
	while(i < tempArray + ArrSize)
	{
		cin >> *i;
		i++;
	}
	return tempArray;                                                                      // Returning the Base-Address of the Inputed Array
}

// Exercise 2 [Output Array]
void OutputArray(int* myArray, const int& ArrSize)
{
	int *i = myArray;
	while(i<myArray+ArrSize) 
	{
		cout<<*i<<" ";
		i++;
	}
	cout<<endl;
}

// Exercise 3 [Compress Array] 

int* CompressArray(int* Arrayptr, int& ArrSize)
{
	int counterOfArray = 0;
	int* _newArr = new int[ArrSize];
	int *i = Arrayptr;
	int* temp = _newArr;                               // 
	while(i < Arrayptr + ArrSize)
	{
		if(*i!=*(i+1))                                // Checking if the Number is duplicate then ignore if it is unique than store in temp Array
		{
			counterOfArray++;
			*temp = *i;
			temp++;
		}
		i++;
	}
		delete[] Arrayptr;                           // DeAllocating the Array
		Arrayptr = 0;
		temp = 0;
		ArrSize = counterOfArray;
		return _newArr;
	
}

//   Exercise# 4 [Intersection]

int* Intersection(int* setA, int ArrSize1, int* setB, int& ArrSize2, int& ArrSize3)
{

	// Checking the Size of Array which contains the same elements in an Array

	for(int *i = setA ; i<setA+ArrSize1 ; i++)
		for(int *j = setB ; j<setB+ArrSize2 ; j++)
		{
			if((*i)==(*j))
			{
				ArrSize3++;
			}
		}
	int* _newArr = new int[ArrSize3];
	int* temp = _newArr;

	for (int* i = setA; i < setA + ArrSize1; i++) {
		for (int* j = setB; j < setB + ArrSize2; j++)
		{
			if (*i == *j)
			{
				*temp = *i;
				 temp++;
			}
		}
	}
	delete [] setA;
	delete [] setB;
	return _newArr;                        // Returning the Base Addresss of Intersected Array
}


