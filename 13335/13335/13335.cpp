#include <iostream>

using namespace std;
class Node
{
private:
	int value;
	Node* post;
	int count;
public:
	Node(int _value, int setcount)
	{
		value = _value;
		count = setcount;
		post = nullptr;
	}
	Node(int _value, int setcount, Node* prenode) :Node(_value, setcount)
	{
		post = prenode;
	}
	void setPost(Node* input)
	{
		post = input;
	}
	Node* getPost() { return post; }
	int getCount() { return count; }
	void setCountminus() { count -= 1; }
	int getValue() { return value; }
};
class Queue
{

	Node* front;
	Node* rear;
	int maxCount;
	int curCount;
	int curTotalValue;
	int maxTotalValue;
public:
	Queue(int _maxCount, int _maxValue) :front(NULL), rear(NULL), curCount(0), curTotalValue(0), maxTotalValue(_maxValue), maxCount(_maxCount)
	{
	}
	void add(int value, int bridgeLength)
	{
		if (front == NULL)
		{
			front = new Node(value, bridgeLength);
			rear = front;
			curTotalValue += value;
			curCount++;
			return;
		}


		rear->setPost(new Node(value, bridgeLength));
		rear = rear->getPost();
		curCount++;
		curTotalValue += value;
	}
	void pop()
	{
		Node* temp = front;
		curTotalValue -= temp->getValue();
		front = temp->getPost();
		curCount--;

	}
	void queCountminus()
	{
		Node* temp = front;
		while (temp != nullptr)
		{
			temp->setCountminus();
			temp = temp->getPost();
		}
	}
	bool CanAdd(int value)
	{
		if (curCount >= maxCount)
			return false;
		if (curTotalValue + value > maxTotalValue)
			return false;
		return true;

	}
	bool CanPop()
	{
		if (curCount == 0)
			return false;
		if (front->getCount() == 0)
			return true;
		return false;
	}
	int getCurCount() { return curCount; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int bridgeLength;
	int maxWeight;
	int count = 0;
	cin >> n;
	cin >> bridgeLength;
	cin >> maxWeight;
	int* array = new int[n];
	Queue que(bridgeLength, maxWeight);

	for (int i = 0; i < n; i++)
	{
		int inputvalue;
		cin >> inputvalue;
		array[i] = inputvalue;
	}

	for (int i = 0; ;)
	{
		if (i == n)
		{
			if (que.getCurCount() == 0)
				break;
		}
		if (que.CanPop())
		{
			que.pop();
		}
		if(i != n)
			if (que.CanAdd(array[i]))
			{	
				que.add(array[i], bridgeLength);
				i++;
			}
		que.queCountminus();
		count++;
	}
	cout << count;

	return 0;
}