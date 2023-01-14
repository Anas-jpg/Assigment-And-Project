#include <iostream> 
using namespace std;
void sinecal(float sum) 
{ 
	int i,n;
	float deg,rad,term;
	cout<<"Enter the value of in degree: ";
	cin>>deg;
	n=20;
	rad=deg*3.141592/180; 
	term=sum=rad;
	for(i=2;i<=n;i++)
	{ 
		term*=-(rad*rad)/((2*i-1)*(2*i-2));
		sum+=term;
	}
	cout<<"Sin value is: "<<sum<<endl; 
	return;
}
int main()
{
	double deg;
	sinecal(deg);
	return 0;
}
