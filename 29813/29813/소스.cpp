#include <iostream>
using namespace std;
struct student
{
	const char* name;
	int passable;
	student* next;
	student(const char *_name,int input):name(_name),passable(input)
	{
		next = nullptr;
	}
	student():student(nullptr,00)
	{

	}
};

class CircleQueue
{
	student* front;
	student* rear;
	student* arr;
	int curindex;
public:
	CircleQueue(int size)
	{
		arr = new student[size];
		front = nullptr;
		rear = front;
		curindex = 0;
	}

	void add(const char *name,int value)
	{
		if (rear + 1 == front)
			return;
		student *temp= new student(name, value);
		rear = temp;
		rear->next = NULL;
		rear++; 
		curindex++;
	}
	student* indexpop(int index)
	{
		if (rear == front)
			return NULL;
		student* pre =front + index-1;
		student *temp=front + index;
		pre->next = temp->next;
		const char* result =temp->name;
		
		curindex--;
		return temp;
	}
	const char* frontpop()
	{
		if (rear == front)
			return NULL;
		student* temp = front;
		front++;
		const char* result = temp->name;

		curindex--;
		return result;
	}
	int cursize()
	{
		return curindex;
	}
	student* getHead() 
	{
		return front;
	}
};
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	CircleQueue queue(N);

	char Name[4];
	int value;

	for (int i = 0; i < N; i++)
	{
		cin >> Name;
		cin >> value;
		queue.add(Name, value);
	}

	while (queue.cursize() != 1)
	{
		if (queue.getHead()->passable == 0)
		{
			queue.frontpop();
			queue.indexpop(1);
		}
		else
		{
			queue.getHead()->passable--;
			student *temp=queue.indexpop(1);
			queue.add(temp->name,temp->passable);
		}
	}
	cout << queue.frontpop();
	return 0;
}