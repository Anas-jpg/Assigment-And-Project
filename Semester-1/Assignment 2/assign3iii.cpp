#include<iostream>
using namespace std;
long long factorial(int num)
{
	int i;
	unsigned long fact;
		for(i=1;i<=num;++i)
	{
		fact=fact*i;
	}
		return fact;
}
int main()
{
	int num,fact;
	cin>>num;
	cout<<factorial(num);
	return 0;
}
