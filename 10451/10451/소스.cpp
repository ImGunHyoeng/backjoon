#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr(1001,{0,0});
vector<int> visit(1001,0);
int ct = 0;
void dfs(int home,int start,int target)
{
	visit[start] = 1;
	if (visit[target]==1)
	{
		ct++;
		return;
	}
	dfs(home, target, arr[target].second);
}
int main()
{

	int T;
	int N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		ct = 0;
		cin >> N;
		for (int j = 1; j <= N; j++)
		{
			int temp;
			cin >> temp;
			arr[j] = { j,temp };
			visit[j] = 0;
		}
		for (int j = 1; j <= N; j++)
		{
			if (visit[j]==1)
				continue;
			dfs(arr[j].first, arr[j].first, arr[j].second);
		}

		cout << ct << '\n';
	}
	return 0;
}