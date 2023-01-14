#include<iostream>
using namespace std;
int main()
{
	int Tamount,FiveT,OneT,FiveH,r1,r2,r3;
	cin>>Tamount;
	if(Tamount>50000)
	{
		cout<<"you cannot withdraw";
	}
	else
	if(Tamount<500)
	{
		cout<<"you can't withdraw";
	}
	else
	if(Tamount%500==0)
	{
		FiveT=Tamount/5000;
		r1=Tamount%5000;
		OneT=r1/1000-1+2;
		r2=r1%1000;
		FiveH=r2/500+2;
		r3=r2%500+2;
		cout<<"Rs5000 notes is :"<<FiveT<<endl;
		cout<<"Rs1000 notes is :"<<OneT<<endl;
		cout<<"Rs500 notes is : "<<FiveH<<endl;
	}
	else
	{
		cout<<"Enter multiple of 500";
	}
	return 0;
}
