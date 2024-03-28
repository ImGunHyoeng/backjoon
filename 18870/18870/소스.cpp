#include <iostream>
void findOrder(int value, int* order, int size);
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
				if (heap[idx] <= heap[left])
					break;
				//더 작다면 그냥 이상태로
				swap(idx, left);
				idx = left;
				continue;
				
				
			}
			if (right <= size - 1)//자식 둘
			{
				//같은 경우에 바꿀필요는 없음
				if (heap[idx] <= heap[left] && heap[idx] <= heap[right])
					break;
				//if (heap[idx] > heap[left] || heap[idx] > heap[right])
				//{
				if (heap[left] <= heap[right])//idx보다 작다는것이 증명됨 변경 필수
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
				//}
			}
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
	int* orderednum = new int[N];
	setList(list, N);
	setHeapByList(heap, list, N);
	int ordernumsize = 0;

	for (int i = 0; i < N; i++)//힙 순서대로 빼기
	{
		int temp = heap.pop();
		if (i != 0 && orderednum[ordernumsize-1]==temp)
			continue;
		orderednum[ordernumsize] = temp;
		ordernumsize++;
	}
	for (int i = 0; i < N; i++)
	{
		findOrder(list[i], orderednum,ordernumsize);
	}
	
	return 0;
}

void findOrder(int value,int *order,int size)
{
	int left = 0,right=size-1;
	int mid = (left + right) / 2;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (order[mid] == value)
		{
			cout << mid<<" ";
			return;
		}
		if (order[mid] > value)
		{
			right = mid - 1;
		}
		if (order[mid] < value)
		{
			left = mid + 1;
		}
	}
	
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
