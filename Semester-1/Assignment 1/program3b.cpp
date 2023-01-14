#include<iostream>
using namespace std;
int main()
{
	int Length1,Length2,Length3,sqlength1,sqlength2,sqlength3;
		cout<<"Enter length 1:";
		cin>>Length1;
		cout<<"Enter lenght 2:";
		cin>>Length2;
		cout<<"Enter Lenght 3:";
		cin>>Length3;
		sqlength1= Length1*Length1;
		sqlength2= Length2*Length2;
		sqlength3=Length3*Length3;
			if(sqlength3==sqlength1+sqlength2)
		{
	cout<<"Triangle is Pythagorean";
		}
	else
			if(sqlength1==sqlength2+sqlength3)
		{
			cout<<"Triangle is Phyagorean";
		}
		else
		{
			if(sqlength2==sqlength1+sqlength3)
			{
				cout<<"Triangle is Phthagorean";
			}
			else
			{
				cout<<"not pythagorean";
			}
		}
	return 0;
	
}
