#include<iostream>
#include<fstream>
#include <conio.h>
#include<Windows.h>
#include<iomanip>
using namespace std;

// Helper Class to provide Useful functions to support our main class

class Helper{

public:

	static int StringLenght(char*);                     // To find the StringLength
	static void DeAllocateStaticData(int *);			

	static char* GetStringFromBuffer(char*);
	static void StringConcatenate(char*&, char*);

	static bool SearchString(char*, char*);

};

int Helper::StringLenght(char* str)                     // To find the StringLength
{
	int stringLen = 0;
	for (char* temp = str; *temp != '\0'; temp++)
		stringLen++;

	return stringLen;
}

// It would DeAllocate the Static Data which Total Quizes, Assignment Marks...
void Helper::DeAllocateStaticData(int * StaticArr)
{
	if(StaticArr!=nullptr)
	{
		delete[] StaticArr;
		StaticArr = nullptr;
	}
}

// It would allocate the exact size space on heap and would return the base address
char* Helper::GetStringFromBuffer(char* buffer)            
{

	int strLen = StringLenght(buffer);
	char* str = 0;

	if (strLen > 0)
	{
		str = new char[strLen + 2];
		char* tempDest = str;
		for (char* tempSrc = buffer; *tempSrc != '\0'; tempSrc++, tempDest++)
		{
			*tempDest = *tempSrc;

		}
		*tempDest='\0';
	}
	return str;
}

// It would Concatenate the First Name with Last Name
void Helper::StringConcatenate(char*&str1, char*str2)
{
	char * str3=new char[strlen(str1)+strlen(str2)+2];

	int Counter1=0;

	for(Counter1;Counter1<strlen(str1);Counter1++)            // Concatenate the first char array into new char array
	{
		str3[Counter1]=str1[Counter1];
	}

	str3[Counter1] = ' ';
	Counter1++;
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

// It would return the bool expression if we find the roll number against our list of Students

bool Helper:: SearchString(char* List, char* str)
{

	if(strcmp(List,str)==0)
	{
		return true;
	}

	return false;
}

class StudentEvaluation
{
private:

	char *rollNo;
	char *Fname;
	char *LName;
	int  *qMarks;
	int  *Amarks;
	static int TotalQu;
	static int TotalAs;
	static int OverAllMarks;

	int MaximumObtain;
	static int  totalstu;

	static int *TotalQuiz;
	static int* TotalAssignment;

public:


	
	int GetMaximumObtain();

	static int GetTotalStu();


	StudentEvaluation (const StudentEvaluation&);

	StudentEvaluation operator= (const StudentEvaluation&);

	void ReadStudentList(ifstream &);

	void PrintListView();

	StudentEvaluation();

	char* GetRollNo();
	static int* GetStatDataA();
	static int* GetStatDataB();


	void PrintDetailView();
	friend void PrintStatistics();

	~StudentEvaluation();
	static void ReadStaticData(ifstream&);
};

int StudentEvaluation::TotalQu=0;
int StudentEvaluation::TotalAs=0;
int StudentEvaluation::totalstu=0;
int StudentEvaluation::OverAllMarks = 0;
int* StudentEvaluation::TotalQuiz=nullptr;
int* StudentEvaluation::TotalAssignment=nullptr;



// It would read the data(static) which could be used by any student
void StudentEvaluation::ReadStaticData(ifstream&fin)
{

	fin>>TotalQu;
	fin>>TotalAs;

	TotalQuiz = new int[TotalQu];
	for(int i= 0 ; i<TotalQu ; i++)
	{
		fin>>TotalQuiz[i];
		OverAllMarks+=TotalQuiz[i];
	}

	TotalAssignment = new int[TotalAs];
	for(int i = 0 ; i<TotalAs ; i++)
	{
		fin>>TotalAssignment[i];
		OverAllMarks+=TotalAssignment[i];
	}
}


// Destructor to Deallocate All data on heap
StudentEvaluation::~StudentEvaluation()
{
	if(rollNo!=nullptr){
		delete[] rollNo;
		rollNo=nullptr;
	}

	if(Fname!=nullptr){
		delete[] Fname;
		Fname = nullptr;
	}

	if(Amarks!=nullptr){
		delete[] Amarks;
		Amarks = nullptr;
	}

	if(qMarks!=nullptr){
		delete[] qMarks;
		qMarks = nullptr;
	}

	if(LName!=nullptr){
		delete[] LName;
		LName = nullptr;
	}
}


// It would print the Total Profile of each student(including Name,Roll No, Total Quizes Marks,....etc)
void StudentEvaluation:: PrintDetailView()
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 11);

	cout<<"\n\n\t\tName: "<<Fname<<endl;
	cout<<"\t\tRoll No: "<<rollNo<<endl;
	cout<<"<---------------------------------->\n"<<endl;
	SetConsoleTextAttribute(console_color, 9);
	cout<<"\tQuizes Marks: "<<endl;
	int total=0;
	for(int i = 0 ; i<TotalQu ; i++)
	{
		cout<<"\tQ"<<i+1<<"\t"<<qMarks[i]<<"/"<<TotalQuiz[i]<<endl;
		total+=TotalQuiz[i];
	}

	SetConsoleTextAttribute(console_color, 14);
	cout<<"\n\tAssignment Marks: "<<endl;
	for(int i = 0 ; i<TotalQu ; i++)
	{
		cout<<"\tA"<<i+1<<"\t"<<Amarks[i]<<"/"<<TotalAssignment[i]<<endl;
		total+=TotalAssignment[i];
	}
	SetConsoleTextAttribute(console_color, 15);
	cout<<"\n\tTotal Marks are:\t"<<MaximumObtain<<"/"<<OverAllMarks<<endl;
	SetConsoleTextAttribute(console_color, 11);
	cout<<"<---------------------------------->\n"<<endl;

}
// It would return the Roll-No address
char* StudentEvaluation:: GetRollNo()
{
	return rollNo;
}

