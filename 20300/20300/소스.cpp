#include <iostream>
using namespace std;
class Queue
{
	int* top;
	int* rear;
	int* arr;
	int maxsize = 0;
	Queue()
	{
		size = 0;
		arr = new int[10];
		top = nullptr;
		rear= nullptr;
	}
	void reAllocator()
	{

	}
	void add(int value)
	{

	}
	int pop() 
	{ 
		return *top; 
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int min = -1;
	
	int N;
	cin >> N;
	int* arr = new int[N];
	/*if (N % 2 == 0)
	{
		
	}
	if (N % 2 != 0)
	{
		int* arr = new int[N+1];
		arr[N] = 0;
	}*/

	for (int i = 0; i < N / 2; i++)
	{
		
	}
	
	

	return 0;
}