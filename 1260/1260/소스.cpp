#include <iostream>

using namespace std;
struct Stack 
{
	int* stack;
	int* Top;
	int count;
	int size;
	~Stack()
	{
		delete[] stack;
	}
	Stack(int n)
	{
		stack = new int[n];
		size = n;
		Top = stack;
		count = 0;
	}
	void Push(int value)
	{
		if (count >= size)
			resize();
		stack[count] = value;
		Top = stack + count;
		count++;
	}
	void resize()
	{
		int* temp = new int[size * 2];
		for (int i = 0; i < count; i++)
			temp[i] = stack[i];
		delete[]stack;
		stack = temp;
	}
	int Pop()
	{
		int temp = *Top;
		Top--;
		count--;
		return temp;
	}
};
struct Queue
{
	int* queue;
	int* Front;
	int* Back;
	int count;
	int size;
	~Queue()
	{
		delete [] queue;
	}
	Queue(int n)
	{
		queue = new int[n];
		size = n;
		Front = queue;
		Back = Front;
		count = 0;
	}
	void Push(int value)
	{
		//if (count >= size)
		//	resize();
		*Back = value;
		Back++;
		count++;
	}
	void resize()
	{
		int* temp = new int[size * 2];
		for (int i = 0; i < count; i++)
			temp[i] = queue[i];
		delete[]queue;
		queue = temp;
	}
	int Pop()
	{
		int temp = *Front;
		Front++;
		count--;
		return temp;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int m;
	int start;
	int** arr;
	
	bool *visited;

	
	cin >> n;

	
	arr = new int* [n];
	visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		visited[i] = false;
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	}

	cin >> m;
	cin >> start;
	Stack stack(n);
	Queue queue(n);
	int startnode = 0;
	int endnode=0;
	for (int i = 0; i < m; i++)
	{
		cin >> startnode;
		cin >> endnode;

		arr[startnode - 1][endnode - 1] = 1;
		arr[endnode - 1][startnode - 1] = 1;
	}
	//dfs
	
	stack.Push(start-1);
	while (stack.count != 0)
	{
		int temp = stack.Pop();
		if(!visited[temp])
			cout << temp+1 << ' ';
		visited[temp] = true;
		for (int i = n-1; i >= 0; i--)
		{
			if (visited[i] == true)
				continue;
			if (arr[temp][i] == 0)
				continue;
			stack.Push(i);
		}
	}
	
	for (int i = 0; i < n; i++)
		visited[i] = false;
	cout << '\n';


	//bfs
	queue.Push(start - 1);
	visited[start - 1] = true;
	while (queue.count != 0)
	{
		int temp = queue.Pop();
		cout << temp+1 << ' ';
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == true)
				continue;
			if (arr[temp][i] == 0)
				continue;
			queue.Push(i);
			visited[i] = true;	
		}
	}
	

	delete[]visited;
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}