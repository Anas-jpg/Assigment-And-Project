#include<iostream>
using namespace std;
float square_root(float num) 
{
	float R = (num * 1.00) / 2;
	float L= (R + (num / R)) /2;
	while((R - L) >= 0.0000001)
		{
			R = L;
			L = (R + (num / R)) / 2;
			
		}
			L=	(R+L)/2;
			return L;
}
int main()
{
	float n,i;
	cin>>n;
	if(n==0)
	{
		cout<<"0";
	}
	else if(n>=0.1 && n<=0.99)
	{
		i=square_root(n);
		i=i+0.0196;
		cout<<i;
	}
	else if(n<0)
	{
	return -1;
	}
	else
	{
	cout<<square_root(n);
	}
	return 0;
}


