#include <iostream>

using namespace std;

struct Node
{
	Node(long long _value,int _count):value(_value),count(_count)
	{
	
	}
	Node():Node(0,0)
	{
	}
	long long value;
	int count;
};
class Heap
{
	Node* array;
	int count;
	int size;
public:
	Heap():count(0),array(new Node[3]), size(3)
	{}
	~Heap() { delete [] array; }

	int getCount() { return count; }
	void resize()
	{
		Node* temp = new Node[size * 2];
		for (int i = 0; i < size; i++)
			temp[i] = array[i];
		array = temp;
		size *= 2;
	}
	void add(const Node * input)
	{
		if (count >= size)
			resize();
		array[count] = *input;
		count++;
		heapSortBottomUp();
	}
	void heapSortBottomUp()
	{
		if (count == 1)
			return;
		
		Node myNode = array[count-1];
		int cur = count-1;

		while (cur != 0)
		{
			if (array[cur].value >= array[(cur - 1) / 2].value)
				break;
			array[cur] = array[(cur - 1) / 2];
			cur = (cur - 1) / 2;
			//올바르게 고친것
			array[cur] = myNode;
		}

		//array[cur] = myNode; 이의 방식으로 하면은 add로 부모와 자리 바꾸는 것을 한번밖에 못함
	}
	const Node pop()
	{
		Node result = array[0];
		array[0] = array[count - 1];
		count--;
		heapSortTopDown();
		return result;
	}
	void heapSortTopDown()
	{
		if (count == 1)
			return;
		Node myNode = array[0];
		int left = 0, right = 0, cur=0;

		while (1)
		{
			left = cur * 2 + 1;
			right = cur * 2 + 2;

			if (left >= count-1 && right >= count-1)
				break;
			
			//자식이 하나일 경우
			if (left == count-1)
			{
				if (array[cur].value <= array[left].value)
					break;
				array[cur] = array[left];
				cur = left;
				array[cur] = myNode;
				continue;
			}

			//자식이 두개일 경우
			if (array[cur].value <= array[left].value && array[cur].value <= array[right].value)
				break;
			if (array[left].value < array[right].value)
			{
				array[cur] = array[left];
				cur = left;
				array[cur] = myNode;
				continue;
			}

			if (array[left].value > array[right].value)
			{
				array[cur] = array[right];
				cur = right;
				array[cur] = myNode;
				continue;
			}
		}
		//값 할당

	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long start, goal;
	cin >> start;
	cin >> goal;

	int count = -1;
	Heap heap;

	Node temp;
	heap.add(new Node(start, 1 ));
	while (heap.getCount() != 0)
	{
		temp = heap.pop();
		if(temp.value*2<=goal)
			heap.add(new Node(temp.value*2, temp.count + 1 ));
		if (temp.value * 10 + 1 <= goal)
			heap.add(new Node(temp.value*10+1, temp.count + 1 ));
		if (temp.value == goal)
		{
			if (count == -1)
			{
				count = temp.count;
				continue;
			}
			if (temp.count < count)
				count = temp.count;
		}
	}
	cout << count;
	return 0;
}