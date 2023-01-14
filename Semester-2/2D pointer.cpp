#include<iostream>
#include<fstream>
using namespace std;

void DeAllocateMemory(int** , const int& );
int **_Intialize2dArr(int,int);
int** get2dArr( ifstream& , int& , int&);
void DisplayMatrix(int**, const int& , const int&);
int**TransposeOfMatrix(int ** , int, int);
void InterchangeRows(int** , const int&, const int&);
void InterchangeRows(int*&, int*& );
int** additionof2dArr(int**, int**, int, int );
bool SymmetricChecker(int **,int,int);

int **_Intialize2dArr(int rows,int cols)        // Helper Function to Intialize the Array
{
	int ** Get2dArr = new int*[rows];
	int **i = Get2dArr;
	while(i<Get2dArr+rows)
	{
		*i = new int[cols];
		i++;
	}
	return Get2dArr;
}

// Q1. Input 2d Array from a File
int** get2dArr( ifstream& fin, int& rows, int& cols)
{
	fin>>rows;
	fin>>cols;

	int **Get2Arr = _Intialize2dArr(rows,cols);
	int **ith = Get2Arr;
	while(ith<Get2Arr+rows)
	{
		for(int *jth  = *ith ; jth<*ith+cols ; jth++)
		{
			fin>>*jth;
		}
		ith++;
	}
	return Get2Arr;
}

// Q2. Display the 2d Matrix
void DisplayMatrix(int** matrix, const int& ROWS, const int& COLS)
{
	int **Startptr = matrix;
	while(Startptr<matrix+ROWS)                    // show Elements from baseAddress to the size of Rows in it.
	{
		int *jth = *Startptr;
		while( jth<*Startptr+COLS)
		{
			cout<<*jth<<" ";
			jth++;
		}
		cout<<endl;
		Startptr++;
	}
}

// Q3. Simply Addition of two Matrices
int** additionof2dArr(int** Arr1, int** Arr_2, int LengthOfRow, int LengthOfCol)
{


	if(LengthOfRow==LengthOfCol)											// Checking Rows are Equal to Columns
	{

		int ** ResultArr = _Intialize2dArr(LengthOfRow,LengthOfCol);		// Intializing 2d-Arr(with pointer iterators)
		int **Rowitr = ResultArr;

		int **i = Arr1;

		while(i<Arr1+LengthOfRow){                                        // Copying Array-1 Elements in Resultant Array
			int *j = *i,*Colitr = *Rowitr;

			while(j<LengthOfCol+*i)
			{
				*Colitr = *j;
				j++,Colitr++;
			}
			i++,Rowitr++;
		}

		int **Rowitr2 = ResultArr;
		int **ith = Arr_2;

		while(ith<Arr_2+LengthOfRow ){                                  // Adding Array-2 Elements into Resultant Array
			int *j = *ith,*Colitr = *Rowitr2;
			while( j<LengthOfCol+*ith)
			{
				*Colitr+= *j;

				j++,Colitr++;

			}
			ith++,Rowitr2++;
		}

		return ResultArr;
	}
	else
	{
		cout<<"Addition is Not Possible: "<<endl;
		return 0;
	}
}

//Q4. Transpose Matrix

int**TransposeOfMatrix(int **Arr , int Row , int Column)
{

	int **TransposedOfMatrix = _Intialize2dArr(Column,Row);         // Intialize 2d-Array on Heap
	
	for(int i = 0 ; i<Column ; i++)
		for(int j = 0 ; j<Row;j++)
			*(*(TransposedOfMatrix + i) + j) = *(*(Arr + j) + i);    // Copying Columns Elements into Rows Elements
		return TransposedOfMatrix;

}

// Q5. Checking the Symmetric of a Matrix
bool SymmetricChecker(int **Arr,int Row,int Columns)
{
	bool Checker=true;
	int **GetTranspose = TransposeOfMatrix(Arr,Row,Columns);

	int ith = 0;
	while (ith < Row){
		int jth = 0;
		while (jth < Columns){
			if (*(*(Arr + ith) + jth)!=*(*(GetTranspose + ith) + jth))           // Checking that the Transpose of the Matrix is equal to Matrix
				Checker=false;
			jth++;
		}
		ith++;
	}
	return Checker;
}

//q7. Simply Interchanging the Rows
void InterchangeRows(int*& Row1, int*& Row2)
{
	int* Result = Row1;
	Row1 = Row2;
	Row2 = Result;
}

