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
	//�迭�� ���������Ҹ� ���ؼ� ���ϴ� ��츦 �����ؼ� �ؾ���.
	while (right <= arr.size()&& left <= arr.size())//������ ���ұ��� ���� ����� ��
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