#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> RGB(3,0);
	int min = 1000;
	cin >> RGB[0];
	min = 0;
	cin >> RGB[1];
	if (min > RGB[1])
		min = 1;
	cin >> RGB[2];
	if (min > RGB[2])
		min = 2;
	int count = 0;
	int right= 2;
	int left = 0;
	int size = 3;
	sort(RGB.begin(), RGB.end());
	while (size)
	{
		if (size == 3)
		{
			for (int i = 0; i < 3; i++)
			{
				RGB[i]--;
				if (RGB[left] <= 0)
				{
					if(left<right)
						left++;
					size--;
				}
			}//세가지 종류를 뺴는 경우
			//if (RGB[left] <= 0)
			//{
			//	if (left < right)
			//		left++;
			//	size--;
			//}
			if (RGB[left]>=0)
				count++;
			
		}
		else if (size == 2)
		{
			/*for (int i = 0; i < 3; i++)
			{
				
				RGB[left]--;
			}*/
			RGB[left] -= 3;
			if (RGB[left] <= 0)
			{
				if (left < right)
					left++;
				size--;
			}
			if (RGB[left]>=-2)
				count++;
		}
		else
		{
			RGB[left] -= 3;
			if (RGB[left] <= 0)
			{
				if (left < right)
					left++;
				size--;
			}
			if (RGB[left]>=-2)
				count++;
		}


	}

	cout << count;

	return 0;
}

//그냥 다른것 모두 묶어내고,나서 다른것으로 묶는 방식?
//가장 작은것을 먼저처리하고 다른 것들을 처리
//가장 작은것으로 전부 처리하기