// Default Constructor
StudentEvaluation::StudentEvaluation()
{
	rollNo= 0;
	Fname = 0;
	LName = 0;
	
	qMarks = 0;
	Amarks = 0;
	
	totalstu++;
	MaximumObtain=0;
}

// It would Print the List of Student as we read in the file
void StudentEvaluation:: PrintListView()
{
	if(strlen(Fname)>16)
		cout<<rollNo<<"\t"<<Fname<<"\t";
	else
	cout<<rollNo<<"\t"<<Fname<<"\t\t";
	
	for(int i = 0 ; i<TotalAs ; i++)
	{
		cout<<qMarks[i]<<"\t";
	}
	
	for(int i = 0 ; i<TotalAs ; i++)
	{
		cout<<Amarks[i]<<"\t";
	}
	cout<<MaximumObtain;
	cout<<endl;
}

// It would Read Each Student Data( like First Name, Last Name, Roll No ,Quizes and Assignment Marks)
void StudentEvaluation:: ReadStudentList(ifstream & fin )
{

	char temp[80];
	fin>>temp;
	rollNo = Helper::GetStringFromBuffer(temp);
	fin>>temp;
	Fname = Helper::GetStringFromBuffer(temp);
	fin>>temp;
	LName = Helper::GetStringFromBuffer(temp);

	Helper::StringConcatenate(Fname,LName);

	qMarks = new int[TotalQu];
	for(int i = 0 ; i<TotalQu ; i++){
		fin>>qMarks[i];
		MaximumObtain+=qMarks[i];
	}

	Amarks = new int[TotalAs];
	for(int i = 0 ; i<TotalQu ; i++){
		fin>>Amarks[i];
		MaximumObtain+=Amarks[i];
	}

}

// Assignment Operator
StudentEvaluation StudentEvaluation:: operator= (const StudentEvaluation& rhs)
{
		
	if(Fname)
		delete[] Fname;

		Fname = new char[Helper::StringLenght(rhs.Fname)];
		Fname = Helper::GetStringFromBuffer(rhs.Fname);
		
		LName = new char[Helper::StringLenght(rhs.LName)];
		LName = Helper::GetStringFromBuffer(rhs.LName);

		delete[] qMarks;
		qMarks = new int[rhs.TotalQu];
		for(int i = 0 ; i<rhs.TotalQu ; i++)
		{
			qMarks[i] = rhs.qMarks[i];
		}

		delete[] Amarks;
		Amarks = new int[rhs.TotalAs+1];
		for(int i = 0 ; i<rhs.TotalAs ; i++)
			Amarks[i] = rhs.Amarks[i];

		TotalQu = rhs.TotalQu;
		TotalAs = rhs.TotalAs;


		rollNo = Helper::GetStringFromBuffer(rhs.rollNo);

		MaximumObtain = rhs.MaximumObtain;
		return *this;
}

