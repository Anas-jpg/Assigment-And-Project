#include<iostream>
using namespace std;
#define Max_Size 100
void Show_Array( int A[], int startIndex, int endIndex)
{
   		cout<<"Please Enter StartIndex Value to  EndIndex Valiue : "<<endl<<endl;
   		cout<<"Start Index Value"<<endl;
   		cin >> startIndex;
   		cout<<"End Index Value"<<endl;
		cin >> endIndex;
		int i;
		cout<<" Showing Array from Start Index To End Index : "<<endl<<endl;
			for (i = startIndex; i <= endIndex; i++)
			{
				A[i]=i;
				cout<<A[i]<<" ";
			}
		return ;
}
void Show_Array( int A[], int s)
{
		cout<<"Please Enter  value : ";
    	int i;
		for( i = 0 ; i<=s;i++)
			{
				A[i]=i;	
				cout<<A[i]<<" ";
			}	
	return;
}

void Input_Array(int A[], int startIndex, int endIndex)
{
		int i;
		cout<<"Please Enter Starting Value and Ending Value : ";
		cin>>startIndex>>endIndex;
		for(i = startIndex ; i<=endIndex ; i++)
			{
				A[i]=i;
				cin>>A[i];
			}
	return;
}
void Input_Array(int A[], int s)
{
	
		cout<<"Enter n integer : ";
		int i;
			for(int i = 0 ; i<s;i++ )
				{
					cin>>A[i];
				}
	return;
}
int selectionSort ( int A[], int n)
{
int i , j, small, temp;
for( i=0 ; i < n-1 ; i++)
 {
 	small = i;
 	for( j=i+1 ; j < n ; j++)
{
  	if ( A[j] < A[small] )
  	small = j;
}
 	temp = A[i];
 	A[i] = A[small];
 	A[small] = temp;
 }
}
void BubbleSort(int A[], int n) 
{
		int flag , k , i, temp;
 		for( k=1; k<n ; k++)
 			{
  				flag = 0;
   				for( i=0 ; i<n-k ; i++)
   			{
    			if(A[i] >A[i+1])
    		{
    			temp = A[i];
    			A[i] = A[i+1];
    			A[i+1] = temp;
    			flag = 1;
			}
   			}
  				if(flag == 0 )
  				break;
  			}
}
void Add_Arrays( int A[], int B[],int C[], int s)
{
		int c;
		int sum[Max_Size];
		cout << "Enter the N of Elements in the Array : ";
  		cin >> s;
  		cout << "Enter Elements of First Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> A[c];
  		cout << "Enter Elements of Second Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> B[c];
  		cout << "Sum of Elements of the Arrays:" << endl;
  		for (c = 0; c < s; c++)
		   {
    	sum[c] = A[c] + B[c];
    	cout << sum[c] <<" ";
    		}
}

void Sub_Arrays( int A[],  int B[], int C[], int s)
{
   		int c;
		int sum[Max_Size];
		cout << "Enter the N of Elements in the Array : ";
  		cin >> s;
  		cout << "Enter Elements of First Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> A[c];
  		cout << "Enter Elements of Second Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> B[c];
  		cout << "Sub of Elements of the Arrays:" << endl;
  		for (c = 0; c < s; c++)
		   	{
    	sum[c] = A[c] - B[c];
    	cout << sum[c] <<" ";
    		}
}

void Mul_Arrays( int A[],  int B[], int C[], int s){
    
		int c;
		int sum[Max_Size];
		cout << "Enter the N of Elements in the Array : ";
  		cin >> s;
  		cout << "Enter Elements of First Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> A[c];
  		cout << "Enter Elements of Second Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> B[c];
  		cout << "Mul of Elements of the Arrays:" << endl;
  		for (c = 0; c < s; c++)
		   	{
    	sum[c] = A[c] * B[c];
    	cout << sum[c] <<" ";
    		}
}

int Mul_Polynomial_Arrays( int A[],  int B[], int C[], int s)
{
	int i,j;
	for(i=0;i<s;i++)
	{
		cin>>A[i];
	}
	for(i=0;i<s;i++)
	{
		cin>>B[i];
	}
	for(i=0;i<s;i++)
	for(j=0;j<s;j++)
	C[i+j]=C[i+j]+A[i]*B[j];
	cout<<C[i+j];
}

