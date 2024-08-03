#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int degree[101] = { 0, };
int counts[101] = { 0, };
//int result[101] = { 0, };

int N;
int M;
void calculate(int target, int requirednum, int multiply);
vector<pair<int, int>> arr[101];


int main()
{
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	int X, Y, K;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> K;
		arr[X].push_back({ Y,K });
		degree[X]++;
	}

	//for (int i = 1; i <= N; i++)
	//{
	//	if(arr[i].size()!=0)
	//		cout << arr[i].front().first <<" " << arr[i].front().second;
	//}

	//마지막 경우의 수로 값을 계산
	for(int i=0;i<degree[N];i++)
	{
		calculate(arr[N][i].first, arr[N][i].second, 1);
	}

	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0&&counts[i]!=0)
			cout << i << " " << counts[i]<<'\n';
	}

	return 0;
}
void calculate(int target, int requirednum, int multiply)
{
	if (degree[target] == 0)
	{
		counts[target] += requirednum * multiply;
		return;
	}

	for (int i = 0; i < degree[target]; i++)
	{
		calculate(arr[target][i].first, arr[target][i].second, requirednum*multiply);//배수를 또 넣어줘야한다.
	}
}