#include<iostream>
using namespace std;


// ----------------------Question No 1(a)--------------------------------------------

int* leftShift(int A[],int x,int y,int size)
{
	int subarrsize = y-x;
	int *Arr = new int[size];

	int k=0;
	if(x>y || x>size|| y>size)
	{
		cout<<"X should not be greater than y: "<<endl;
	}

	if(x==0)
	{
		return A;
	}
	for(int i = x ; i<=y ; i++,k++)
	{
		Arr[k] = A[i];
	}
	int sizectr=0;

	for(int i = x ,z=y+1; i<y ; i++,z++)
	{
		A[i] = A[z];
		sizectr++;
	}

	for(int i = 0 ; i<size-subarrsize ; i++,k++)
	{
		Arr[k] = A[i];
	}

	return Arr;
}

int* rightShift(int A[],int x,int y,int size)
{
	int subarrsize = y-x;
	int *Arr = new int[size];

	int i = x;
	int k=0;
	int counter=0;
	for(int i = x ; i<=y ; i++,k++)
	{
		Arr[k] = A[i];
		counter++;

		cout<<"Arr[k]"<<Arr[k]<<endl;
	}
	int temp;
	if(x==0)
	{
		temp = y+1;
	}
	else
		temp = y;
	for( int z=y+1; i<temp ; i++,z++)
	{		
		A[i] = A[z];
		cout<<"Arr[i]"<<A[i]<<endl;
	}


	// 1 2 3 4
	for(int s = 0 ; s<counter ; s++,i++)
	{
		A[i] = Arr[s];

	}

	cout<<"---------------"<<endl;
	return A;
}
// Helper Functions
void shift_Right(int A[],int xpos,int ypos)
{

	if(A[xpos]<A[ypos]){
		int lastElement = A[ypos];

		for(int i = ypos ; i>xpos ; i--)
		{
			A[i] = A[i-1];
		}

		A[xpos] = lastElement;
	}

}
void Swap(int A[],int xpos,int ypos)
{

	if(A[xpos]<A[ypos]){
		int temp= A[xpos];
	A[xpos] = A[ypos];
	A[ypos] = temp;
	}

}

// Q2 implementing Sorting Algo with Shifting

void maxSort_Shifting(int ArrayUnsorted[],int size)
{

	int Key = ArrayUnsorted[0];

	for(int ith = 0 ; ith<size-1 ; ith++)
	{
		int ypos=ith;
		// finding Greatest Element

		for(int i = ith ; i<size ; i++)
		{				
			if(ArrayUnsorted[i]>Key)
			{
				Key = ArrayUnsorted[i];
				ypos = i;
			}
		}
		// -----------------------
		shift_Right(ArrayUnsorted,ith,ypos);

	}

}

// Q2 implementing Sorting Algo with Swapping

void maxSort_Swapping(int ArrayUnsorted[],int size)
{
	int pos=0;
	for(int ith = 0 ; ith<size-1 ; ith++)
	{
		int Key = ArrayUnsorted[ith];
		// finding Greatest Element

		for(int jth = ith ; jth<size ; jth++)
		{				
			if(ArrayUnsorted[jth]>Key)
			{
				Key = ArrayUnsorted[jth];
				pos = jth;
			}
		}
		// -----------------------Swapping Elements-----------------------
		Swap(ArrayUnsorted,ith,pos);

	}
}

void PrintArray(int ArrayUnsorted[],int size){

	for(int i = 0 ; i<size ; i++)
	{
		cout<<ArrayUnsorted[i]<<",";
	}
	cout<<endl;
}

void main()
{
	int size;
	int xpos,ypos;
	int key;
	while(1)
	{
		cout<<"Press 1 to Exit:\nPress 2 for Left Shif\nPress 3 for Right Shift\nPress 4 for Max Sort using Swap\nPress 5 for Max Sort Using Shifting: "<<endl<<endl;
		cin>>key;

		if(key==1)
		{
			return;
		}
		else if(key==2)
		{
			cout<<"Enter Size of Array: "<<endl;
			cin>>size;
			int *ArrayUnsorted = new int[size];
			cout<<"Enter Elements: "<<endl;
			for(int i = 0 ; i<size; i++)
			{
				cin>>ArrayUnsorted[i];
			}
			cout<<"\nEnter x position"<<endl;
			cin>>xpos;
			cout<<"Enter y positon: "<<endl;
			cin>>ypos;
			leftShift(ArrayUnsorted,xpos,ypos,size);
			PrintArray(ArrayUnsorted,size);

			cout<<"-------------"<<endl; 
		}
		else if(key==3)
		{
			cout<<"Enter Size of Array: "<<endl;
			cin>>size;
			int *ArrayUnsorted = new int[size];
			cout<<"Enter Elements: "<<endl;
			for(int i = 0 ; i<size; i++)
			{
				cin>>ArrayUnsorted[i];
			}
			cout<<"\nEnter x position"<<endl;
			cin>>xpos;
			cout<<"Enter y positon: "<<endl;
			cin>>ypos;
			rightShift(ArrayUnsorted,xpos,ypos,size);
			PrintArray(ArrayUnsorted,size);
		}
		else if(key==4)
		{
			cout<<"Enter Size of Array: "<<endl;
			cin>>size;
			int *ArrayUnsorted = new int[size];
			cout<<"Enter Elements: "<<endl;
			for(int i = 0 ; i<size; i++)
			{
				cin>>ArrayUnsorted[i];
			}
			maxSort_Swapping(ArrayUnsorted,size);

			cout<<"\nArray-Sorted:\t"<<endl;
			PrintArray(ArrayUnsorted,size);
		}
		else if(key==5)
		{
			cout<<"Enter Size of Array: "<<endl;
			cin>>size;
			int *ArrayUnsorted = new int[size];
			cout<<"Enter Elements: "<<endl;
			for(int i = 0 ; i<size; i++)
			{
				cin>>ArrayUnsorted[i];
			}
			maxSort_Shifting(ArrayUnsorted,size);

			cout<<"\nArray-Sorted:\t"<<endl;
			PrintArray(ArrayUnsorted,size);
		}

	}
	system("pause");
}