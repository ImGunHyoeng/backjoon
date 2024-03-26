#include <iostream>
using std::cin;
using std::cout;

void inputLectureInfo(int count, int* lectureMinInfo)
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
bool isLower(int* blueLayInfo, int blueLayCount, int compare)
{
	for (int i = 0; i < blueLayCount; i++)
	{
		if (blueLayInfo[i] < compare)
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
	int blueLayCount = 0;

	int min = 0;
	int max = 0;

	cin >> lectureCount;
	cin >> blueLayCount;

	int* lectureMinInfo = new int[lectureCount];
	int* blueLayInfo = new int[blueLayCount];


	inputLectureInfo(lectureCount, lectureMinInfo);
	resetBlueLayInfo(blueLayCount, blueLayInfo);
	max = getSum(lectureCount, lectureMinInfo);
	min = getMin(lectureCount, lectureMinInfo);

	unsigned int left = min, right = max;
	int middle = (left + right) / 2;

	while (left <= right)
	{
		middle = (left + right) / 2;
		int curBlueLayCount = 0;
		int curLectureCount = 0;
		resetBlueLayInfo(blueLayCount, blueLayInfo);
		for (; curLectureCount < lectureCount; curLectureCount++)
		{
			//블루레이의 크기가 합친용량보다 큰지 체크
			if (blueLayInfo[curBlueLayCount] + lectureMinInfo[curLectureCount] < middle)
				blueLayInfo[curBlueLayCount] += lectureMinInfo[curLectureCount];
			else//작을경우 다음 블루레이에 들어감
			{
				curBlueLayCount++;
				if (curBlueLayCount == blueLayCount)
					break;
				blueLayInfo[curBlueLayCount] += lectureMinInfo[curLectureCount];
			}
		}
		//블루레이의 개수보다 적거나 같을경우 조건만족이라서 진행
		if (curBlueLayCount <= blueLayCount-1) 
		{
			isCondition = true;
		}
		else isCondition = false;
		if (isCondition)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	cout << middle;

	return 0;
}