// Copy Constructor
StudentEvaluation::StudentEvaluation  (const StudentEvaluation& rhs)
{
	
	Fname = new char[strlen(rhs.Fname)+1];
	Fname = Helper::GetStringFromBuffer(rhs.Fname);
	
	LName = new char[strlen(rhs.Fname)+1];
	LName = Helper::GetStringFromBuffer(rhs.LName);

	qMarks = new int[rhs.TotalQu];
	for(int i = 0 ; i<rhs.TotalQu ; i++)
	{
		qMarks[i] = rhs.qMarks[i];
	}

	Amarks = new int[rhs.TotalAs];
	for(int i = 0 ; i<rhs.TotalAs ; i++)
		Amarks[i] = rhs.Amarks[i];

	TotalQu = rhs.TotalQu;
	TotalAs = rhs.TotalAs;


	rollNo = Helper::GetStringFromBuffer(rhs.rollNo);
	MaximumObtain = rhs.MaximumObtain;
}

// Return the Total Students in the List
int StudentEvaluation:: GetTotalStu()
{
	return totalstu;
}

// Return the Maximum Obtain Marks for Each Student
int StudentEvaluation:: GetMaximumObtain()
{
	return MaximumObtain;
}

// It would return the base Address of TotalQuizesMarks(static) 
int*StudentEvaluation:: GetStatDataA()
{
	return TotalQuiz;
}

// It would return the base Address of TotalAssignmentMarks(static)
int*StudentEvaluation:: GetStatDataB()
{
	return TotalAssignment;
}

// Global Function: Read Data from File and Return the Base Address
StudentEvaluation* StudentList()
{
	int total;
	StudentEvaluation * List;
	ifstream fin;
	fin.open("GradeSheet.txt");
	fin>>total;
	StudentEvaluation::ReadStaticData(fin);

	List = new StudentEvaluation[total];

	for(int i = 0 ; i<total; i++){

		List[i].ReadStudentList(fin);
	}

	return List;
}

// This function takes the student list and sorted the list in ascending order(by Total Marks)
StudentEvaluation *SortedOrder(StudentEvaluation * List)
{
	
	for(int i=0; i<StudentEvaluation::GetTotalStu(); i++)
	{
		for(int j=i+1; j<StudentEvaluation::GetTotalStu(); j++)
		{
			if(List[j].GetMaximumObtain() < List[i].GetMaximumObtain())
			{
				 StudentEvaluation temp = List[i];
				List[i] = List[j];
				List[j] = temp;
			}
		}
	}
	return List;
}


// The Global Function it would take the roll no and check againt the list of student's roll No and print the details
void SearchStudent(char* RollNoCheck)
{
	bool flag= false;
	StudentEvaluation * List  = StudentList();
	int i=0;
	int FoundIndex = 0;
	for(; i<StudentEvaluation::GetTotalStu(); i++)
	{
		if(Helper::SearchString(List[i].GetRollNo(),RollNoCheck))
		{
			flag = true;
			FoundIndex = i;
		}
	}
	if(flag)
		List[FoundIndex].PrintDetailView();
	else
	{
		cout<<"Record Not Found: "<<endl;
	}
	delete[] List;											// DeAllocating the List

	// DeAllocating the Static Data
		Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataA());
		Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataB());

}

