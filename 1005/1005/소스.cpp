#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;
int K;
vector<int> Adj[1001];
int Timearr[1001];
int Degree[1001] = { 0, };
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int T;
	int X;
	int Y;
	int W;
	int Goal;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		
		cin >> N;
		cin >> K;
		for (int j = 0; j < N; j++)
		{
			cin >> W;
			Timearr[i] = W;
			Degree[i] = 0;
		}
		for (int j = 0; j < K; j++)
		{
			cin >> X;
			cin >> Y;
			Adj[X].push_back(Y);
			Degree[Y]++;
		}
		cin >> Goal;
		//값 입력 프로세스
		
		//계산하기
		//힙에 집어넣기
		
		
	}

	return 0;
}