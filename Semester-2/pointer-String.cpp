#include<iostream>
using namespace std;

class MyString
{
	// Friend Functions for Insertion and Extraction
	friend istream& operator>>(istream& in, MyString&);
	friend ostream& operator<<(ostream& out, const MyString& obj);

private:

	char* str;
	int lenght;

	// Private Function to Calculate the String Length
	int StringLenght(char* str)
	{
		int stringLen = 0;
		for (char* temp = str; *temp != '\0'; temp++)
			stringLen++;

		return stringLen;

	}

	// Private Function to allocate specific size of Memory on Heap

	char* GetStringFromBuffer(char* buffer)
	{

		int strLen = StringLenght(buffer);
		char* str = 0;

		if (strLen > 0)
		{
			str = new char[strLen + 1];
			char* tempDest = str;
			for (char* tempSrc = buffer; *tempSrc != '\0'; tempSrc++, tempDest++)
			{
				*tempDest = *tempSrc;
			}
			*tempDest = '\0';
		}
		return str;
	}

	// Concatenate Function to Concatenate two strings into one
	void StringConcatenate(char*&str1, char*str2)
	{
		char * str3=new char[strlen(str1)+strlen(str2)+2];

		int Counter1=0;

		for(Counter1;Counter1<strlen(str1);Counter1++)            // Concatenate the first char array into new char array
		{
			str3[Counter1]=str1[Counter1];
		}
		int Counter2=0;

		for(Counter1,Counter2;Counter2<strlen(str2);Counter2++,Counter1++)	// Concatenate the 2nd char array into first char-Array
		{
			str3[Counter1]=str2[Counter2];
		}

		str3[Counter1]='\0';														// Placing Null Char to the end
		delete[] str1;																// DeAllocate the First Array
		str1=str3;																	// Pointing str1 to str3
		str3=nullptr;

	}
public:

	MyString();
	MyString( MyString &rhs);

	MyString &operator=(MyString rhs);

	MyString operator+(const MyString & rhs);

	bool operator<(MyString rhs);
	char& operator[](int c);

	bool operator!();

	void Set(char* temp);

	char*operator()(int startingIndex,int length);
	~MyString();
	bool operator!=(MyString rhs);

};

// Not equal Operator if would return true or false based on condition

bool MyString::operator!=(MyString rhs)
{
	if(str==rhs.str)
		return false;

	return true;
}

// Destructor
MyString::~MyString()
{
	if(str!='\0')
		delete[] str;
}

// parentheses(round bracket) operator to return string starting from given index to the end ending index

char* MyString::operator()(int startingIndex,int length)
{


	int size = length-startingIndex;

	char *str1 = new char[size];

	int x = 0;
	for(int i = startingIndex ; i<length+startingIndex-2; i++,x++)
	{
		str1[x] = str[i];
	}

	str1[x] = '\0';

	delete[] str;
	str = nullptr;

	str = str1;

	return str;
}

// Set Functions to Allocate Memory on Heap
void MyString:: Set(char* temp)
{
	str = GetStringFromBuffer(temp);
}


// Not operator(Unary) if would compare string and return true or false
bool MyString:: operator!()
{
	if(str=='\0')
		return true;

	return false;
}

// Subscript Operator; It would return the specific index of the string(Array)
char& MyString::operator[](int c)
{
	if(StringLenght(str)>c)

	return str[c];
	
	else
	{
		throw exception("Out of Range");
	}
}


// Less than Operator(Conditional) it would compare if l.h.s object is r.h.s object
bool MyString:: operator<(MyString rhs)
{
	for(int i = 0 ; i<strlen(str) ; i++)
	{
		if(str[i]<rhs.str[i])
		return true;
	}
	
	return false;
}

// It would Concatenate two objects
MyString MyString:: operator+(const MyString & rhs)
{
	MyString AddTwoStr=*this;
	
	StringConcatenate(AddTwoStr.str,rhs.str);
	
	return AddTwoStr;
}

// Operator equal it would copy rhs object into lhs object
MyString &MyString:: operator=( MyString rhs)
{
	if(*this!=rhs)
	{
		if(str)
			delete[] str;

		str = new char[strlen(rhs.str)];
		str = GetStringFromBuffer(rhs.str);
		return *this;
	}
}

// Copy Constructor:
MyString::MyString( MyString &rhs)
{
	str = GetStringFromBuffer(rhs.str);
	lenght = rhs.lenght;
}

// Insertion Operator
ostream& operator<<(ostream& os, const MyString& out)
{
	if(out.str)
		os << out.str;
	return os;
}

// Extraction Operator
istream& operator>>(istream& os,  MyString& out)
{
	char temp[80];
	os>>temp;


	out.Set(temp);

	return os;
}

//Default Constructor
MyString::MyString()
{
	lenght = 1;
	str = '\0';
}
void main()
{
	MyString str1, str2, str3, str4;

	if(!str1)
	{
		cout<<"String 1 is Empty.\n";
		cout<<"Str 1 = "<<str1<<endl<<endl<<endl;
	}

	cout << "Enter String 1:\t";
	cin >> str1;


	cout << "Enter String 2:\t";
	cin >> str2;


	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl<<endl<<endl;

	cout<<"Before str1 = str1; str1 = "<<str1<<endl;
	str1 = str1;
	cout<<"After str1 = str1, str1 = "<<str1<<endl<<endl<<endl;


	cout<<"Before str4 = str3 = str1+str2\n";
	cout<<"str1 = "<<str1<<endl;
	cout<<"str2 = "<<str2<<endl;
	cout<<"str3 = "<<str3<<endl;
	cout<<"str4 = "<<str4<<endl;

	str4 = str3 = str1+str2;


	cout<<"\n\n\nAfter str4 = str3 = str1+str2\n";
	cout<<"str1 = "<<str1<<endl;
	cout<<"str2 = "<<str2<<endl;
	cout<<"str3 = "<<str3<<endl;
	cout<<"str4 = "<<str4<<endl;

	cout<<"\n\n\nEnter String 3:\t";
	cin >> str3;

	cout<<"\n\n\nEnter String 4:\t";
	cin >> str4;

	cout<<"\n\n\nstr3 = "<<str3<<endl;
	cout<<"str4 = "<<str4<<endl;
	
	if(str3 < str4)
		cout<<"String 3 is Less than String 4.\n";
	else
		cout<<"String 3 is NOT Less than String 4.\n";

	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl;
	str5[7] = '$';

	cout << "\n\nStr5:\t" << str5 << endl;

	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;

	system("pause");
}
