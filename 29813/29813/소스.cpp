#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;
class Student
{
public:
	char * name;
	int passable;
	Student* next;
	Student(const char *_name,int input): Student()
	{
		
		passable=input;
		if (input % 10 == 0)
			passable = passable / 10;
		name = new char[strlen(_name)+1];
		strcpy(name, _name); 
		
	}
	Student():name(nullptr), passable(0), next ( nullptr)
	{
		
	}
	~Student()
	{
		//delete [] name;
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
		//cout << "Quedelete" << endl;
		front = arr;
		for (int i = 0; i < size; i++)
		{
			//1.지역변수로 가면은 바로 초기화 되어서 안된다.
			//front->~Student();
			//2.큐가 소멸될 때 값을 초기화 시켜주는 것.
			delete front->name;
			//delete front;
			front++;
		}
	
	}

	void add(const char *name,int value)
	{
		if (nullptr== front)
		{
			Student* temp = new Student(name, value);
			arr = temp;
			front = temp;
			rear = temp;
			curindex++;
			return;
		}
		Student *temp= new Student(name, value);
		arr[curindex] = *temp;
		rear->next = temp;
		rear++;
		rear->next = NULL;
		
		curindex++;
	}

	void change()
	{
		Student temp = *(front + 1);
		Student* pt = front + 1;
		while(pt!=rear)
		{
			*pt = Student((pt + 1)->name, (pt + 1)->passable);
			pt++;
			//arr[i] = Student(arr[i + 1].name, arr[i + 1].passable);
		}
		*rear = temp;
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

	char *Name=new char[4];
	int value;

	for (int i = 0; i < N; i++)
	{
		cin >> Name;
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
	cout<< queue.frontpop();

	return 0;
}