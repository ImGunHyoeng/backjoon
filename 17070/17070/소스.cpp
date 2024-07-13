#include <iostream>

int arr[17][17] = { 0, };
int dp[3][17][17] = { 0, };
int N;
int number = 0;
void dfs(int x, int y, int type);
using namespace std;
int main() 
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	dfs(2, 1, 0);

	cout << number;

	return 0;
}

void dfs(int x,int y,int type)
{
	if (x == N && y == N)
	{
		number++;
		return;
	}
	switch (type)
	{
	case 0:
		{
			if (arr[y][x+1] == 0&&x+1<=N)
				dfs(x + 1, y, 0);
			if (arr[y+1][x] == 0&&arr[y+1][x+1]==0&&arr[y][x+1]==0&&x + 1 <= N&& y + 1 <= N)
				dfs(x + 1, y+1, 2);
		}
			break;
	case 1:
		{
			if (arr[y+1][x] == 0&&y + 1 <= N)
				dfs(x, y+1, 1);
			if (arr[y + 1][x] == 0 && arr[y + 1][x + 1] == 0 && arr[y][x + 1] == 0 && x + 1 <= N&& y + 1 <= N)
				dfs(x + 1, y + 1,2);

		}
			break;
	case 2:
		{
			if (arr[y][x + 1] == 0&&x + 1 <= N)
				dfs(x + 1, y, 0);
			if (arr[y + 1][x] == 0&& y + 1 <= N)
				dfs(x , y+1, 1);
			if (arr[y + 1][x] == 0 && arr[y + 1][x + 1] == 0 && arr[y][x + 1] == 0 &&x + 1 <= N&& y + 1 <= N)
				dfs(x + 1, y + 1, 2);
		}
			break;
	}
}