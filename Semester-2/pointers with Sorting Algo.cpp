#include<iostream>
#include<fstream>
using namespace std;

int * GetData(ifstream &, int& );                                // Read Data1.txt & Data2.txt file with pointers
void ShowArr(int*, int);                                         // Showing Data in 1D dynamic Array with pointer iterators
void BubbleSortAlgo(int*, int);                                  // Sorting(e.g Ascending order) with bubble algo & pointers traversal 
void CombinedArrays(int* , int,int, int*, int*);                 // Combined Two array with pointers traversal by comparing two arrays and sorting sequentially

void main()
{
	int lengthOfArr=0;                                           // Size of Array
	ifstream _InputHandler;
	_InputHandler.open("Data1.txt");                                        // Opening the File

	// First Test Case
	int *Getptr = GetData(_InputHandler,lengthOfArr);

	cout<<"CASE:1 = "<<endl;

	cout<<"Before Sorted: "<<endl;
	ShowArr(Getptr,lengthOfArr);
	cout<<"\nAfter Sorted: "<<endl;
	BubbleSortAlgo(Getptr,lengthOfArr);
	ShowArr(Getptr,lengthOfArr);

	// 2nd Test Case

	int *Getptr1 = GetData(_InputHandler,lengthOfArr);

	cout<<"\nCase:2 = "<<endl;

	cout<<"Before Sorted: "<<endl;
	ShowArr(Getptr1,lengthOfArr);
	cout<<"\nAfter Sorted: "<<endl;
	BubbleSortAlgo(Getptr1,lengthOfArr);
	ShowArr(Getptr1,lengthOfArr);


	// 3rd Test Case

	int *Getptr2 = GetData(_InputHandler,lengthOfArr);

	cout<<"\nCASE: 3"<<endl;

	cout<<"Before Sorted: "<<endl;
	ShowArr(Getptr2,lengthOfArr);
	cout<<"\nAfter Sorted: "<<endl;
	BubbleSortAlgo(Getptr2,lengthOfArr);
	ShowArr(Getptr2,lengthOfArr);

	_InputHandler.close();														// Closing the File

	cout<<"\n\n\t\t---------------Merge Two Array---------------\n\n"<<endl;

	int lengthOfarr=0 , lengthOfarr1=0 , lengthOfarr2=0;

	ifstream CombinedGetter("Data2.txt");                                     // Opening the File

	// 1st Case

	int *getData = GetData(CombinedGetter,lengthOfarr);

	cout<<"\t\tTest Case: 1 = \n"<<endl;

	cout<<"Length of Arr1 = "<<lengthOfarr<<endl;
	cout<<"Array1: ";
	ShowArr(getData , lengthOfarr);


	int *getData1 = GetData(CombinedGetter,lengthOfarr1);

	cout<<"\nLength of Arr2 = "<<lengthOfarr1<<endl;
	cout<<"Array2: ";
	ShowArr(getData1 , lengthOfarr1);

	int *CombinationOfTwoArr = new int[lengthOfarr+lengthOfarr1];

	CombinedArrays(CombinationOfTwoArr,lengthOfarr,lengthOfarr1,getData , getData1);
	cout<<"\nCombination is: "<<endl;
	lengthOfarr2 = lengthOfarr+lengthOfarr1;
	ShowArr(CombinationOfTwoArr  , lengthOfarr2);

	delete[] CombinationOfTwoArr;                                                  // DeAllocation of MergedArray

	cout<<"\n`````````````````````````````````````````````````````````````````"<<endl<<endl;

	// 2nd Test Case

	int *getData0 = GetData(CombinedGetter,lengthOfarr);
	cout<<"\t\tTest Case: 2 = \n"<<endl;

	cout<<"Length of Arr1 = "<<lengthOfarr<<endl;
	cout<<"Array1: ";
	ShowArr(getData0 , lengthOfarr);

	int *getData2 = GetData(CombinedGetter,lengthOfarr1);

	cout<<"\nLength of Arr2 = "<<lengthOfarr1<<endl;
	cout<<"Array2: ";
	ShowArr(getData2 , lengthOfarr1);

	int *CombinationOfTwoArr1 = new int[lengthOfarr+lengthOfarr1];

	CombinedArrays(CombinationOfTwoArr1,lengthOfarr,lengthOfarr1,getData0 , getData2);
	cout<<"\nCombination is: "<<endl;
	lengthOfarr2 = lengthOfarr+lengthOfarr1;
	ShowArr(CombinationOfTwoArr1  , lengthOfarr2);

	delete[] CombinationOfTwoArr1;												// DeAllocating the Resultant Array 

	cout<<"\n`````````````````````````````````````````````````````````````````"<<endl<<endl;

	// 3rd Test Case

	int *getData3 = GetData(CombinedGetter,lengthOfarr);
	cout<<"\t\tTest Case: 3 = \n"<<endl;

	cout<<"Length of Arr1 = "<<lengthOfarr<<endl;
	cout<<"Array1: ";
	ShowArr(getData3 , lengthOfarr);

	int *getData4 = GetData(CombinedGetter,lengthOfarr1);

	cout<<"\nLength of Arr2 = "<<lengthOfarr1<<endl;
	cout<<"Array2: ";
	ShowArr(getData4 , lengthOfarr1);

	int *CombinationOfTwoArr2 = new int[lengthOfarr+lengthOfarr1];

	CombinedArrays(CombinationOfTwoArr2,lengthOfarr,lengthOfarr1,getData3 , getData4);
	cout<<"\nCombination is: "<<endl;
	lengthOfarr2 = lengthOfarr+lengthOfarr1;
	ShowArr(CombinationOfTwoArr2  , lengthOfarr2);

	delete[] CombinationOfTwoArr2;                                                        // DeAllocating the MergedArray(sorted_Array)

	cout<<"\n\t\t\Assignment 1 Completed: "<<endl;

	CombinedGetter.close();
	system("pause");
}

