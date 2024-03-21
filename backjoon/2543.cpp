#include <iostream>
using std::cin;
using std::cout;

void inputLectureInfo(int count,int * lectureMinInfo)
{
	for (int i = 0; i < count; i++)
	{
		cin >> lectureMinInfo[i];
	}
}
void resetBlueLayInfo(int count, int* blueLayInfo)
{
	for (int i = 0; i < count; i++)
	{
		blueLayInfo[i] = 0;
	}
}
int getMin(int count, int* lectureMinInfo)
{
	int result = 200000;
	for (int i = 0; i < count; i++)
	{
		if (lectureMinInfo[i] < result)
			result = lectureMinInfo[i];
	}
	return result;
}

int getSum(int count, int* lectureMinInfo)
{
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		result += lectureMinInfo[i];
	}
	return result;
}
bool isPossible(int* blueLayInfo, int blueLayCount, int* LectureInfo, int lectureCount,int middle)
{
	return true;
}
int getBlueLayMax(int* blueLayInfo, int blueLayCount)
{
	int result = 0;
	for (int i = 0; i < blueLayCount; i++)
	{
		if (blueLayInfo[i] > result)
			result = blueLayInfo[i];
	}
	return result;
}
bool isBlueLayEmpty(int* blueLayInfo, int blueLayCount)
{
	for (int i = 0; i < blueLayCount; i++)
	{
		if (blueLayInfo[i] == 0)
			return true;
	}
	return false;
}
bool isLower(int* blueLayInfo, int blueLayCount,int compare)
{
	for (int i = 0; i < blueLayCount; i++)
	{
		if (blueLayInfo[i] <compare)
			return true;
	}
	return false;
}


int main()
{
	bool isCondition = false;
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int lectureCount = 0;
	int blueLayCount= 0;

	int min = 0;
	int max = 0;

	cin >> lectureCount;
	cin >> blueLayCount;

	int* lectureMinInfo = new int[lectureCount];
	int* blueLayInfo = new int[blueLayCount];


	inputLectureInfo(lectureCount, lectureMinInfo);
	resetBlueLayInfo(blueLayCount, blueLayInfo);
	max=getSum(lectureCount, lectureMinInfo);
	min=getMin(lectureCount, lectureMinInfo);

	unsigned int left = min, right = max;
	int middle = (left + right) / 2;

	while (left < right)
	{

		int curBlueLayCount = 0;
		int curLectureCount = 0;
		resetBlueLayInfo(blueLayCount, blueLayInfo);
		for (; curLectureCount < lectureCount; curLectureCount++)
		{
			blueLayInfo[curBlueLayCount] += lectureMinInfo[curLectureCount];
			if (blueLayInfo[curBlueLayCount] < middle)
				continue;
			if (curBlueLayCount + 1 == blueLayCount)
				continue;
			curBlueLayCount++;
		}
		//강의가 들어가지 않는 블루레이의 유무
		if (curBlueLayCount + 1 != blueLayCount)
			isCondition = false;
		else 
		{
			isCondition = !isBlueLayEmpty(blueLayInfo,blueLayCount);
		}
		//블루레이안에 있는 값이 최소값보다 작지 않아야한다.
		isCondition = !isLower(blueLayInfo, blueLayCount, middle);
		if(isCondition)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
		middle = (left + right) / 2;
	}
	cout << getBlueLayMax(blueLayInfo, blueLayCount);

	return 0;
}