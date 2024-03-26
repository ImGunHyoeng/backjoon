#include <iostream>
using namespace std;
struct Range
{
	unsigned int min;
	unsigned int max;
};
int makeLen(int value, int cut);
void setInfo(int* lenInfo, int size);

void setRange(int* lenInfo, int size, Range& range);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int curLenCount = 0;
	int goalLenCount= 0;
	cin >> curLenCount;
	cin >> goalLenCount;
	int* lenInfo = new int[curLenCount];
	Range range = { 1,0 };
	setInfo(lenInfo, curLenCount);
	setRange(lenInfo, curLenCount,range);
	
	while (range.min <= range.max) 
	{
		unsigned int mid = (range.min + range.max) / 2;
		int sumLenCount = 0;
		int lenorder = 0;
		for (int i = 0; i < curLenCount; i++)
			sumLenCount += makeLen(lenInfo[i], mid);

		if (sumLenCount >= goalLenCount)
		{
			range.min = mid + 1;
		}
		else
		{
			range.max = mid - 1;
		}
	}
	cout << range.max;

	
	return 0;
}
int makeLen(int value,int cut)
{
	int count = 0;
	while (true)
	{
		if (value - cut < 0)
			return count;
		value -= cut;
		count++;
	}
}
void setInfo(int* lenInfo, int size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		lenInfo[i] = temp;
	}
}
void setRange(int* lenInfo, int size, Range& range)
{
	for (int i = 0; i < size; i++)
	{
		if (range.max < lenInfo[i])
			range.max = lenInfo[i];
	}

}