#include <iostream>

char arr[101][101]{ '\0', };
bool visted[101][101] = { false, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
using namespace std;
void dfs(int y, int x);
void RBdfs(int y, int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	int RGBnum = 0;
	int RBnum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j= 0; j < N; j++)
		{
			if (visted[i][j] == false)
			{
				visted[i][j] = true;
				dfs(i, j);
				RGBnum++;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visted[i][j] = false;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visted[i][j] == false)
			{
				visted[i][j] = true;
				RBdfs(i, j);
				RBnum++;
			}
		}
	}
	cout << RGBnum<<" "<<RBnum;


	return 0;
}
void RBdfs(int y, int x)
{
	char near;
	for (int k = 0; k < 4; k++)
	{
		near = arr[y + dy[k]][x + dx[k]];
		if ((arr[y][x] == near|| abs(arr[y][x] - near)==11) && visted[y + dy[k]][x + dx[k]] == false)
		{
			visted[y + dy[k]][x + dx[k]] = true;
			RBdfs(y + dy[k], x + dx[k]);
		}
	}
	return;
}
void dfs(int y, int x)
{
	char near;
	for (int k = 0; k < 4; k++)
	{
		near = arr[y + dy[k]][x + dx[k]];
		if (arr[y][x] == near&& visted[y+dy[k]][x+dx[k]] == false)
		{
			visted[y + dy[k]][x + dx[k]]=true;
			dfs(y + dy[k], x + dx[k]);
		}
	}
	return;
}