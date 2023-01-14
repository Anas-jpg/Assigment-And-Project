#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Page;
class User;
class Facebook;
class Helper;
class activity;
class post;
class Date;
class Base;
class Comment;

class Date
{
private:
	int day , month,year;
public:
	
	static Date currentDate;
	bool checkLatestdate(Date New)
	{
		if(year<New.year)
			if(month<New.month)
				return false;

		if(day<New.day)
			return false;
		else
			return true;
	}
	Date()
	{
		day,month,year=0;
	}
	Date(int _d , int _m , int _y)
	{
		if(_d>0 && _m>0 && _y>0){
		day = _d;
		month=_m;
		year = _y;
	}
	}
	 int GetYear()
	{
		return year;
	}
	void SetDate(int d ,int m , int y)
	{
		if(d<=31 && m<=12){
			day = d;
			month = m;
			year = y;
		}
	}
	void LoadDate(ifstream & fin)
	{
		fin>>day;
		fin>>month;
		fin>>year;
	}
	void PrintDate()
	{

		cout<<"("<<day<<"/"<<month<<"/"<<year<<")"<<" ";
	}
};
// Helper Class to provide Useful functions to support our main classes


class Helper{

public:

	static int StringLenght(char*);                     // To find the StringLength			
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



// It would allocate the exact size space on heap and would return the base address
char* Helper::GetStringFromBuffer(char* buffer)            
{

	int strLen = StringLenght(buffer);       // Checking the Length of String
	char* str = 0;
	str = new char[strLen+1];

	for (int i = 0; buffer[i] != '\0'; i++)
	{
		str[i] = buffer[i];
	}
	str[strLen] = '\0';             // Putting Null Character AT the end of String

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




// Its a base class(Abstract class) that shared the common attributes of each class(i.e Name,ID)
class Base
{
	char*id;

public:
//	static char* ID;
	virtual void Print();					// Polymorphism concept is used
	virtual void PrintNameID();
	virtual void PrintName();
	void LoadID(ifstream& fin);
	virtual void addPostList(post *);
	static void SetID(char * str);
	char*getID();
	virtual void addTimeline(post*);
	Base()
	{
		id = NULL;
	}
	virtual ~Base()
	{
		if(id!=NULL)
		{
			delete[] id;
		}
	}
};


void Base:: addTimeline(post*)
{

}


void Base:: addPostList(post *)
{

}

void Base:: LoadID(ifstream& fin)
{
	char temp[80];

	fin>>temp;
	id = Helper::GetStringFromBuffer(temp);
}


// Virtual Functions to print the relevant class names and IDs
void Base:: PrintName()
{

}

void Base:: PrintNameID()
{

}

void Base::Print()
{

}

// Comment class which would store the comment attributes(i.e Commenter Name and the Discription)  of the post

class Comment 
{
private:
	char*CommentID;
	char*CommentText;
	char *PostID;
	char*UserID;
	Base *commentby;
public:
	Comment();
	void SetCommentData(char *CID,char *Text, Base * _likedby);
	void Print();
	void SetComment(char *Text,Base * _likedby );
	char*GetText();
	~Comment()
	{
		if(CommentID!=0)
		{
			delete[] CommentID;
		}
		if(CommentText!=0)
		{
			delete[] CommentText;
		}
		if(PostID!=0)
		{
			delete[] PostID;
		}
		if(UserID!=0)
		{
			delete[] UserID;
		}

	}
};




// Activity class would store the behaviour(such as Discription, Type of Feeling) of the specific users
class activity
{
private:
	int TypeOftype;
	char *discription;
	char *Activity;
public:
	activity();

	void ReadPost(ifstream & fin);
	void Print();

	// Destructor of activity class
	~activity();
};

class Page : public Base
{
private:
	char*ID;
	char*Title;
	post**Posts;
	int numberofposted;
	post**Timeline;
	int numberofTimeline;
public:

	Page(char *,char *);
	void addTimeline(post*&rhs);
	void PrintNameID();
	void PrintName();
	void LoadPages(ifstream &fin);
	void PrintPosts();
	void Print();
	void VIewPage();
	char *& PageID();
	void addPostList(post *aaa);

	char *&PageTitle();
	~Page();
};

class User : public Base
{
private:
	char *ID;
	char *FirstName;
	char *LastName;

	User** FriendList;
	Page** LikedPages;

	Base *sharedby;
	Base **likedby;
	post* Shared;
	int NumberLikedPages;
	int numberOfFriendList;
	post**Posts;
	int NumberofPost;
	post**Timeline;
	int numberofTimeline;
	int differenceofyears;
public:



	User();
	void addPostList(post *aaa);
	void addTimeline(post*rhs);
	void PrintName();
	void PrintNameID();
	void SetPoster(Base* obj);
	void Print();
	void PrintHomePage();
	void ViewTimeline();
	void printFriendlist();
	void PrintPosts();
	void  SetTimeline(post* aaa);

	void ViewFriendList();
	void ViewPageList();


	Page**GetLikedPages();
	User**GetFriendList();

	// Maximum  A one User can have 10 Friends
	void SetMemory();

	// Maximum  A one User can have 10 Pages
	void SetMemoryPages();
	void AddFriend(User * frind, int index);
	void AddPages(Page * rhs, int index);
	void addPost(User * frind);
	void ReadUsers(ifstream & fin, char ** tempFriend,char ** tempPage);
	char * GetStr();

	// View the Past Memories
	void SeeMemory();
	~User();

};


class Facebook : public Base
{
private:
	static int TotalPages;
	User** UserList;
	Page**PageList;
	post**PostList;
	activity**activityList;
	static int TotalUser;
	Comment**CommentList;
	int typeOfPost;					// Either Activity or Post
	int TotalPost;
	Comment* commentby;
	User* CurrentUser;

public:
	Facebook();

	void ReadPages(char*&);
	void ReadFriend(char *** &tempFriend , char ***&tempPage,char*);
	void LoadData(char*,char*,char*,char*);
	void ReadPostfromText(char*);
	void ReadCommentsfromText(char*);
	
	Page*& SearchPageByID(char * str);
	User*& SearchUserByID (char* str);
	post*&SearchPostbyID(char*str);

	void LinkedFriends(char ***&tempFriendList);
	void LinkedPages(char ***&tempPageList);

	void AddLiked(User* str);
	void PostComment(char*_post , char*CommentText, Base*user);

	
	post** GetPostList();
	void SetCurrentUser(char*str);
	
	~Facebook();

};


class post : public Base
{
private:
	char * discripton;
	int TypeOfPost;
	Comment ** ListOfComments;
	activity * shareActivityby;
	int noOfLiked;
	int numberOfComments;
	Base ** LikedBy;							// A post can be liked by Page or the User
	Base * Sharedby;							// A Page or a User can shared the post
	Date SharedDate;							// Composition

public:
	char*_ID;

	post();

	void SetPoster(Base*& auth);
	Date* GetDate();
	void Print();
	void SetComments(Comment* comments_);

	void AddNewLiked(Base* Like);
	void ReadPost(ifstream & fin);

	void ViewLikedList()
	{
		cout<<"\n---------------------- ViewLikedList(post5)---------------"<<endl;
		for(int i = 0 ; i<noOfLiked ; i++)
			LikedBy[i]->PrintNameID();
	}
	Comment** GetComments()
	{
		return ListOfComments;
	}
	Base* getWriter();
	void AddComment(char*NewComment,Base* _user)
	{

		static int flag =0;
		Comment * newComment = new Comment();
		newComment->SetComment(NewComment,_user);
		cout<<" Number of Comments: "<<numberOfComments<<endl;
		ListOfComments[numberOfComments] = newComment;

		Print();
		if(flag!=0){
			ListOfComments++;
			for(int i = 0 ; i<numberOfComments ; i++)
				ListOfComments[i]->Print();
		}
		flag++;
	}
	// Destructor
	~post();
};




// -------------------------------------------------Post Class----------------------------------------------------------------

post::post()
{
	LikedBy=nullptr;
	discripton=nullptr;
	Sharedby=nullptr;
	noOfLiked=0;
	_ID = nullptr;
	numberOfComments=0;
	ListOfComments = NULL;
	ListOfComments = new Comment*[15];
	int k = 0;
	while(k<15)
	{
		ListOfComments[k] = NULL;
		k++;
	}
	k=0;

	LikedBy = new Base * [10];
	while(k<10)
	{
		LikedBy[k] = NULL;
		k++;
	}
}
Base* post::getWriter()
{
	return Sharedby;
}
void post::SetPoster(Base*& auth)
{
	Sharedby = auth;
}
Date*post:: GetDate()
{
	return &SharedDate;
}

void post::Print()
{

	if(SharedDate.checkLatestdate(Date::currentDate)){
		if(TypeOfPost==1)
		{
			Sharedby->PrintName();
			SharedDate.PrintDate();
			cout<<" shared ";
			cout<<"\"";
			cout<<discripton;
			cout<<"\""<<endl;
		}
		if(TypeOfPost==2)
		{	
			Sharedby->PrintName();
			SharedDate.PrintDate();
			shareActivityby->Print();
			cout<<" ";
			cout<<"\"";
			cout<<discripton;
			cout<<"\""<<endl;

		}

		for(int i = 0 ; i<numberOfComments ; i++)
			ListOfComments[i]->Print();
	}
}

void post:: SetComments(Comment* comments_)
{

	*(ListOfComments+numberOfComments) = comments_;
	numberOfComments++;
}

void post::AddNewLiked(Base* Like)
{

	{
		*(LikedBy+noOfLiked) = Like;
		noOfLiked++;
	}
}

void post::ReadPost(ifstream & fin)
{
	char tempBuffer[80];


	fin>>TypeOfPost;  // Type 2 or 1
	fin>>tempBuffer;
	_ID = Helper::GetStringFromBuffer(tempBuffer);

	SharedDate.LoadDate(fin);			// Date
	fin.ignore();
	fin.getline(tempBuffer,80);
	discripton = Helper::GetStringFromBuffer(tempBuffer);

	if(TypeOfPost==2){
		shareActivityby = new activity;
		shareActivityby->ReadPost(fin);
	}			
}

post::~post()
{
	if(discripton!=nullptr)
	{
		delete[] discripton;
	}
	
	for(int i = 0 ; i<15 ; i++)
	{
		{
			delete[] ListOfComments[i];
		}
	}
	delete[] ListOfComments;					// Destroying Base Pointer
	ListOfComments = nullptr;
	for(int i = 0 ; i<10 ; i++)
	{
		{
			delete[] LikedBy[i];
		}
	}
	delete[] LikedBy;
	LikedBy = nullptr;
}

// ------------------------------------------------------Page Class-----------------------------------------------




Page::Page(char *iD = nullptr,char *Tit = nullptr)
{
	ID = nullptr;
	Title = nullptr;
	numberofposted=0;
	Timeline = new post*[12];
	for(int i = 0 ; i<12 ; i++)
	{
		Timeline[i] = NULL;
	}
	Posts = new post*[10];
	for(int i = 0 ; i<10 ; i++)
	{
		Posts[i] = NULL;
	}

	numberofTimeline=0;
}
void Page::addTimeline(post*&rhs)
{
	Timeline[numberofTimeline]=rhs;
	numberofTimeline++;
}
void Page::PrintNameID()
{
	cout<<ID<<"-"<<Title<<endl;
}
void Page::PrintName()
{
	cout<<Title<<" ";
}
void Page::LoadPages(ifstream &fin)
{
	char temp[80];
	fin>>temp;
	ID = Helper::GetStringFromBuffer(temp);
	fin.getline(temp,80);
	Title = Helper::GetStringFromBuffer(temp);
}
void Page::PrintPosts()
{
	for(int i = 0; i < numberofposted; i++)
	{

		{
			if(Posts[i]!=NULL)
				Posts[i]->Print();
		}
	}
}
void Page::Print()
{
	cout<<ID<<"\t\t"<<Title<<endl;
}
void Page:: VIewPage()
{
	PrintPosts();
	cout<<"\n\n\n"<<endl;
}
char *&Page:: PageID()
{
	return ID;
}
void Page::addPostList(post *aaa)
{


	static int x = 0;

	*(Posts+numberofposted) = aaa;
	numberofposted++;
}


char *& Page::PageTitle()
{
	return Title;
}
Page::~Page()
{
	if(ID!=nullptr)
		delete[] ID;
	if(Title!=nullptr)
		delete[] Title;

	for(int i = 0 ; i<12 ; i++)
	{
		{
			delete[] Timeline[i];
		}
	}
	delete[] Timeline;
	Timeline = nullptr;
	// List of Posts of the Pages
	for(int i = 0 ; i<10 ; i++)
	{

		{
			delete[] Posts[i];
		}
	}
	delete[] Posts;
	Posts = nullptr;
}




// -----------------------------------------------Activity ------------------------------------------------------

activity::activity()
{
	TypeOftype = 0;
	discription=0;
	Activity=0;
}
void activity:: ReadPost(ifstream & fin)
{

	char buffer[80];
	fin>>TypeOftype;

	fin.ignore();
	fin.getline(buffer,80);

	Activity=Helper::GetStringFromBuffer(buffer);
}
void activity:: Print()
{

	switch(TypeOftype)
	{
	case 2:
		cout<<"Thinking about\t";
		cout<<Activity;
		break;
	case 3:
		cout<<"Making\t";
		cout<<Activity;
		break;
	case 1:
		cout<<"Feeling\t";
		cout<<Activity;
		break;
	case 4:
		cout<<" is celebrating\t";
		cout<<Activity;
		break;			
	}

}
activity::~activity()
{
	if(discription!=0)
	{
		delete[] discription;
	}
	if(Activity!=0)
	{
		delete[] Activity;
	}
}

// ------------------------------------------------------------ USER ------------------------------------------------------------



Facebook::Facebook()
{
	TotalPost=0;
	PostList = new post*[10];
	for(int i = 0 ; i<10 ; i++)
		PostList[i]=new post[10];
	int k = 0;
	while(k<10)
	{
		PostList[k] = NULL;
		k++;
	}

	activityList = new activity*[10];
	for(int i = 0 ; i<10 ; i++)
		activityList[i]=new activity;
	k = 0;
	while(k<10)
	{

		activityList[k] = NULL;
		k++;
	}
	UserList = nullptr;
	PageList = nullptr;

}
void Facebook:: ReadPages(char*&PageName)
{
	ifstream finPages(PageName);
	finPages>>TotalPages;
	PageList = new Page*[TotalPages]; 
	for(int i = 0 ; i<TotalPages ; i++)
	{
		*(PageList+i) = new Page;
	}

	for(int i = 0 ; i<TotalPages ; i++)
	{
		PageList[i]->LoadPages(finPages);
	}
}
void Facebook:: ReadFriend(char *** &tempFriend , char ***&tempPage,char*UserFile)
{
	ifstream finUsers(UserFile);
	finUsers>>TotalUser;
	if(TotalUser>0){
	
	tempFriend = new char**[TotalUser];
	tempPage = new char**[TotalUser];

	int i = 0 ; 
	while(i<TotalUser )
	{
		tempPage[i] = new char*[10];
		tempFriend[i] = new char*[10];
		i++;
	}

	i=0;

	// Allocating Users
	UserList  = new User*[TotalUser];
	do
	{
		UserList[i] = new User;
		i++;
	}
	while(i<TotalUser);

	i=0;
	while(i<TotalUser)
	{
		UserList[i]->ReadUsers(finUsers,tempFriend[i],tempPage[i]);
		i++;
	}
}
	else
	{
		cout<<"File is not opened Properly: "<<endl;
	}
}

void Facebook::LoadData(char*PageFile,char*UserFile,char*CommentFile,char*postFile)
{
	char*** tempFriendList=nullptr;
	char *** tempPageList=nullptr;
	ReadPages(PageFile);
	ReadFriend(tempFriendList,tempPageList,UserFile);
	ReadPostfromText(postFile);
	ReadCommentsfromText(CommentFile);
	LinkedFriends(tempFriendList);
	LinkedPages(tempPageList);

	// DeAllocation of 3d Pointers
	
	for(int i = 0 ; i<TotalUser ; i++)
	{
		for(int j = 0; j<10 ; j++)
		{
			delete[] tempFriendList[i][j];
			delete[] tempPageList[i][j];
		}
		delete[] tempFriendList[i];
		delete[] tempPageList[i];
	}
	delete[] tempFriendList;
	delete[] tempPageList;
}

Page*& Facebook::SearchPageByID(char * str)
{
	int i = 0;
	do
	{
		if(Helper::SearchString(PageList[i]->PageID(),str))
		{
			return PageList[i];
		}
		i++;
	}
	while(i<TotalPages);
}
User*& Facebook::SearchUserByID (char* str)
{
	int i = 0 ;
	{
		do
		{
			if(Helper::SearchString(UserList[i]->GetStr(),str))
			{
				return UserList[i];
			}
			i++;
		}
		while(i<TotalUser );
	}
}

void Facebook:: LinkedFriends(char ***&tempFriendList)
{	 
	int i = 0;
	do
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
	while( i < TotalUser);

}

void Facebook:: LinkedPages(char ***&tempPageList)
{
	int i = 0;
	do
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
	while( i < TotalUser);
}

void Facebook:: ReadCommentsfromText(char*CommentFile)
{

	int TotalComments;
	char buffer[80];
	char CommentID[80];
	char CommentText[80];
	Base*likedby;
	ifstream fin(CommentFile);
	fin>>TotalComments;

	CommentList = new Comment*[TotalComments];
	int k = 0 ;
	do
	{
		*(CommentList+k) = new Comment;
		k++;
	}
	while(k<TotalComments);

	int i = 0 ;
	do
	{


		post *temp;
		fin>>CommentID;   // c1

		fin>>buffer;   // post1
		temp=SearchPostbyID(buffer);

		fin>>buffer;  // u1/p1

		if(buffer[0]=='u')
		{
			likedby = SearchUserByID(buffer);
		}
		else if(buffer[0]=='p')
		{
			likedby= SearchPageByID(buffer);
		}

		fin.ignore();
		fin.getline(CommentText,80);   // CommentText
		CommentList[i]->SetCommentData(CommentID,CommentText,likedby);
		temp->SetComments(CommentList[i]);
		i++;
	}
	while( i<TotalComments);

}
void Facebook::ReadPostfromText(char*postFile)
{
	Base *shared;
	char TypeChecler[10];
	int d,m,y;

	static int noOfPost = 0;
	ifstream fin(postFile);
	fin>>TotalPost;
	PostList = new post*[TotalPost];
	
	int i = 0 ;									// Loop Starts from Here

	do{

		PostList[i] = new post;
		PostList[i]->ReadPost(fin);
		fin>>TypeChecler;
		int s=0;

		if(TypeChecler[0]=='u')
		{
			shared = SearchUserByID(TypeChecler);
		}
		else
		{
			shared = SearchPageByID(TypeChecler);
		}

		PostList[i]->SetPoster(shared);
		shared->addPostList(PostList[i]);
		shared->addTimeline(PostList[i]);


		Base **LikedBy = new Base*[20];

		static int LikedBase=0;

		for( int k = 0;   ; k++){
			fin>>TypeChecler;

			if(TypeChecler[0]=='u')
			{
				LikedBy[k] = SearchUserByID(TypeChecler);			
			}

			else if(TypeChecler[0]=='p')
			{
				LikedBy[k] = SearchPageByID(TypeChecler);

			}
			else
			{
				break;
			}
			PostList[i]->AddNewLiked(LikedBy[k]);
		}
		i++;
	}
	while( i<TotalPost);

}


post*& Facebook::SearchPostbyID(char*str)
{
	int i = 0;
	while(i<TotalPost)
	{
		if(strcmp(PostList[i]->_ID,str)==0)
		{
			return PostList[i];
		}
		i++;
	}

}

post** Facebook::GetPostList()
	{
		return PostList;
	}
	void Facebook::SetCurrentUser(char*str)
	{
		for(int i = 0 ; i<TotalUser ; i++)
		{
			if(Helper::SearchString(UserList[i]->GetStr(),str))
			{
				CurrentUser = (UserList[i]);
				CurrentUser->PrintNameID();
				cout<<"Successfully Set User: "<<endl;

			}
		}

	}
	void Facebook::AddLiked(User* str)
	{

	}
	void Facebook:: PostComment(char*_post , char*CommentText, Base*user)
	{
		Base*commentby;
		char a[10] = "u7";
		post*temp = SearchPostbyID(_post);
		temp->SetPoster(user);
		Comment *as = new Comment();
		as->SetCommentData("u7",CommentText,user);
		temp->SetComments(as);
	}

	Facebook::~Facebook()
	{
		if(UserList)
		{		
		delete[] UserList;
		}
		if(PageList)
		{		
		delete[] PageList;
		}

		delete[] PostList;
		delete[] activityList;
	}


// -------------------------------------------------------User Class ------------------------------------------------------------

User::User()
{
	ID = nullptr;
	FirstName = nullptr;
	LastName = nullptr;
	FriendList=nullptr;
	LikedPages=nullptr;
	NumberLikedPages=0;
	numberOfFriendList=0;
	Posts = nullptr;
	NumberofPost=0;
	numberofTimeline=0;
	likedby = nullptr;
	Timeline = new post*[12];
	for(int i = 0 ; i<12 ; i++)
	{
		Timeline[i] = NULL;
	}


	Posts = new post*[10];
	for(int i = 0 ; i<10 ; i++)
	{
		Posts[i] = NULL;
	}

}
void User::addPostList(post *aaa)
{
	static int x = 0;
	Posts[NumberofPost] = aaa;
	NumberofPost++;
}
void User::addTimeline(post*rhs)
{
	Timeline[numberofTimeline]=rhs;
	numberofTimeline++;
}
void User::PrintName()
{
	cout<<"\t"<<FirstName<<" ";
}
void User::PrintNameID()
{
	cout<<ID<<"-"<<FirstName<<endl;
}
void User::SetPoster(Base* obj)
{
	sharedby = obj;
}	

void User::Print()
{
	cout<<ID<<"\t\t"<<FirstName<<endl;
}

void User::PrintHomePage()
{
	cout<<"HomePage: "<<endl;
	cout<<"Current User: ";

	Print();

	int i = 0 ;
	do
	{
		FriendList[i]->PrintPosts();
		i++;
	}
	while( i<numberOfFriendList );

	i=0;
	while( i<NumberLikedPages )
	{
		LikedPages[i]->PrintPosts();
		i++;
	}
	
}
void User:: ViewTimeline()
{
	int i = 0 ; 
	do
	{
		if(Timeline[i]!=NULL)
		Timeline[i]->Print();
		i++;
	}
	while(i<numberofTimeline);
}
void User:: printFriendlist()
{
	cout<<FriendList[2]->FirstName<<" shared "<<endl;
}
void User::PrintPosts()
{
	int i = 0;
	do
	{
		{
			if(Posts[i]!=NULL)
				Posts[i]->Print();
			i++;
		}
	}
	while( i < NumberofPost );
}
void  User::SetTimeline(post* aaa)
{
	*(Posts+NumberofPost) = aaa;
	NumberofPost++;
}


void User::ViewFriendList()
{
	cout<<"Current User: ";
	Print();
	cout<<"-------------------------"<<endl;

	for(int i = 0 ; i<numberOfFriendList ; i++)
	{
		FriendList[i]->Print();
	}
}

void User::ViewPageList()
{
	cout<<"\nLiked Pages:\t:";
	cout<<FirstName<<endl<<endl;
	cout<<"-------------------------"<<endl;
	for(int i = 0 ; i<NumberLikedPages ; i++)
	{
		LikedPages[i]->Print();
	}
}


Page**User::GetLikedPages()
{
	return LikedPages;
}

User**User::GetFriendList()
{
	return FriendList;
}


// Maximum  A one User can have 10 Friends
void User::SetMemory()
{
	if(FriendList==nullptr){
		FriendList = new User*[10];
		for(int i = 0 ; i<10; i++)
		{
			FriendList[i] = NULL;
		}
	}
}

// Maximum  A one User can have 10 Pages
void User::SetMemoryPages()
{
	if(LikedPages==nullptr){
		LikedPages = new Page*[10];
		for(int i = 0 ; i<10; i++)
		{
			LikedPages[i] = NULL;
		}
	}
}


void User::AddFriend(User * frind, int index)
{
	*(FriendList+index) = frind;
	numberOfFriendList++;
}
void User::AddPages(Page * rhs, int index)
{
	*(LikedPages+index) = rhs;
	NumberLikedPages++;
}
void User::addPost(User * frind)
{
	sharedby=frind;
}

void User:: ReadUsers(ifstream & fin, char ** tempFriend,char ** tempPage)
{
	for(int i = 0 ; i<10 ; i++){
		tempFriend[i] = new char;
		tempPage[i] = new char;
	}

	char temp[80];
	fin>>temp;
	ID = Helper::GetStringFromBuffer(temp);
	fin>>temp;
	FirstName = Helper::GetStringFromBuffer(temp);
	fin>>temp;
	LastName = Helper::GetStringFromBuffer(temp);

	Helper::StringConcatenate(FirstName,LastName);
	int i = 0 ;
	do
	{
		fin>>temp;
		if(temp[0]=='-')
			break;
		int size = strlen(temp);
		for(int k =0 ; k<size ; k++){
			tempFriend[i] = Helper::GetStringFromBuffer(temp);
		}
		i++;
	}
	while(1);

	LikedPages = new Page*[10];
	i=0;
	do
	{
		fin>>temp;
		if(temp[0]=='-')
			break;
		int size = Helper::StringLenght(temp);
		for(int k =0 ; k<size ; k++){
			tempPage[i] = Helper::GetStringFromBuffer(temp);	
		}
		i++;
	}
	while(1);
}
char *User:: GetStr()
{
	return ID;
}
User::~User()
{
	if(ID!=nullptr)
		delete[] ID;
	if(FirstName!=nullptr)
		delete[] FirstName;
	if(LastName!=nullptr)
		delete[] LastName;


	for(int i = 0 ; i<12 ; i++)
	{
	
		{
			delete[] Timeline[i];
		}
	}
	delete[] Timeline;
	Timeline = nullptr;

	// Postlist
	for(int i = 0 ; i<10 ; i++)
	{
		{
			delete[] Posts[i];
		}
	}
	delete[] Posts;
	Posts = nullptr;

	// It can be either User or Page

	for(int i = 0 ; i<10 ; i++)
	{
		{
			delete[] likedby[i];
		}
	}
	delete[] likedby;
	likedby = nullptr;

	for(int i = 0 ; i<10 ; i++)
	{
		if(FriendList[i]!= NULL)
		{
			delete[] FriendList[i];
		}
	}
	delete[] FriendList;
	FriendList = nullptr;

	for(int i = 0 ; i<10 ; i++)
	{
		if(LikedPages[i]!= NULL)
		{
			delete[] LikedPages[i];
		}
	}
	delete[] LikedPages;
	LikedPages = nullptr;

}

void User:: SeeMemory()
	{
		cout<<"We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago: \n"<<endl;
		if(numberofTimeline>0){
		Date *old = Timeline[numberofTimeline-1]->GetDate();
		int TimeDiff = Date::currentDate.GetYear()- old->GetYear();
		cout<<"On this day: "<< TimeDiff<<" years ago"<<endl;
		Timeline[numberofTimeline-1]->Print();
		}
		else
		cout<<"No User Entered in its timeline"<<endl;
	}



// -------------------------------------- COMMENT Class ----------------------------------------------------------------

void  Comment::SetCommentData(char *CID,char *Text, Base * _likedby)
{
	int size = 0;
	size = Helper::StringLenght(CID);
	CommentID = new char[size+2];
	int i = 0;
	for( ; i<size ; i++)
	{
		CommentID[i] = CID[i];
	}
	CommentID[i]='\0';

	size = Helper::StringLenght(Text);
	CommentText = new char[size+2];
	i = 0;
	for( ; i<size ; i++)
	{
		CommentText[i] = Text[i];
	}
	CommentText[i]='\0';
	commentby = _likedby;

}
void Comment::Print()
{
	cout<<"\t";
	commentby->PrintName();
	cout<<"wrote\t";
	cout<<"\"";
	cout<<CommentText;
	cout<<"\"";
	cout<<endl;
}



Comment::Comment()
{
	CommentID=0;
	CommentText=0;
	PostID=0;
	UserID=0;
}
char*Comment::GetText()
{
	return CommentText;
}

void Comment::SetComment(char *Text,Base * _likedby )
{
	commentby=_likedby;
	CommentText = Helper::GetStringFromBuffer(Text);
}


int Facebook:: TotalPages=0;
int Facebook::TotalUser=0;
Date Date::currentDate;
void main()
{
	Facebook fb;

	Date::currentDate.SetDate(14,11,2017);


	fb.LoadData("Pages.txt","Users.txt","Comments.txt","Posts.txt");
	fb.SetCurrentUser("u7");

	cout<<"----------------------------------------------------------"<<endl;

	User * cr = fb.SearchUserByID("u7");
	cr->ViewFriendList();
	cr->ViewPageList();
	cout<<"____________________________________________________"<<endl;
	cout<<"\nCommand:\t\tHomePage"<<endl;
	cout<<"____________________________________________________"<<endl;
	cr->PrintHomePage();

	cout<<"\n____________________________________________________"<<endl;
	cout<<"\nCommand:\t\tView TimeLine"<<endl;
	cout<<"____________________________________________________"<<endl;

	cr->ViewTimeline();

	post * str = fb.SearchPostbyID("post5");

	cout<<"\n____________________________________________________"<<endl;
	cout<<"\nCommand:\t\tView ViewLikedList(post5)"<<endl;
	cout<<"____________________________________________________"<<endl;

	str->ViewLikedList();

	cout<<"\n____________________________________________________"<<endl;
	cout<<"\nCommand:\t\tLikePost(post5)"<<endl;
	cout<<"____________________________________________________"<<endl;

	str->AddNewLiked(cr);
	str->ViewLikedList();


	cout<<"\n____________________________________________________"<<endl;
	cout<<"\nCommand:\t\tViewPage(P1)"<<endl;
	cout<<"____________________________________________________"<<endl;
	Page * p1 = fb.SearchPageByID("p1");
	p1->VIewPage();

	cout<<"\n_________________________________________________________________"<<endl;
	cout<<"\nCommand:\tPostComment(post4, Good Luck for your Result)"<<endl;
	cout<<"_________________________________________________________________"<<endl;

	Facebook onj;
	post *ptr = fb.SearchPostbyID("post4");
	ptr->AddComment("Good Luck for your Result",cr);
	//ptr->Print();
	cout<<"\n_________________________________________________________________"<<endl;
	cout<<"\nCommand:\tPostComment(post8, Thanks for the wishes)"<<endl;
	cout<<"_________________________________________________________________"<<endl;

	post *ptr1 = fb.SearchPostbyID("post8");
	ptr1->AddComment("Thanks for the wishes",cr);

	cout<<"\n_________________________________________________________________"<<endl;
	cout<<"\nCommand:\tSee Memories"<<endl;
	cout<<"_________________________________________________________________"<<endl;
	cr->SeeMemory();
	
	fb.SetCurrentUser("u11");
	//ptr1->Print();

	system("pause");
}