#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	
	int N;
	cin >> N;
	vector<int> arr;
	vector<int> DP;
	arr.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
		DP.push_back(0);
	}
	DP.push_back(0);//n+1개 만큼의 DP

	for (int i = 1; i <= N; i++)
	{
		int mx=0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])//모든 배열중에서 큰 값 찾기
				mx = max(mx, DP[j]);
		}
		DP[i] = mx + 1;//DP는 i 이전까지 제일 큰수
	}
	sort(DP.begin(), DP.end(),cmp);
	cout << DP[0];
	return 0;
}