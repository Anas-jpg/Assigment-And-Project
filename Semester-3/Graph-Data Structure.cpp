#include<iostream>
using namespace std;

class Node
{
private:
	int data;			// For storing vertices inside queue
	char data1;			// For labeling inside the node
	Node* next;

public:
	Node()
	{}

	Node(int val)
	{
		data = val;
		next = NULL;
	}

	void setData(char val)
	{
		data1 = val;
	}

	friend class graph;
};

class graph
{
private:
	int v;
	Node* front;
	Node* back;
	int **adjacency;

public:
	graph()
	{
		front = NULL;
		back = NULL;
	}

	graph(int vertices)
	{
		v = vertices;
		adjacency = new int* [v];

		for (int i = 0;i < v;i++)
		{
			adjacency[i] = new int [v];
		}

		for (int i = 0;i < v;i++)
		{
			for (int j = 0;j < v;j++)
			{
				adjacency[i][j] = 0;
			}
		}
	}

	void addEdge(int p, int q)
	{
		adjacency[p][q] = 1;
		adjacency[q][p] = 1;
	}
	
	int BFS()
	{
		Node* arr = new Node[v]; 

		bool* visited = new bool[v];

		for (int i = 0;i < v;i++)     // marking all the vertices as not visited
		{
			visited[i] = false;
		}

		int count = 0;
		int x = 65;

		cout << "Labeling :\n\n";  

		for (int i = 0;i < v; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				push(i);

				count++;		// counter to count no of connected components

				while (!empty())
				{
					i = peek();
					arr[i].setData(x);
					cout << "Vertex " << i << " => " << arr[i].data1 << "  ";
					pop();

					for (int it = 0;it < v;it++)
					{
						if (adjacency[i][it] == 1 && !visited[it])
						{
							visited[it] = true;
							push(it);
						}
					}
				}
				x++;		// New label (means label changed) for new component
				cout << endl;
			}
		}

		return count;
	}

	void push(int x)
	{
		Node* n = new Node(x);

		if (front == NULL)
		{
			back = n;
			front = n;
			return;
		}

		back->next = n;
		back = n;
	}

	void pop()
	{
		Node* todelete = front;
		front = front->next;
		delete todelete;
	}

	int peek()
	{
		return front->data;
	}

	bool empty()
	{
		if (front == NULL)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
};

int main()
{
	int ver = 1;
	
	do
	{
		if (ver <= 0)
		{
			cout << "Invalid Entry\n\n";
			cin.clear();
			cin.ignore(132, '\n');
		}

		cout << "Enter Total no of vertices : ";
		cin >> ver;
	} while (ver <= 0);

	graph g(ver);
	
	int totalEdges = (ver * (ver - 1) / 2);			// Formula for total edges in the undirected graph
	int edges = 0;

	do
	{
		if (edges < 0 || edges > totalEdges)
		{
			cout << "Invalid Entry\n";
			cin.clear();
			cin.ignore(132, '\n');
		}

		cout << "\nEnter Total no of edges : "; 
		cin >> edges;
	} while (edges < 0 || edges > totalEdges);

	int c1 = 0, c2 = 0, j = 0;

	if (edges != 0)
	{
		cout << "\nEnter connections between vertices :" << "\n\n";
	}

	else
		cout << endl;
	
	for (int i = 0;i < edges;i++)
	{
		do
		{
			if (c1 < 0 || c1 >= ver)
			{
				cout << "Invalid Entry\n\n";
				cin.clear();
				cin.ignore(132, '\n');
			}
			cout << "Enter 1st vertex : ";
			cin >> c1;
		
		} while (c1 < 0 || c1 >= ver);

		do
		{
			if (c2 < 0 || c2 >= ver)
			{
				cout << "Invalid Entry\n\n";
				cin.clear();
				cin.ignore(132, '\n');
			}
			cout << "Enter 2nd vertex : ";
			cin >> c2;
			
		} while (c2 < 0 || c2 >= ver);

		g.addEdge(c1, c2);
		cout << "\nEdge " << ++j << " created (" << c1 << "," << c2 << ")";
		cout << "\n-----------------------------\n";
	}
	
	cout << "\nTotal Components : " << g.BFS() << "\n\n";
	system("pause");
	return 0;
}