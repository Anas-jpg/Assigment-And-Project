#include<iostream>
#include<fstream>
using namespace std;

int SizeOf_Cstring(char*&);
void StringConcatenate(char*&, char*);
inline int SpaceCtr(char*&);
char** TokenizedString(char* );
inline char* GetStrFromBuffer(char* );
inline void DisplayArr(char**&, int& );
inline void DeallocateMemory(char**& , int& );
char* SentenceReverse(char*);
char** InverseTokenizedString(char*);

// Helper: Counting The Length of Character
inline int SizeOf_Cstring(char*&str)
{
	int Counter = 0;
	int i = 0;
	while(str[i]!='\0')
	{
		Counter++;
		i++;
	}
	return Counter;
}

// Concatenate two string into the first string
void StringConcatenate(char*&str1, char*str2)
{
	char * str3=new char[SizeOf_Cstring(str1)+SizeOf_Cstring(str2)+1];

	int Counter1=0;

	for(Counter1;Counter1<SizeOf_Cstring(str1);Counter1++)            // Concatenate the first char array into new char array
	{
		str3[Counter1]=str1[Counter1];
	}
	

	int Counter2=0;

	for(Counter1,Counter2;Counter2<SizeOf_Cstring(str2);Counter2++,Counter1++)	// Concatenate the 2nd char array into first char-Array
	{
		str3[Counter1]=str2[Counter2];
	}

	str3[Counter1]='\0';														// Placing Null Char to the end
	delete[] str1;																// DeAllocate the First Array
	str1=str3;																	// Pointing str1 to str3
	str3=nullptr;

}

// Helper: Space Counter It will count the spaces between the words
inline int SpaceCtr(char*&str)
{
	int spaceCtr = 0;
	for(int i = 0 ; str[i]!='\0';i++)
	{
		if(str[i]==' ')
		{
			spaceCtr++;
		}
	}
	spaceCtr+=2;
	return spaceCtr; 
}

// Tokenizing the String and one token contains a complete word till space
char** TokenizedString(char* str)
{
	int LengthOfStr = SizeOf_Cstring(str);

	int spaceCtr = 0;

	spaceCtr = SpaceCtr(str);

	char**Token = new char*[spaceCtr];
	int counter=0;
	int index=0;
	int flag = 1;
	for(int i = 0 ; i<spaceCtr ; i++)
	{
		while(str[index]!='\0'&& flag==1)                     // It will Count the length of each word
		{
			if(str[index]!=' ')
			{
				counter++;
			}
			else
			{
				flag = 0;
			}

			if(flag==1)
				index++;
		}

		Token[i] = new char[counter+2];
		counter=0;
		index++;
		flag=1;
	}

	int word=0,spell=0;

	// Tokenizing the string
	for(int j = 0 ; str[j]!='\0' ; j++,spell++)
	{

		if(str[j]==' ')
		{	
			Token[word][spell] = ' ';
			spell++;
			Token[word][spell] = '\0';
			word++;
			spell = -1;
			continue;
		}

		Token[word][spell] = str[j];

	}

	Token[word][spell] = ' ';
	spell++;
	Token[word][spell] = '\0';
	return Token;


}

// Allocating the char array on heap by their specific lenght and copying the values to resultant array 
inline char* GetStrFromBuffer(char* buffer)
{
	int strLen = SizeOf_Cstring(buffer);       // Checking the Length of String
	char* str=nullptr;

	if (strLen != 0)
	{	
		str = new char[strLen+1];

		for (int i = 0; buffer[i] != '\0'; i++)
		{
			str[i] = buffer[i];
		}
		str[strLen] = '\0';             // Putting Null Character AT the end of String
	}
	return str;
}
// DisplayArring the char array
inline void DisplayArr(char**& str, int& size){

	for(int i = 0 ; i<size-1 ; i++)
		cout<<str[i]<<endl;

}

// DeAllocating the 2d Array
inline void DeallocateMemory(char**& studentsList, int& size)
{
	for(int i = 1 ; i<size ; i++){
		delete[] studentsList[i];
	}

}

// Helper: It will count each words of every token
inline int charCounter(char* str)
{
	
	char**Token = TokenizedString(str);
	int TokenCount = SpaceCtr(str);
	int counter = 0;
	for(int ithPos = TokenCount-2 ; ithPos>=0 ; ithPos--){
		for(int jthPos = 0 ; Token[ithPos][jthPos]!='\0';jthPos++)
		{
			counter++;
		}
		counter++;
	}

	DeallocateMemory(Token,TokenCount);                              // DeAllocation
		return counter;

}

// Sentence Reversing
char* SentenceReverse(char* str)
{
	int size = charCounter(str);
	char *RevSentence = new char[size+1];
	RevSentence[0] = '\0';
	char**Token = TokenizedString(str);
	int TokenCount = SpaceCtr(str);
	
		for(int i = TokenCount-2 ; i>=0 ; i--){
		
		{
			StringConcatenate(RevSentence,Token[i]);		// Keep Appending Till the End of the Token
		}
	}
		DeallocateMemory(Token,TokenCount);					// DeAllocating the Token
		return RevSentence;
}
// Reversing the Tokenized string by using previous function 
char** InverseTokenizedString(char* str)
{
	int spaceCtr = 0;

	spaceCtr = SpaceCtr(str);

	char*ReverseSentence1 = SentenceReverse(str);
	char**RevToken = TokenizedString(ReverseSentence1);

	delete [] ReverseSentence1;								// DeAllocating the ReverseSentence1
	
	return RevToken;
}


void main()
{
	char* str1=nullptr;
	char* str2=nullptr;
	ifstream charOpener;
	charOpener.open("Data.txt");
	char tempBuffer[80];
	charOpener.getline(tempBuffer,80);
	str1 = GetStrFromBuffer(tempBuffer);

	charOpener.getline(tempBuffer,80);
	str2 = GetStrFromBuffer(tempBuffer);

	cout<<"Before Concatenate: "<<endl;
	cout<<"String 1: "<<str1<<endl;
	cout<<"String 2: "<<str2<<endl;
	cout<<"\nAfter Concatenate: "<<endl;
	StringConcatenate(str1,str2);
	cout<<"String 1: "<<str1<<endl;
	cout<<"String 2: "<<str2<<endl;


	char**tokenized = TokenizedString(str1);
	int spaceCtr = SpaceCtr(str1);

	cout<<"\nTokenized String: "<<endl;
	DisplayArr(tokenized,spaceCtr);
	DeallocateMemory(tokenized,spaceCtr);              // DeAllocating The Tokenized String

	cout<<"\n----------------"<<endl;
	char**reverseOrder = InverseTokenizedString(str1);
	cout<<"Reverse Tokenized String: "<<endl;
	DisplayArr(reverseOrder,spaceCtr);
	DeallocateMemory(reverseOrder,spaceCtr);			   // DeAllocating the Reverse Tokenized

	cout<<"\n-------Reverse-Sentence--------"<<endl;

	char *reverseSentence = SentenceReverse(str1);
	cout<<reverseSentence<<endl;

	if(str2!=nullptr)								// DeAllocate
		delete[] str2;

	if(str1!=nullptr)                               // DeAllocate
		delete[] str1;

	delete[] reverseSentence;									// DeAllocate Rev 		


	system("pause");
}