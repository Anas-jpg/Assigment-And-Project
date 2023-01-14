#include<iostream>
using namespace std;

class Node
{
	Node*next;
	int data;
	int priority;
	int executionTime;
public:
	Node()
	{
		next = NULL;
		data = 0;
		priority = 0;
		executionTime = 0;
	}
	friend class Queue;
};

class Queue
{

	Node*front;
	Node*Rear;
	bool flag;
public:
	Queue()
	{
		front = NULL;
		Rear = NULL;
		flag = true;
	}
	void enqueue(int data)
	{
		Node*t = new Node;
		t->executionTime = data;

		t->next=NULL;

		if(front==NULL)
		{
			front = Rear = t;
		}
		else
		{
			Rear->next=t;
			Rear=t;
		}
	}

	int dequeue()
	{

		if(front==NULL)
		{
			cout<<"Queue is Empty: "<<endl;
			return -1;
		}
		else
		{
			int x=front->executionTime;
			Node*t=front;
			front=front->next;
			delete t;
			return x;
		}

	}

	void RoundRobin(int executionTime)
	{
		Node*p = front;
		Node*t = front;
		bool flag = true;


		if(p->next==NULL)
		{
			dequeue();
			return;
		}
		else if(p->executionTime<=0 )
		{
			dequeue();
		}
		else if (p->executionTime>0 )
		{
			p->executionTime=p->executionTime-executionTime;				
			int x = p->executionTime;

			dequeue();
			if(x>0)
				enqueue(x);
		}
		display();
		cout<<endl;
	}


	void ScedulingforHybrid()
	{
		double T1 = 10;
		double alpha = 0.5;

		Node*t = front;

		while(t)
		{
			double PredictedTime = alpha*front->priority+alpha*T1;
			cout<<"ID: "<<t->data<<endl;
			cout<<"Predicited Time: "<<PredictedTime<<endl;			
			RoundRobin(PredictedTime);
			t = front;
		}		
	}

	void SeceduleTime(int executionTime)
	{
		Node*t = front;

		while(t)
		{
			RoundRobin(executionTime);
			t=front;
		}
	}

	void display()
	{

		Node*p=front;

		if(front==NULL)
		{
			cout<<"Queue is Empty: "<<endl;
			return;
		}
		while(p!=NULL)
		{
			cout<<p->executionTime<<",";
			p = p->next;
		}
	}

	void priortyQueue(int data,int priorty)
	{
		Node*t = new Node;
		Node*temp;
		if(t==NULL)
		{
			cout<<"Heap is FULL: "<<endl;
		}
		else
		{

			t->executionTime = data;
			t->priority = priorty;
			t->next = NULL;


			if(front==NULL || front->priority>priorty)
			{
				t->next = front;  
				front = t;
			}
			else
			{
				Rear = front;									
				while(Rear->next!=NULL && Rear->next->priority<=priorty)
				{
					Rear= Rear->next;
				}

				t->next = Rear->next;
				Rear->next = t;
			}
		}
	}

	void priortyQueueDec(int data,int priorty,int exeTime)
	{
		Node*t = new Node;
		Node*temp;
		if(t==NULL)
		{
			cout<<"Heap is FULL: "<<endl;
		}
		else
		{

			t->data = data;
			t->priority = priorty;
			t->executionTime = exeTime;
			t->next = NULL;


			if(front==NULL || front->priority<priorty)
			{
				t->next = front;  
				front = t;
			}
			else
			{
				Rear = front;									
				while(Rear->next!=NULL && Rear->next->priority>=priorty)
				{
					Rear= Rear->next;
				}

				t->next = Rear->next;
				Rear->next = t;
			}
		}
	}


	void PriorySceduling()
	{
		Node * t = front;
		while(t)
		{
			t->executionTime -=t->executionTime;
			dequeue();
			t = front;
		}
	}


};


void main()
{
	int choice;
	cout<<"\n\n\t\"Enter 1 to Insert in Queue RoundRobin Operation\":"<<endl;
	cout<<"\n\n\t\"Enter 2 to insert in a priority Queue Wise\": "<<endl;
	cout<<"\n\n\t\"Enter 3 for Hybrid Stategy\": "<<endl;
	cout<<"-----------------------------------"<<endl;
	cin>>choice;

	switch(choice){
	case 1: 
		{
			Queue A;

			int totalElements;
			cout<<"Enter Total Elements to be inserted in queue: "<<endl;
			cin>>totalElements;
			int x;
			cout<<"\n-----------Enter Elements---------------"<<endl<<endl;
			for(int i = 0 ; i<totalElements;i++)
			{
				cin>>x;
				A.enqueue(x);
			}

			cout<<"\n\nEnter Execution Time: \n"<<endl;
			cin>>x;
			A.SeceduleTime(x);
			cout<<"--------Q1-----------------"<<endl;
			cout<<"\nDisplaying: \n"<<endl;

			A.display();
			break;
		}
	case 2:
		{
			int totalElements;
			int x;
			cout<<"---------Q2------------------------\n: "<<endl<<endl;
			Queue B;
			cout<<"Enter Total Elements to be inserted in Priority Queue: "<<endl;
			cin>>totalElements;
			cout<<"\n-----------Enter Elements with Priority---------------"<<endl<<endl;
			int priority;
			for(int i = 0 ; i<totalElements;i++)
			{
				cout<<"Enter ID: "<<endl;
				cin>>x;
				cout<<"Enter Priority: "<<endl;
				cin>>priority;
				B.priortyQueue(x,priority);
			}
			cout<<"\nDisplaying Before Sceduling: "<<endl;
			B.display();
			cout<<"\nDisplaying: After Sceduling "<<endl;
			B.PriorySceduling();
			B.display();
			break;
		}
	case 3:
		{
			cout<<"\n---------Q3------------------------\n: "<<endl<<endl;
			Queue C;
			int f;
			int n;
			int pr;
			int time;
			cout<<"Enter Total Elements to be inserted in Priority Queue(Hybrid Mode): "<<endl;
			cin>>f;
			cout<<"\n-----------Enter Elements with Priority---------------"<<endl<<endl;

			for(int i = 0 ; i<f;i++)
			{
				cout<<"Enter ID: "<<endl;
				cin>>n;
				cout<<"Enter Priority: "<<endl;
				cin>>pr;
				cout<<"Enter Execution-Time: "<<endl;
				cin>>time;
				C.priortyQueueDec(n,pr,time);
			}
			cout<<"\nDisplaying Before Sceduling: "<<endl;
			C.display();
			cout<<"-------------------------------------"<<endl;
			cout<<"\nDisplaying: After Sceduling "<<endl;
			C.ScedulingforHybrid();

			cout<<"Checking Stack is Null or Not: "<<endl;
			C.display();
			break;
		}
	default:
		break;
	}
	system("pause");
}