// Q6. Interchaning the Two Rows by 
void InterchangeRows(int** Arr, const int& ROWS, const int& COLS)
{
	int lengthofRow1 = 0;                                   // Hard-Coded Values of Interchanging Rows
	int	lengthofRow2 = 2;

	cout<<"Interchanging Rows of Matrix A: "<<endl;

	cout<<"Row1: "<<lengthofRow1+1<<endl;
	cout<<"Row2: "<<lengthofRow2+1<<endl;

	InterchangeRows(*(Arr + lengthofRow1),*(Arr + lengthofRow2));
}

// DeAllocate the Matrix
void DeAllocateMemory(int** matrix, const int& rows)
{
	int i = 0;
	if(matrix!=NULL){
	while(i < rows)
	{
		delete[] matrix[i];
		i++;
	}
	delete[] matrix;
	matrix = 0;
	}
}
void main()
{
	int lengthOfRows,lengthOfCols,lengthOfRows2,lengthOfCols2,lengthOfRows3,lengthOfCols3;
	ifstream fin;
	fin.open("InputFile.txt");																// Opening the File

	int **Get2dArr = get2dArr(fin,lengthOfRows,lengthOfCols);
	cout<<"A Matrix is: "<<endl;
	DisplayMatrix(Get2dArr,lengthOfRows,lengthOfCols);

	cout<<"-----------------"<<endl;
	int **Get2dArr2 = get2dArr(fin,lengthOfRows2,lengthOfCols2);
	cout<<"\nThe B matrix is: "<<endl;
	DisplayMatrix(Get2dArr2,lengthOfRows2,lengthOfCols2);

	cout<<"\n-----------------------"<<endl;
	int **Get2dArr3 = get2dArr(fin,lengthOfRows3,lengthOfCols3);
	cout<<"\nThe C matrix is: "<<endl;
	DisplayMatrix(Get2dArr3,lengthOfRows3,lengthOfCols3);

	fin.close();																			// Closing the File

	
	cout<<"\n-----------------------"<<endl;
	cout<<"A+B = "<<endl;

	int **AdditionMatrix = additionof2dArr(Get2dArr,Get2dArr2,lengthOfRows,lengthOfCols);
	DisplayMatrix(AdditionMatrix,lengthOfRows,lengthOfCols);
	DeAllocateMemory(AdditionMatrix,lengthOfRows);                                        // DeAllocating Addition Matrix Arr

	cout<<"\nA+C = "<<endl;

	int **AdditionMatrix2 = NULL;
	AdditionMatrix2 = additionof2dArr(Get2dArr,Get2dArr3,lengthOfRows3,lengthOfCols);
	DeAllocateMemory(AdditionMatrix2,lengthOfRows3);									//  DeAllocating Addition Matrix2 Arr

	cout<<"-----------------------"<<endl;

	cout<<"\nTranspose Of Matrix A: "<<endl;
	int **Transpose = TransposeOfMatrix(Get2dArr,lengthOfRows,lengthOfCols);
	DisplayMatrix(Transpose,lengthOfRows,lengthOfCols);
	DeAllocateMemory(Transpose,lengthOfRows);										// DeAllocating the Memory of TransposeMatrix A


	cout<<"\nTranspose Of Matrix C: "<<endl;
	int **Transpose2 = TransposeOfMatrix(Get2dArr3,lengthOfRows3,lengthOfCols3);
	DisplayMatrix(Transpose2,lengthOfCols3,lengthOfRows3);
	DeAllocateMemory(Transpose2,lengthOfRows);										 // DeAllocating the Memory of TransposeMatrix C

	DeAllocateMemory(Get2dArr3,lengthOfRows3);										 // DeAllocating the the Third Input 2d-Arr
	
	cout<<"---------------------------"<<endl;

	bool SymetricCheckerA=SymmetricChecker(Get2dArr, lengthOfRows, lengthOfCols);
	if (SymetricCheckerA)
	{
		cout << "\nThe matrix A is Symmetric:" << endl;
	}
	else
	{
		cout << "\nThe matrix A is not Symmetric:" << endl;
	}
	bool SymetricCheckerB=SymmetricChecker(Get2dArr2, lengthOfRows2, lengthOfCols2);
	if (SymetricCheckerB)
	{
		cout << "\nThe matrix B is Symmetric:" << endl;
	}
	else
	{
		cout << "\nThe matrix B is not Symmetric:" << endl;
	}
	DeAllocateMemory(Get2dArr2,lengthOfRows2);							// DeAllocate Memory of 2nd Input-Array

	cout<<"-------------------------"<<endl;

	InterchangeRows(Get2dArr,lengthOfRows,lengthOfCols);

	cout<<"\nAfter Interchanging of Matrix A: "<<endl;
	DisplayMatrix(Get2dArr,lengthOfRows,lengthOfCols);

	DeAllocateMemory(Get2dArr,lengthOfRows);							// DeAllocate Memory of 1st Input-Array;
	

	system("pause");
}