void PrintStatistics()
{
	StudentEvaluation * List = StudentList();
	cout<<"\t\tQ1"<<"\tQ2"<<"\tQ3"<<"\tQ4"<<"\tA1"<<"\tA2"<<"\tA3"<<"\tA4"<<endl;
	cout<<"\nTotal:\t\t";
	for(int i = 0 ; i < List->TotalQu ; i++)
	{
		cout<<List->TotalQuiz[i]<<"\t";
	}
	for(int i = 0 ; i < List->TotalAs ; i++)
	{
		cout<<List->TotalAssignment[i]<<"\t";
	}
	cout<<endl;
	cout<<"Maximum:\t";
	for(int j =0;j<List->TotalQu ; j++){
		float max = List[0].qMarks[j];


		for(int i=1; i<StudentEvaluation::totalstu; i++)
		{
			if(max<List[i].qMarks[j])
				max = List[i].qMarks[j];
		}
		cout<<max<<"\t";
	}

	for(int j =0;j<List->TotalAs ; j++){
		float max = List[0].Amarks[j];
		for(int i=1; i<StudentEvaluation::totalstu; i++)
		{
			if(max<List[i].Amarks[j])
				max = List[i].Amarks[j];
		}
		cout<<setprecision(2)<<max<<"\t";
	}
	cout<<endl;

	cout<<"Minimum:\t";
	for(int j =0;j<List->TotalQu ; j++){
		float min = List[0].qMarks[j];


		for(int i=1; i<StudentEvaluation::totalstu; i++)
		{
			if(min>List[i].qMarks[j])
				min = List[i].qMarks[j];
		}
		cout<<setprecision(2)<<min<<"\t";
	}

	for(int j =0;j<List->TotalAs ; j++){
		float min = List[0].Amarks[j];
		for(int i=1; i<StudentEvaluation::totalstu; i++)
		{
			if(min>List[i].Amarks[j])
				min = List[i].Amarks[j];
		}
		cout<<min<<"\t";
	}
	cout<<endl;
	cout<<"Average:\t";
	for(int i = 0 ; i<List->TotalQu ; i++)
	{
		float ObtainMarks = 0;
		for(int j = 0 ; j<StudentEvaluation::totalstu ; j++)
		{
			ObtainMarks += List[j].qMarks[i];
		}
		cout<<(ObtainMarks/StudentEvaluation::totalstu)<<"\t";
	}
	for(int i = 0 ; i<List->TotalAs ; i++)
	{
		float ObtainMarks = 0;
		for(int j = 0 ; j<StudentEvaluation::totalstu ; j++)
		{
			ObtainMarks += List[j].Amarks[i];
		}
		cout<<setprecision(2)<<(ObtainMarks/StudentEvaluation::totalstu)<<"\t";
	}
	cout<<endl;

	delete[] List;													// DeAllocating the Student's List
		
		Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataA());
		Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataB());
}

void main()

{
	HANDLE console_color;						// It would Add color to the Console text

		int op;
		cout<<"Press 1 to View List of Student: "<<endl;
		cout<<"Press 2 to View Student List Sorted Order: "<<endl;
		cout<<"Press 3 to Search Student from List: "<<endl;
		cout<<"Press 4 View Statistics: "<<endl;
		cout<<"Press 5 to Exit the Program" <<endl;
		cout<<"\n-------------------------------------------\n"<<endl;

		cin>>op;
		switch(op){
		case 1:
			{

				cout<<"====================================================================================="
					<<"========================="<<endl;
				cout<<"Roll:No"<<"\t"<<"\tName"<<"\t\t\tQ1"<<"\tQ2"<<"\tQ3"<<"\tQ4"<<"\tA1"<<"\tA2"<<"\tA3"<<"\tA4"<<"\tTotal"<<endl;
				cout<<"====================================================================================="
					<<"========================="<<endl;

				console_color = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(console_color, 11);

				StudentEvaluation* A = StudentList();
				for(int i = 0 ; i<StudentEvaluation::GetTotalStu() ; i++)
					A[i].PrintListView();

				// DeAllocations
				delete[] A;                      

				Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataA());
				Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataB());
				break;
			}

		case 2:
			{
				cout<<"====================================================================================="
					<<"========================="<<endl;
				cout<<"Roll:No"<<"\t"<<"\tName"<<"\t\t\tQ1"<<"\tQ2"<<"\tQ3"<<"\tQ4"<<"\tA1"<<"\tA2"<<"\tA3"<<"\tA4"<<"\tTotal"<<endl;
				cout<<"====================================================================================="
					<<"========================="<<endl;
				
				console_color = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(console_color, 11);
				
				StudentEvaluation* A = StudentList();
				StudentEvaluation * sorted = SortedOrder(A);
				for(int i = 0 ; i<StudentEvaluation::GetTotalStu() ; i++)
					sorted[i].PrintListView();
				
				//DeAllocations
				delete[] sorted;
				Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataA());
				Helper::DeAllocateStaticData(StudentEvaluation::GetStatDataB());
				break;
			}
		case 3:
			{
				char temp[80];
				cout<<"Enter Student Roll No: "<<endl;
				cin>>temp;
				SearchStudent(temp);
				break;
			}
		case 4:
			{
				console_color = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(console_color, 11);
				PrintStatistics();
				break;
			}
		case 5:
			{
				return;
			}

		}
	system("pause");

}