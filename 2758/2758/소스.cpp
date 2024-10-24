#include <iostream>
#include <vector>

int T;
int m;
int n;
using namespace std;
int main()
{
	cin >> T;
	bool check;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cin >> m;
		vector<string> result;
		int dp[m][m];
		for (int j = 0; j < m; j++)//dp[m]으로 처음 값이 설정
		{
			for (int k = 0; k <= m; k++)//두번째 m이 1씩 답이 올라가는 것
			{
				if ((dp[j][k]+k) * 2 > m)
					break;
				else
				{
					dp[j][k + 1] = (dp[j][k] + k) * 2;
				}
				if (dp[j][k] >= n)//정답체크
				{
					check = true;
					string temp;
					for (int q = 0; q <= n; q++)
					{
						temp += dp[j][q];
					}
					for (int p = 0; p = result.size(); p++)
					{
						if (temp == result[p])
						{
							check = false;
							break;
						}
					}
					if (check)
						result.push_back(temp);
				}
			}
			cout << result.size();
		}
	}
	

	return 0;
}