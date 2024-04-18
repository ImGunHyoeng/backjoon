#include <iostream>
using namespace std;

struct Node
{
	int deadline;
	int cupNoddle;
	Node(int d, int c)
	{
		deadline = d;
		cupNoddle = c;
	}
	Node() :Node(0, 0)
	{}
};
template <typename T>
class Heap
{
	int curcount;
	int arrsize;
	T* arr;
public:
	int getcurcount() { return curcount; }
	Heap()
	{
		arr = new T[size_t(200001)];
		arrsize = 200001;
		curcount = 0;
	}
	~Heap()
	{
		delete [] arr;
	}
	void resize()
	{
		T* temp = new T[size_t(curcount * 2)];
		for (int i = 0; i < curcount; i++)
			temp[i] = arr[i];

		delete[] arr;
		arr = temp;
	}
	void add(T input)
	{
		if (curcount >= arrsize)
			resize();
		if (curcount == 0)
		{
			arr[0] = input;
			curcount++;
			return;
		}
		arr[curcount]= input;
		curcount++;
		bottomupsort();
	}
	T pop()
	{	
		T temp = arr[0];

		topdownsort();

		return temp;
	}
	void topdownsort()
	{
		arr[0] = arr[curcount - 1];
		T curvalue = arr[curcount - 1];
		curcount--;
		int sequnce = 0;
		int left, right;
		while (1)
		{
			left = sequnce * 2 + 1;
			right = sequnce * 2 + 2;
			
			if (curcount - 1 < left)//자식이 없는 경우의 수
				break;

			//자식 하나
			if (curcount-1 == left)
			{
				if (curvalue <= arr[left])
					break;
				arr[sequnce] = arr[left];
				sequnce = left;
				continue;//자식이 한 쪽일 경우
			}

			//자식이 둘다
			if (curvalue <= arr[right] && curvalue <= arr[left])
				break;
			if (arr[left] <= arr[right])
			{
				arr[sequnce] = arr[left];
				sequnce = left;
				continue;
			}

			arr[sequnce] = arr[right];
			sequnce = right;
			continue;
		}
		arr[sequnce] = curvalue;
	}
	void bottomupsort()
	{
		T curvalue = arr[curcount-1];
		int sequnce = curcount-1;
		while (sequnce!=0)
		{
			if (curvalue >= arr[(sequnce - 1) / 2])
				break;
			//시퀀스의 값이 다를경우
			arr[sequnce] = arr[(sequnce-1) / 2];
			sequnce = (sequnce - 1) / 2;
			
			
		}
		arr[sequnce] = curvalue;
	}
	T top()
	{
		return arr[0];
	}
};

template <>
class Heap<Node>
{
	int curcount;
	int arrsize;
	Node* arr;
public:
	Node top()
	{
		return arr[0];
	}
	int getcurcount() { return curcount; }
	Heap()
	{
		arr = new Node[size_t(200001)];
		arrsize = 200001;
		curcount = 0;
	}
	~Heap()
	{
		delete[] arr;
	}
	void resize()
	{
		Node* temp = new Node[size_t(curcount * 2)];
		for (int i = 0; i < curcount; i++)
			temp[i] = arr[i];

		delete[] arr;
		arr = temp;
	}
	void add(Node input)
	{
		if (curcount >= arrsize)
			resize();
		if (curcount == 0)
		{
			arr[0] = input;
			curcount++;
			return;
		}
		arr[curcount] = input;
		curcount++;
		bottomupsort();
	}
	Node pop()
	{
		Node temp = arr[0];

		topdownsort();

		return temp;
	}
	void topdownsort()
	{
		arr[0] = arr[curcount - 1];
		Node curvalue = arr[curcount - 1];
		curcount--;
		int sequnce = 0;
		int left, right;
		while (1)
		{
			left = sequnce * 2 + 1;
			right = sequnce * 2 + 2;

			if (curcount - 1 < left)//자식이 없는 경우의 수
				break;

			//자식 하나
			if (curcount - 1 == left)
			{
				if (curvalue.deadline <= arr[left].deadline)
					break;
				arr[sequnce] = arr[left];
				sequnce = left;
				continue;//자식이 한 쪽일 경우
			}

			//자식이 둘다
			if (curvalue.deadline <= arr[right].deadline && curvalue.deadline <= arr[left].deadline)
				break;
			if (arr[left].deadline <= arr[right].deadline)
			{
				arr[sequnce] = arr[left];
				sequnce = left;
				continue;
			}

			arr[sequnce] = arr[right];
			sequnce = right;
			continue;
		}
		arr[sequnce] = curvalue;
	}
	void bottomupsort()
	{
		Node curvalue = arr[curcount - 1];
		int sequnce = curcount - 1;
		while (sequnce != 0)
		{
			if (curvalue.deadline >= arr[(sequnce - 1) / 2].deadline)
				break;
			//시퀀스의 값이 다를경우
			arr[sequnce] = arr[(sequnce - 1) / 2];
			sequnce = (sequnce - 1) / 2;


		}
		arr[sequnce] = curvalue;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long result = 0;
	int input[2] = { 0, };
	int n;
	Node* arr;
	cin >> n;
	arr = new Node[n];
	Heap <Node> NodeHeap;
	Heap <int> Nodeval;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[i].deadline = temp - 1;
		cin >> temp;
		arr[i].cupNoddle = temp;
		
		NodeHeap.add(arr[i]);//deadline순서로 정렬
	}
	Node temp;
	//for (int i = 0; i < n; i++)
	//{
	//	temp = NodeHeap.pop();
	//	cout << temp.deadline << ' ' << temp.cupNoddle << endl;
	//}

	//int k = 0;
	while(1)
	{
		if (NodeHeap.getcurcount() == 0)
			break;


		temp=NodeHeap.pop();
		if (Nodeval.getcurcount()-1 < temp.deadline)
		{
			Nodeval.add(temp.cupNoddle);
			continue;
		}
		else 
		{
			if(Nodeval.top() >= temp.cupNoddle)
				continue;
			Nodeval.pop();
			Nodeval.add(temp.cupNoddle);
		}
		
	}
	while (1)
	{
		if (Nodeval.getcurcount() == 0)
			break;
		result += Nodeval.pop();
	}
	cout << result;
	delete[]arr;
	return 0;
}