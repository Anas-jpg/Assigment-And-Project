#include<iostream>
#include<cmath>
#include<cstdlib>
#include<iomanip>
using namespace std;

class ComplexNumber
{
private:
	int real;
	int imaginary;
public:	
	ComplexNumber(int, int); //with default arguments
	~ComplexNumber(); //Does Nothing.
	void Input();
	void Output();
	bool IsEqual(ComplexNumber);
	ComplexNumber Conjugate();
	ComplexNumber Add(ComplexNumber);
	ComplexNumber Subtract(ComplexNumber);
	ComplexNumber Multiplication(ComplexNumber);
	float Magnitude();
};

// Comparing the values of lhs object to the rhs object

bool ComplexNumber:: IsEqual(ComplexNumber rhs)
{
	if(real == rhs.real)
		if(imaginary == rhs.imaginary)
		{
			return 1;
		}
		return 0;
}

// Overloaded Constructor with Default Values
ComplexNumber::ComplexNumber(int real=0,int imaginary=0)
{
	this->real = real;
	this->imaginary = imaginary;
}

// Inputting the data into the object
void ComplexNumber::Input()
{
	cout<<"Enter Real: ";
	cin>>real;
	cout<<endl;

	cout<<"Enter Imaginary: ";
	cin>>imaginary;
	cout<<endl;
}

// Displaying the Number in Complex Form
void ComplexNumber::Output()
{
	if(imaginary>=0)
		cout << real << "+" << imaginary << "i" << endl;
	else
		cout<<real<<imaginary<<"i"<<endl;
}

// Returning the Conjugate of Complex Number 
ComplexNumber ComplexNumber:: Conjugate()
{
	ComplexNumber conjuGate;

	conjuGate.real  = real;
	conjuGate.imaginary = imaginary*-1;               // Changing the sign of imaginary Number

	return conjuGate;
}

// Adding lhs object to rhs Object and returning the sum object which contains the sum result of two object

ComplexNumber ComplexNumber:: Add(ComplexNumber rhs)
{
	ComplexNumber sum;

	sum.real = real+rhs.real;
	sum.imaginary = imaginary+rhs.imaginary;

	return sum;
}

// Subtracting lhs object to rhs Object and returning the Subtracted object which contains the subtraction result of two object
ComplexNumber ComplexNumber:: Subtract(ComplexNumber rhs)
{
	ComplexNumber subtract;

	subtract.real = real-rhs.real;
	subtract.imaginary = imaginary-rhs.imaginary;

	return subtract;
}

// Multiplying lhs object to rhs Object and returning the Multiplied object which contains the multiplication result of two object
ComplexNumber ComplexNumber:: Multiplication(ComplexNumber rhs)
{
	ComplexNumber Multiply;

	Multiply.real = (real * rhs.real) - (imaginary * rhs.imaginary);
	Multiply.imaginary = (real * rhs.imaginary) + (rhs.real * imaginary);

	return Multiply;

}

// Computing the Magnitude of the Object
float  ComplexNumber::Magnitude()
{
	float Magnitude;

	Magnitude = (real*real)+(imaginary*imaginary);      
	abs(Magnitude);										// Converting the values to absolute(+ve) 

	return sqrt(Magnitude);
}

// Destructor which does Nothing
ComplexNumber::~ComplexNumber(){
}

void main()
{
	cout<<"------Enter Complex Number 1: ------"<<endl;

	ComplexNumber c1;
	c1.Input();

	cout<<"\n------Enter Complex Number 2: ------"<<endl;

	ComplexNumber c2;
	c2.Input();

	cout<<"\n--------C-o-m-p-l-e-x-F-o-r-m--------------\n"<<endl;
	
	cout<<"Complex Number 1: ";
	c1.Output();

	cout<<"Complex Number 2: ";
	c2.Output();
	
	cout<<"\n---------------------------------------------"<<endl;

	if(c1.IsEqual(c2))
		cout<<"Complex No: 1 is equal to Complex No: 2 "<<endl;
	else
		cout<<"Complex No: 1 is not equal to Complex No: 2 "<<endl;

	cout<<"---------------------------------------------"<<endl;
	
	cout<<"\nConjugate of Complex No 1:  ";
	
	ComplexNumber conJugate;

	conJugate=c1.Conjugate();
	conJugate.Output();

	cout<<"Conjugate of Complex No 2:  ";
	
	conJugate=c2.Conjugate();
	conJugate.Output();

	cout<<"\n------------S-U-M------------"<<endl;
	
	ComplexNumber sum;
	cout<<"C1+C2: ";

	sum = c1.Add(c2);
	sum.Output();

	cout<<"\n------------S-U-B-T-R-A-C-T-I-O-N------------"<<endl;
	
	ComplexNumber subract;
	cout<<"C1-C2: ";

	subract = c1.Subtract(c2);
	subract.Output();

	cout<<"\n------------M-U-L-T-I-P-L-I-C-A-T-I-O-N------------"<<endl;
	
	ComplexNumber Multiply;
	cout<<"C1*C2: ";

	Multiply = c1.Multiplication(c2);
	Multiply.Output();

	cout<<"\n------------M-a-g-n-i-t-u-d-e------------"<<endl;

	cout<<"The magnitude of Complex Number 1 is: "<<setprecision(4)<<c1.Magnitude()<<endl;						// Set percision to 3 digits after decimal
	cout<<"The magnitude of Complex Number 2 is: "<<setprecision(4)<<c2.Magnitude()<<endl<<endl;

	system("pause");
}