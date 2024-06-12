#include <iostream>
#include <algorithm>
using namespace std;
int tree[100001][3], dp[100001][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	int count = 1;
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < 3; j++)
			{
				cin >> tree[i][j];
				dp[i][j] = 0;
			}

		dp[0][0] = 100000, dp[0][1] = tree[0][1], dp[0][2] = tree[0][1]+tree[0][2];
		//가운데 값으로 부터 시작해야 하기에 가운데 값을 기준으로 생각 ,음수까지 가능
		for (int i = 1; i < N; i++)
		{
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + tree[i][0];
			dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] }) + tree[i][1];
			dp[i][2] = min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] }) + tree[i][2];
		}

		cout << count <<". "<< dp[N-1][1] <<"\n";
		count++;
			
		
	}
	return 0;
}