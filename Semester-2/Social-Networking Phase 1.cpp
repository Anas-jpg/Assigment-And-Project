#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Page;
class User;

class Facebook;
class Helper;
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



class Page
{
private:
	char*ID;
	char*Title;

public:

	Page(char *iD = nullptr,char *Tit = nullptr)
	{
		ID = nullptr;
		Title = nullptr;
	}

	void LoadPages(ifstream &fin)
	{
		char temp[80];
		fin>>temp;
		ID = Helper::GetStringFromBuffer(temp);
		fin.getline(temp,80);
		Title = Helper::GetStringFromBuffer(temp);
	}
	void PrintTitleAndId()
	{
		cout<<ID<<"\t\t"<<Title<<endl;
	}
	char * PageID()
	{
		return ID;
	}
	char *PageTitle()
	{
		return Title;
	}
	void SetPageID(char*temp)
	{
		ID = Helper::GetStringFromBuffer(temp);
	}
	void SetPageTitle(char*temp)
	{
		Title = Helper::GetStringFromBuffer(temp);
	}
		~Page()
	{
		if(ID!=nullptr)
			delete[] ID;
		if(Title!=nullptr)
			delete[] Title;
	}

};

class User
{
private:
	char *ID;
	char *FirstName;
	char *LastName;
	User** FriendList;
	Page** LikedPages;
public:
	char tempFriend[80];
	char tempPage[80];
	User()
	{
		ID = nullptr;
		FirstName = nullptr;
		LastName = nullptr;
		FriendList=nullptr;
		LikedPages=nullptr;
	}
	void PrintID()
	{
		cout<<ID<<"\t\t"<<FirstName<<endl;
	}

	void ViewFriendList()
	{
		cout<<"Current User: ";
		PrintID();
		for(int i = 0 ; i<2 ; i++)
		{
			FriendList[i]->PrintID();
		}
	}

	void ViewPageList()
	{
		cout<<"Current User: ";
		cout<<ID<<"\t\t"<<FirstName<<endl<<endl;
		for(int i = 0 ; i<2 ; i++)
		{
			LikedPages[i]->PrintTitleAndId();
		}
	}


	Page**GetLikedPages()
	{
		return LikedPages;
	}

	User**GetFriendList()
	{
		return FriendList;
	}

	void SetMemory()
	{
		if(FriendList==nullptr){
			FriendList = new User*[10];
			for(int i = 0 ; i<10; i++)
			{
				FriendList[i] = new User;
			}
		}
	}

	void SetMemoryPages()
	{
		if(LikedPages==nullptr){
			LikedPages = new Page*[10];
			for(int i = 0 ; i<10; i++)
			{
				LikedPages[i] = new Page;
			}
		}
	}


	void AddFriend(User *& frind, int index)
	{
		FriendList[index] = frind;
	}
	void AddPages(Page *& rhs, int index)
	{
		LikedPages[index] = rhs;
	}

	void ReadUsers(ifstream & fin, char ** tempFriend,char ** tempPage)
	{

		char temp[80];
		fin>>temp;
		ID = Helper::GetStringFromBuffer(temp);
		fin>>temp;
		FirstName = Helper::GetStringFromBuffer(temp);
		fin>>temp;
		LastName = Helper::GetStringFromBuffer(temp);

		for(int i = 0 ; i<10 ; i++){
			tempFriend[i] = new char[20];
			tempPage[i] = new char[20];
		}


		Helper::StringConcatenate(FirstName,LastName);
		for(int i = 0 ;  ; i++)
		{
			fin>>temp;
			if(temp[0]=='-')
				break;
			int size = strlen(temp);
			for(int k =0 ; k<size ; k++){
				tempFriend[i] = Helper::GetStringFromBuffer(temp);
			}
		}
		LikedPages = new Page*[10];
		
		for(int i = 0 ; i<10 ; i++)
		{
			LikedPages[i]=new Page;
		}
		
			for(int i = 0 ;  ; i++)
		{
			fin>>temp;
			if(temp[0]=='-')
				break;
			int size = strlen(temp);
			for(int k =0 ; k<size ; k++){
				LikedPages[i]->SetPageID(temp);
				tempPage[i] = Helper::GetStringFromBuffer(temp);		}

	}
	}
	char * GetStr()
	{
		return ID;
	}


	~User()
	{
		if(ID!=nullptr)
			delete[] ID;
		if(FirstName!=nullptr)
			delete[] FirstName;
		if(LastName!=nullptr)
			delete[] LastName;

	}

};



class Facebook
{
public:
	static int TotalPages;
	User** UserList;
	Page**PageList;
	static int TotalUser;
	void LoadData(char *** &tempFriend , char ***&tempPage)
	{
		ifstream finPages("Pages.txt");
		finPages>>TotalPages;
		PageList = new Page*[TotalPages]; 
		for(int i = 0 ; i<TotalPages ; i++)
		{
			PageList[i] = new Page;
		}

		for(int i = 0 ; i<TotalPages ; i++)
		{
			PageList[i]->LoadPages(finPages);
		}

		ifstream finUsers("Users.txt");
		finUsers>>TotalUser;

		tempFriend = new char**[TotalUser];
		tempPage = new char**[TotalPages];

		for(int i = 0 ; i<50 ; i++)
		{
			tempPage[i] = new char*[TotalPages];
			tempFriend[i] = new char*[TotalPages];
		}

		UserList  = new User*[TotalUser];

		for(int i = 0 ; i<TotalUser; i++)
		{
			UserList[i] = new User;
		}

		for(int i = 0 ; i<TotalUser; i++)
		{
			UserList[i]->ReadUsers(finUsers,tempFriend[i],tempPage[i]);
		}

	}

	Page*& SearchPageByID(char * str)
	{
		for(int i = 0 ; i<TotalPages ; i++)
		{
			if(Helper::SearchString(PageList[i]->PageID(),str))
			{
				return PageList[i];
			}
		}
	}
	User*& SearchUserByID (char* str)
	{
		{
			for(int i = 0 ; i<TotalUser ; i++)
			{
				if(Helper::SearchString(UserList[i]->GetStr(),str))
				{
					return UserList[i];
				}
			}
		}

	}

	void AssociateFriends(char ***&tempFriendList)
	{	 
		int i = 0;
		while( i < TotalUser)
		{
			for(int j = 0; ; j++)

			{
				if(tempFriendList[i][j][0] != 'u'){
					break;
				}
				UserList[i]->SetMemory();
				UserList[i]->AddFriend(SearchUserByID(tempFriendList[i][j]), j);
			}
			i++;
		}

	}

	void AssociatePages(char ***&tempPageList)
	{
		int i = 0;
		while( i < TotalUser)
		{
			for(int j = 0; ; j++)

			{
				if(tempPageList[i][j][0] != 'p'){
					break;
				}

				UserList[i]->SetMemoryPages();
				UserList[i]->AddPages(SearchPageByID(tempPageList[i][j]), j);
			}
			i++;
		}
	}

};

int Facebook:: TotalPages=0;
int Facebook::TotalUser=0;

void main()
{
	Facebook fb;

	char*** tempFriendList=nullptr;
	char *** tempPageList=nullptr;

	fb.LoadData(tempFriendList,tempPageList);
	fb.AssociateFriends(tempFriendList);
	fb.AssociatePages(tempPageList);
	User * cr = fb.SearchUserByID("u7");
	cr->ViewFriendList();
	cr->ViewPageList();
	system("pause");
}