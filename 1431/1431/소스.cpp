#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int numsum(string str)
{
	int result = 0;
	//int temp = 0;
	for (int i = 0; i < str.length(); i++)
	{
		
		if (isalpha(str[i]))
		{
			continue;
			//temp = 0;
		}
		else
		{
			//temp *= 10;
			result += str[i] - 48;
			//temp += str[i]-48;
		}
	}
	//result += temp;
	return result;
}


bool cmp(string a, string b)
{
	int asum = numsum(a);
	int bsum = numsum(b);
	if (a.length() != b.length())//길이가 작다면
	{
		return a.length() < b.length();
	}
	else if (asum !=bsum)//a가 더 작다면
	{
		return asum < bsum;//앞에 sum이 더 작은 식으로 처리
	}
	else//같을 경우
	{
		return a < b;
	}
}
int main()
{
	vector<string> arr;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}