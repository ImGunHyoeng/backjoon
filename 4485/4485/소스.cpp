#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000
//vector<pair<int, int>> arr[126];
int input[126][126];

bool visted[126][126];
queue<pair<int, int>> que;
int Distancemin[126][126];

int N;
void BFS(int row, int col);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> N;
	int count = 1;
	int result = 0;
	while (N != 0) 
	{
		for (int i = 1; i <= N; i++)
		{
			
			for (int j = 1; j <= N; j++)
			{
				cin >> input[i][j];
				Distancemin[i][j] = INF;
				visted[i][j] = false;
			}
		}
		//for (int i = 1; i <= N; i++)
		//{
		//	arr[i].push_back(make_pair(i,input[i][i]))
		//}\

		BFS(1, 1);
		
		
		
		result = Distancemin[N][N];
		cout << "Problem " << count << ": " << result<<'\n';
		count++;
		cin >> N;
	}
	
}

void BFS(int row, int col)
{
	Distancemin[row][col] = input[row][col];
	que.push(make_pair(row, col));
	while (!que.empty())
	{
		int r = que.front().first;
		int c = que.front().second;
		que.pop();
		//if (visted[r][c])
		//	continue;
		if (Distancemin[r][c] + input[r][c + 1] < Distancemin[r][c + 1] && c + 1 <= N)
		{
			Distancemin[r][c+1] = Distancemin[r][c] + input[r][c + 1];
			que.push({ r,c + 1 });
		}


		if (Distancemin[r][c] + input[r + 1][c] < Distancemin[r + 1][c] && r + 1 <= N)
		{
			Distancemin[r+1][c] = Distancemin[r][c] + input[r + 1][c];
			que.push({ r+1,c });
		}

		if (Distancemin[r][c] + input[r - 1][c] < Distancemin[r - 1][c] && r - 1 >= 0)
		{
			Distancemin[r-1][c] = Distancemin[r][c] + input[r - 1][c];
			que.push({ r-1,c });
		}

		if (Distancemin[r][c] + input[r][c - 1] < Distancemin[r][c - 1] && c - 1 >= 0)
		{
			Distancemin[r][c-1] = Distancemin[r][c] + input[r][c - 1];
			que.push({ r,c - 1 });
		}
		//visted[r][c] = true;
	}
	//for (int i = 1; i <= N; i++)
	//{
	//	for (int j = 1; j <= N; j++)
	//	{
	//		
	//		if (Distancemin[i][j] + input[i][j + 1] < Distancemin[i][j+1]&&j+1<=N)
	//			Distancemin[i][j] = Distancemin[i][j] + input[i][j + 1];

	//		if (Distancemin[i][j] + input[i+1][j] < Distancemin[i+1][j] && i + 1 <= N)
	//			Distancemin[i][j] = Distancemin[i][j] + input[i + 1][j ];

	//		if (Distancemin[i][j] + input[i - 1][j] < Distancemin[i-1][j] && i - 1 >=0)
	//			Distancemin[i][j] = Distancemin[i][j] + input[i-1][j];

	//		if (Distancemin[i][j] + input[i][j - 1] < Distancemin[i][j-1] && j - 1 >=0)
	//			Distancemin[i][j] = Distancemin[i][j] + input[i][j - 1];
	//					
	//	}
	//}
}
//void Dijkstra(int row,int col)
//{
//	Distancemin[row][col];
//	visted[1][1] = true;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			visted[i][j] = true;
//			if(Distancemin[i][j]+<Distancemin[i][j])
//		}
//	}
//}