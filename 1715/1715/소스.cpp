#include <iostream>
using namespace std;
class Heap
{
	int * arr;
	int cursize;
public:
	Heap(int size)
	{
		arr = new int[size];
		cursize = 0;
	}
	int getsize() { return cursize; }
	void add(int input)
	{
		if (cursize == 0)
		{
			arr[0] = input;
			cursize++;
			return;
		}
		arr[cursize] = input;
		cursize++;
		HeapsortDownTop();
	}

	int pop()
	{
		int temp = arr[0];
		arr[0] = arr[cursize-1];
		cursize--;
		HeapsortTopDown();
		
		return temp ;
	}

	void HeapsortTopDown()
	{
		int cur = 0;
		int curresult = arr[0];
		int left, right;

		while (1)
		{
			left = cur * 2 + 1;
			right = cur * 2 + 2;
			if (cursize < left)//자식이 없음
				break;
			if (cursize == left)//자식이 하나
			{
				if (arr[cur] <= arr[left])
					break;
				arr[cur] = arr[left];
				arr[left] = curresult;
				cur = left;
				continue;
			}
			//자식 두개
			if (arr[cur] <= arr[left] && arr[cur] <= arr[right])
				break;
			if (arr[left] <= arr[right])
			{
				arr[cur] = arr[left];
				arr[left] = curresult;
				cur = left;
				continue;
			}

			if (arr[left] > arr[right])
			{

				arr[cur] = arr[right];
				arr[right] = curresult;
				cur = right;
				continue;
			}

		}
	}

	void HeapsortDownTop()
	{
		int curvalue=arr[cursize - 1];
		int child = cursize - 1;
		int parrent;
		while (1)
		{
			if (child == 0)
				break;
			parrent = (child-1)/ 2;
			if (arr[parrent] <= arr[child])
				break;
			arr[child] = arr[parrent];
			arr[parrent] = curvalue;
			child = parrent;

		}
	}
};
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int result = 0;
	int N;
	cin >> N;

	Heap heap(N);

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		heap.add(temp);
	}
	
	while (heap.getsize() != 1)
	{
		int sum = 0;
		sum += heap.pop();
		sum += heap.pop();
		result += sum;
		heap.add(sum);
	}
	cout << result;


	return 0;
}