int Mul_Dot_Arrays( int A[],  int B[], int s)
{
	cout<<"Input n numbers of array : ";
	cin>>s;
	cout<<"Enter 1st array ";
	for(int i=0;i<s;i++)
	cin>>A[i];
	cout<<"Enter 2nd array ";
	for(int i=0;i<s;i++)
	cin>>B[i];
	int product=0;
	for(int i = 0; i<s ; i++)
	product=product+A[i]*B[i];
	return product;
}
void Div_Arrays( int A[],  int B[], int C[], int s)
{
	
		int c;
		int sum[Max_Size];
		cout << "Enter the N of Elements in the Array : ";
  		cin >> s;
  		cout << "Enter Elements of First Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> A[c];
  		cout << "Enter Elements of Second Array" << endl;
  		for (c = 0; c < s; c++)
    	cin >> B[c];
  		cout << "Division of Elements of the Arrays:" << endl;
  		for (c = 0; c < s; c++)
		   	{
    	sum[c] = A[c] / B[c];
    	cout << sum[c] <<" ";
			}
}
void mergeArrays(int arr1[], int arr2[],int merge[], int size1, int size2)                             
{ 
	int  i, j, k,size;
	cout<<"Enter Array 1 Size : ";
	cin>>size1;
	cout<<"Enter Array 1 Elements : ";
	for(i=0; i<size1; i++)
	{
		cin>>arr1[i];
	}
	cout<<"Enter Array 2 Size : ";
	cin>>size2;
	cout<<"Enter Array 2 Elements : ";
	for(i=0; i<size2; i++)
	{
		cin>>arr2[i];
	}
	for(i=0; i<size1; i++)
	{
		merge[i]=arr1[i];
	}
	int n;
	n=size=size1+size2;
	for(i=0, k=size1; k<size && i<size2; i++, k++)
	{
		merge[k]=arr2[i];
	}
	int C[Max_Size];
	int flag , temp;
 	for( k=1; k<n ; k++)
 		{
  			flag = 0;
   			for( i=0 ; i<n-k ; i++)
   		{
    	if(merge[i] >merge[i+1])
    		{
    			temp = merge[i];
    			merge[i] = merge[i+1];
    			merge[i+1] = temp;
    			flag = 1;
    		}
   }
  				if(flag == 0 )
  				break;
  		}
		cout<<"Sorted Array : "<<endl;
		for(i=0; i<n; i++)
		cout<<merge[i]<<" ";	
}
void MultiPoly(int a[], int b[],int c[], int n)
{ 
		
		cout<<"Enter Degree ";
		cin>>n;
		cout<<"Enter 1st Array Element : "<<endl;
	 	for(int i = 0 ; i<n;i++)
		cin>>a[i];
		cout<<"Enter 2nd Array Element : "<<endl;
		for(int j = 0 ; j<n;j++)
		cin>>b[j];
		for(int k=0 ;k<n ; k++)
		c[k]=0;
		for(int i = 0;i<n;i++)
		for(int j = 0; j<n;j++)
		c[i+j]+=a[i]*b[j];
		for(int k =0 ; k<=n ; k++)
		cout<<c[k]<<" ";
		return;
} 
void printPoly(int poly[], int n) 
{ 
	for (int i=0; i<n; i++) 
	{ 
	cout << poly[i];
	if (i != n-1) 
	cout << " + "; 
	} 
} 
void displayArray1(int A[],int n)
{
 int i;
 for(i=0;i<n;i++)
	cout<<A[i]<<" "; cout<<"\n";
}
int main()
{
    int F[Max_Size], S[Max_Size], A[Max_Size],B[Max_Size],C[Max_Size];
    int start,end,n,c,s;
    cout<<"                 Please Enter Number 1 to 12 to perform specific operation \t "<<endl<<endl;
    cout<<"1 : Show Array from start value to End Value " <<endl;
    cout<<"2 : Show All elements of Array "<<endl;
    cout<<"3 : Input integer values specified by the user between the StartIndex and endIndex "<<endl;
    cout<<"4 : Input n integer in a Array"<<endl;
    cout<<"5 : Sort Array by Selection"<<endl;
    cout<<"6 : Sort Array By Bubble Algo "<<endl;
    cout<<"7 : Add Two arrays point by point"<<endl;
    cout<<"8 : Subtract Two Arrays "<<endl;
    cout<<"9 : Multiply of Two Arrays "<<endl;
    cout<<"10 : Divide two arrays"<<endl;
    cout<<"11 : Merge two Arrays"<<endl;
    cout<<"12 : Dot Product of Two Vectors "<<endl;
    cout<<"13 : Polynomial Multiplication of Two array"<<endl<<endl;
    cin>>n;
    switch(n)
    {
    	case 1:
				{
					Show_Array(A,start,end);
					break;		
				}
		case 2:
				{
						cin>>s;
						cout<<"please enter n value";
					Show_Array(A,s);
					break;
				}
		case 3:
				{
					Input_Array(A,start,end);
					break;
				}
		case 4:
				{
						cin>>s;
					Input_Array(A, s);
					break;
				}
		case 5: 
				{
					int n;
 						cout<<"enter size of array\n"; cin>>n;
 						int A[n],e,i,ans;
 						cout<<"enter elements of array\n";

 						for(i=0;i<n;i++)
 						cin>>A[i]; 
 						cout<<"Array before sorting\n";

 						displayArray1(A,n);

 						selectionSort(A,n);

 						cout<<"Array after sorting\n";
 						displayArray1(A,n);
 						break;
				}
		case 6:
				{
						int n,i,e;
 						cout<<"enter number of elements\n";
 						cin>>n;
 						int A[n];
 						cout<<"enter elements\n";
 						for(i=0;i<n;i++)
 						cin>>A[i];
 						cout<<"Array before sorting:\n";
 						displayArray1(A,n);
 						BubbleSort(A,n);
 						cout<<"Array after sorting:\n";
 						displayArray1(A,n);
 						break;
				}
		case 7:
				{
						Add_Arrays(A,B,C,s);
						break;		
				}
		case 8:
				{
					    Sub_Arrays(A,B,C,s);
					    break;
				}
		case 9:
				{
					
						Mul_Arrays(A,B,C,s);
						break;
				}
		case 10:
				{
						Div_Arrays(A,B,C,s);
						break;
				}
		case 11:
				{
						int n,i,e,m;
						int D[Max_Size];
 						mergeArrays(A,B,C,n,m);
 						break;
 						
				}
		case 12:
					{
						cout<<"Dot Product is : "<<Mul_Dot_Arrays(A,B,s);
						break;
					}
		case 13:
					{
								int n;
								MultiPoly(A,B,C,n);
								break;
					}
	}
 					return 0;	
				}
