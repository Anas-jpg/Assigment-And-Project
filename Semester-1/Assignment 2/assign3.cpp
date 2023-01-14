#include<iostream>
using namespace std;
int Euclid_GCD(int m, int n)
{
    int r=m%n;
    while(r>0)
    {
        m=n;
        n=r;
        r=m%n;
    }
    return(m,n);
}
int main()
{
    int m,n;
    cin>>m>>n;
    if(m<0)
    {
    	m=m*-1;
	}
	if(n<0)
	{
		n=n*-1;
	}
    cout<<"The GCD IS "<<Euclid_GCD(m,n);
    return 0;
}
