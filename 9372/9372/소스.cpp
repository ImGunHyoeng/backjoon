#include <iostream>
#include <vector>
using namespace std;
int main()
{
	
	
	int T, N, M;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cin >> M;
		vector<int> nations;
		vector<vector<int>> directions(N+1,vector<int>( N+1,0 ));
	
		for (int j = 0; j < M; j++)
		{
			int a, b;
			cin >> a;
			cin >> b;
			directions[a][b] = 1;
			directions[b][a] = 1;
		}
		cout << N - 1 << '\n';
	}

	return 0;
}