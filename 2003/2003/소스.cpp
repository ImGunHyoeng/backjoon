#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> arr;
	int n;
	long long x;
	cin >> n;
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int left=0, right = 0;
	long long sum = 0;
	int count = 0;
	//배열의 마지막원소를 더해서 구하는 경우를 포함해서 해야함.
	while (right <= arr.size()&& left <= arr.size())//마지막 원소까지 가는 경우의 수
	{
	
		if (sum > x)
		{
			if (left < arr.size())
				sum -= arr[left];
			left++;
		}
		else if (sum < x)
		{
			if(right<arr.size())
				sum += arr[right];
			right++;
		}
		else if (sum == x)
		{
			count++;
			if (left < arr.size())
				sum -= arr[left];
			left++;
		}
	}

	cout << count;
	return 0;
}