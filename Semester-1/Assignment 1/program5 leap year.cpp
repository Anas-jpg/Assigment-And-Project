#include<iostream>
using namespace std;
int main()
{
	int year1,year2,answer;
	cout<<"Enter a year start from:";
	cin>>year1;
	cout<<"Enter a year to end :";
	cin>>year2;
	if(year1<1582 || year2<1582)
	{
		cout<<"Enter a year AFTER 1582 of Gregorian Calendar";
	}
	else if(year1%100!=0 || year2%100!=0)
	{
		answer=(year2/4-year2/100+year2/400)-(year1/4-year1/100+year1/400);
	answer++;
		cout<<"leap years are: "<<answer;
	}
	else if(year2%4==0&&year1%4==0)
	{
	answer=(year2/4-year2/100+year2/400)-(year1/4-year1/100+year1/400);
		cout<<"leap years are: "<<answer;
	}
	else
	{
		answer=(year2/4-year2/100+year2/400)-(year1/4-year1/100+year1/400);
	cout<<"leap years are: "<<answer;
	}
	return 0;
}
	
