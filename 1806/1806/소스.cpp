#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int> arr;
	int n;
	int s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int left=0, right = 0;
	int size = 0;
	int minsize = 100001;
	int sum = 0;
	while (left < n)
	{
		if (sum < s)
		{
			if (right == n)
				break;
			sum += arr[right];
			size++;
			right++;
		}
		else
		{
			if(size!=0)
				minsize = min(minsize, size);
			sum -= arr[left];
			size--;
			left++;
		}
	}
	if (minsize == 100001)
		minsize = 0;
	cout << minsize;
}