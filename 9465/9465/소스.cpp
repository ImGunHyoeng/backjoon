#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	int N;
	int** arr;
	int** dp;
	arr = new int* [2];
	dp = new int* [2];
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cin >> N;

		for (int j = 0; j < 2; j++)
		{
			arr[j] = new int[N+1];
			dp[j] = new int[N+1];
		}
		for (int j = 0; j < 2; j++)//배열 초기화
			for (int k = 1; k <= N; k++)
			{
				cin >> arr[j][k];
			}

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1];	
		dp[1][1] = arr[1][1];
		for (int i = 2; i <= N; i++) 
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}
		cout << (max(dp[0][N], dp[1][N])) << '\n';

		for (int j = 0; j < 2; j++)//배열 메모리 할당초기화
		{
			delete[] arr[j];
			delete[] dp[j];
		}

	}
	delete[] arr;
	delete[] dp;


	return 0;
}