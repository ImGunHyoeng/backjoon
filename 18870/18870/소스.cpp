#include <iostream>

class Heap
{

private:
	int* heap;
	int size;

public:

	Heap(int* _heap, int _size) :heap(_heap),size(_size){}

	void addHeap(int value)
	{
		size++;
		int idx = size - 1;
		if (size == 1)
		{
			heap[0] = value;
			return;
		}
		heap[idx] = value;
		while (idx!=0&&heap[idx] < heap[(idx-1) / 2])
		{
			swap(idx, (idx - 1) / 2);
			idx = (idx-1) / 2;
		}
	}

	void swap(int index,int index2)
	{
		int temp = heap[index];
		heap[index] = heap[index2];
		heap[index2] = temp;
	}
	int top()
	{

		return heap[0];
	}
	int pop()
	{
		if (size == 0)
			return 0;
		int idx = 0;
		int result = heap[0];
		heap[0] = heap[size-1];
		size--;
		int left = idx * 2 + 1, right = idx * 2 + 2;
		while (1)
		{
			 left = idx * 2+1,right=idx*2+2;
			if (left > size-1)//자식이 없는경우
				break;
			if (left == size-1)//자식이 하나인 경우
			{
				if (heap[idx] > heap[left])
				{
					swap(idx, left);
					idx = left;
					continue;
				}
			}
			else{//자식이 둘일 경우에 왼쪽 오른쪽 구별해서 나가게 하기.
				if (heap[idx] > heap[left] || heap[idx] > heap[right])
				{
					if (heap[left] <= heap[right])
					{
						swap(idx, left);
						idx = left;
						continue;
					}
					else
					{
						swap(idx, right);
						idx = right;
						continue;
					}
				}
			}
			break;
		}
		return result;
	}
};

using namespace std;
void setList(int* list, int size);
void setHeapByList(Heap& heap, int* list, int size);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	Heap heap{new int[N],0};
	int* list = new int[N];
	setList(list, N);

	
	for (int i = 0; i < N; i++)
	{
		setHeapByList(heap, list, N);
		int count = 0;
		int heaptemp = 0;
		int heappre = 0;
		for (int j = 0; j < N; j++)
		{
			if (heap.top() > list[i])
				break;
			heaptemp=heap.pop();
			if (heappre == heaptemp)
				continue;
			if (list[i] > heaptemp)
				count++;
			heappre = heaptemp;
				
		}
		cout << count << " ";
	}
	
	return 0;
}

void setList(int* list, int size)
{
	for (int i = 0; i < size; i++)
		cin >> list[i];
}

void setHeapByList(Heap & heap, int* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		heap.addHeap(list[i]);
	}
}
