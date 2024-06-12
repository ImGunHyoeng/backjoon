#include <iostream>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int price[16] = { 0, };
	int time[16] = { 0, };
	int DP[21] = { 0, };
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> time[i];
		cin >> price[i];
	}

	for (int i = N; i >= 1; i--) 
	{
		if (i + time[i] > N + 1)//마지막날까지 일한 경우만 제외하고 처리
		{
			DP[i] = DP[i + 1];
			continue;//여기에서 오늘 안한값과 다음날의 값을 비교해서 최대값을 넣어주어야한다.
		}
		DP[i] = max(DP[i + 1], price[i] + DP[i+time[i]]);
	}
	
	cout << DP[1];


	return 0;
}