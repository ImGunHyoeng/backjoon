#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;
class Student
{
public:
	char* name;
	int passable;
	//Student * next;
	Student(const char* _name, int input) :Student()
	{
		passable = input;
		if (input % 10 == 0)
			passable = passable / 10;
		strcpy(name, _name);
		name[strlen(_name)] = '\0';

	}
	Student() :passable(0)
	{
		name = new char[20];
	}
	~Student()
	{
		delete[] name;
		//dangeling pointer ¹æÁö¿ë
		name = nullptr;
	}
};

class Queue
{
	Student* front;
	Student* rear;
	Student* arr;
	int curindex;
	int size;
public:
	Queue(int _size)
	{
		arr = new Student[_size];
		front = nullptr;
		rear = front;
		curindex = 0;
		size = _size;
	}
	~Queue()
	{
		//front = arr;
		//Student* temp = nullptr;
		//for (int i = 0; i < size; i++)
		//{
		//	temp = front;
		//	delete temp;
		//	temp = nullptr;
		//	front++;
		//}

		delete[] arr;
	}

	void add(const char* name, int value)
	{
		if (nullptr == front)
		{
			front = arr;
			strcpy(arr[curindex].name, name);
			arr[curindex].passable = value;
			rear = front;
			curindex++;
			return;
		}

		strcpy(arr[curindex].name, name);
		arr[curindex].passable = value;
		rear++;
		curindex++;
	}

	void change()
	{
		char* temp;
		int value;
		temp = (front + 1)->name;
		value = (front + 1)->passable;

		Student* pt = front + 1;

		while (pt != rear)
		{
			*pt = *(pt + 1);
			pt++;
		}
		(*rear).passable = value;
		(*rear).name = temp;
	}
	const char* frontpop()
	{
		Student* temp = front;
		front++;
		const char* result = temp->name;

		curindex--;
		return result;
	}
	int cursize()
	{
		return curindex;
	}
	Student* getHead()
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
	Queue queue(N);

	char* Name = new char[4];
	int value;
	for (int i = 0; i < N; i++)
	{
		cin >> Name;
		Name[3] = '\0';
		cin >> value;
		queue.add(Name, value);
	}

	while (queue.cursize() != 1)
	{
		if (queue.getHead()->passable == 1)
		{
			queue.frontpop();
			queue.frontpop();
		}
		else
		{
			queue.getHead()->passable--;
			queue.change();
		}
	}
	cout << queue.frontpop();

	delete Name;
	return 0;
}