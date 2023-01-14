#include<iostream>
using namespace std;

class BinaryNum
{
private:
	int* binNum;
	int noOfBits;
public:
	int * ConvertBinary(char * str,int size)
	{
		int index = 0;
		int *tempbinNum = new int[size];
		int zeros  =0;
		int ones = 1;
		for(int i = 0; i<size ; i++)
		{
			if(str[i]=='0')
			{
				tempbinNum[index] = zeros;
				index++;
			}
			else
			{
				tempbinNum[index] = ones;
				index++;
			}
		}
		return tempbinNum;
	}

	BinaryNum()
	{
		noOfBits=0;
		binNum=NULL;
	}
	void Print()
	{
		
			for(int i = 0 ; i<noOfBits ; i++)
				cout<<binNum[i];
			
		cout<<endl;
	}
	BinaryNum(char * str)
	{
		noOfBits = strlen(str);
		binNum  = ConvertBinary(str,noOfBits);
	}
	BinaryNum operator+(BinaryNum other)
	{
			int Total = noOfBits > other.noOfBits ? noOfBits : other.noOfBits;
		BinaryNum temp;
		temp.binNum = new int[Total];
		int exp = 0;
		int i = 0;
		while (i < Total )
		{
			int Bin1 = i < noOfBits&& binNum[i] ? 1 : 0;             
			int Bin2 = i < other.noOfBits&& other.binNum[i] ? 1 : 0; 
			int sum = Bin1 + Bin2 + exp;                           
			temp.binNum[i] = sum == 1 || sum == 3 ? 1 : 0;           

			exp = sum > 1 ? 1 : 0;
			i++;
		}

		temp.binNum[Total] = exp;

		binNum = new int[Total];
		noOfBits = Total;

		 i = 0;
		while( i < noOfBits)
		{
			binNum[i] = temp.binNum[i];
			 i++;
		}
		return *this;

	}
		void print()
	{
		for (int i = noOfBits-1; i >=0; i--)
		{
			cout << binNum[i];
		}
		cout << endl;
	}
		int operator[](int x)
		{
			return binNum[x];
		}



			BinaryNum operator++(int)                                           
	{
		int Res = 0;
		int power = 1;
		int exp = 0;
		BinaryNum temp(*this);
		temp.binNum = new int[noOfBits];
		for (int i = 0; i < noOfBits; i++)
		{

			temp.binNum[i] = binNum[i]++;                               
																		
		}

		int i = 0;
		while ( i < noOfBits )
		{
			Res += temp.binNum[(noOfBits - 1) - i] * power;      
			power *= 2;
			i++;
		}
		Res++;
		for ( i=0;Res > 0 ;i++)
		{
			binNum[i] = Res % 2;
			Res = Res / 2;
		}

		
		int end = noOfBits - 1;
		for (int start = 0;start < end ; start++, end--)
		{
			int temp = binNum[start];
			binNum[start] = binNum[end];
			binNum[end] = temp;
		}


		return temp;
	}



};
void main()
{
	BinaryNum b1;
	BinaryNum b2("101");
	BinaryNum b3("1001");
	cout<<"b1 = ";b1.Print();
	cout<<"b2 = ";b2.Print();
	cout<<"b3 = ";b3.Print();
	b1 = b2+b3;
	cout<<"b1 = ";b1.print();
	cout<<"b1[0] = "<<b1[0]<<endl;
	cout<<"b1[3] = "<<b1[3]<<endl;
	(b3++).Print(); 
	b3.Print(); 

	system("pause");
}