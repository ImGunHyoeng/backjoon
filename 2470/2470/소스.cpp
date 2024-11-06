#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{	
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = arr.size() - 1;
	int sum=arr[left]+arr[right];
	pair<int, int> minidx({ left,right });
	int min = abs(sum);
	while (left < right)
	{
		sum = arr[left] + arr[right];

		if (abs(sum) < min)
		{
			min = abs(sum);
			minidx = { left,right };
			if (sum == 0)
				break;
		}
		if (sum >= 0)
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	cout << arr[minidx.first] <<" "<< arr[minidx.second];

	return 0;
}