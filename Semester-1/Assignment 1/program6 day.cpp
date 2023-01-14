#include<iostream>

using namespace std;

int main()
{
	int Week,Day,var1,var2,Month,Year,m,d;

	cout<<("Enter Day:\n");
		cin>>d;
	cout<<("Enter Month:\n");
		cin>>m;
	cout<<("Enter Year:\n");
		cin>>Year;
	if(Year<1900 || Year>2500)
	{
	printf("Input Valid year range from 1900-2500");
	}
     else if(m<1 || m>12)
	{
	printf("Input Valid month range from 1-12");
	}
	else if(d<1 || d>31){
	printf("Input Valid day range from 1-31");
	}
else
	{
	var1=Year/100;
	var2=Year%100;
	Week=d+(13*m+13)/5;
	Week=Week+var2+var2/4+var1/4;
	Week=Week%7;

	if (Week==0)
	{
		cout<<("\n Day is Monday");
	}
	else if
	(Week==1)
	{
		cout<<("\nDay is Tuesday");
	}
	else if
	(Week==2)
	{
		cout<<("\nDay is Wednesday");
	}
	else if
	(Week==3)
	{
		cout<<("\nDay is Thursday");
	}
	else if
	(Week==4)
	{
		cout<<("\Day is Friday");
	}
	else if
	(Week==5)
	{
		cout<<("\n Day is Saturday");
	}
	else if
	(Week==6)
	{
		cout<<("\nDay is Sunday");
	}

	return 0;
}
}