void BubbleSortAlgo(int * unsortedptr, int lengthofArr)
{
	if(lengthofArr>0)
	{
		int temp;
		int again = 0;
		int* startingptr = unsortedptr;
		int *endptr = unsortedptr + lengthofArr;
		int* tillStartingptr = unsortedptr;
		while (startingptr < endptr ){
			for (int* tillStartingptr = unsortedptr; tillStartingptr < startingptr; tillStartingptr++)
			{
				if (*startingptr < *tillStartingptr && again==0)                      // Check if Element in startptr is less than element in Endingptr
				{
					temp = *startingptr;
					*startingptr = *tillStartingptr;
					*tillStartingptr = temp;
				}
			}
			startingptr++;

		}
	}
	else
	{
		cout<<"Size is Less than 1: "<<endl;
	}
}

// Checking Size should be Greater than 1 and display all Elements of Array

void ShowArr( int * ShowPtr , int size)
{
	if (size>0)          
	{
		int * endptr = ShowPtr+size;
		do
		{
			cout<<*ShowPtr<<" ";
			ShowPtr++;
		}
		while(ShowPtr<endptr);
		
	}
	else
	{
		return;	
	}
}


int * GetData(ifstream & input , int & ArrSize)
{
	input>>ArrSize;

	if(ArrSize>=1)                            //  To check if size of Array should be Greater than 1
	{
		int * NewArr = new int[ArrSize];
		int * endptr = NewArr+ArrSize;
		int* j = NewArr;

		while(j<endptr)
		{
			input>>*j;
			j++;
		}
		return NewArr;
		delete[] NewArr;
	}
	else
	{
		return 0;
	}
}
void CombinedArrays(int* Combined , int lengthofArr1,int lengthofArr2 , int *unsortedArr1 , int *unsortedArr2)
{
	int temp=0;
	int * i = unsortedArr1 ,  *j = unsortedArr2;
	for( ; lengthofArr1 >0 && lengthofArr2 >0  ; ) 
	{
		if(*i <=*j && lengthofArr1>0 &&lengthofArr2>0)  // To check that if unsortArr1 is less than Arr2 than Adds elelent in Combined
		{
			*Combined = *i;
			i++;
			Combined++;
			lengthofArr1--;
		}
		else
		{
			 *Combined = *j;
			 Combined++;
			 j++;
			 lengthofArr2--;
		}
	}

	for(; lengthofArr1>0 ; Combined++ , lengthofArr1--, i++)   // Remaining Elements of Arr1 add into Combined Array
	{
		temp = *i;		
		*Combined = temp;
	}
	for(; lengthofArr2>0 ; Combined++ , lengthofArr2--, j++) // // Remaining Elements of Arr2 add into Combined Array
	{
		temp = *j;
		*Combined = temp;
	}

}
