#include <iostream>

using namespace std;

class Heap
{
	int* array;
	int count;
	int size;
public:
	Heap():count(0),array(new int[10]), size(10)
	{}
	~Heap() { delete [] array; }

	void resize()
	{
		int* temp = new int[size * 2];
		for (int i = 0; i < size; i++)
			temp[i] = array[i];
		array = temp;
	}
	void add(int value)
	{
		if (count + 1 > size)
			resize();
		array[count] = value;
		count++;
		heapSortBottomUp();
	}
	void heapSortBottomUp()
	{
		if (count == 1)
			return;
		
		int myvalue = array[count-1];
		int cur = count-1;

		while (cur != 0)
		{
			if (array[cur] >= array[(cur - 1) / 2])
				break;
			array[cur] = array[(cur - 1) / 2];
			cur = (cur - 1) / 2;
			
		}
		array[cur] = myvalue;
	}
	int pop()
	{
		if (count == 0)
			return -1;
		int result = array[0];
		array[0] = array[count - 1];
		count--;
		heapSortTopDown();
		return result;
	}
	void heapSortTopDown()
	{
		int myvalue = array[0];
		int left = 0, right = 0, cur=0;

		while (1)
		{
			left = cur * 2 + 1;
			right = cur * 2 + 2;

			if (left >= count || right >= count)
				break;
			if (array[cur] <= array[left] && array[cur] <= array[right])
				break;

			if (array[left] < array[right])
			{
				array[cur] = array[cur * 2 + 1];
				cur = cur * 2 + 1;
				continue;
			}

			if (array[left] > array[right])
			{
				array[cur] = array[cur * 2 + 2];
				cur = cur * 2 + 2;
				continue;
			}
		}
		//°ª ÇÒ´ç
		array[cur] = myvalue;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Heap heap;

	int* arr = new int[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		heap.add(arr[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		cout<<heap.pop();
	}
	return 0;
}