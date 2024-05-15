//DFS
//#include <iostream>
//#include <vector>
//#define INF 100000000
//using namespace std;
//struct Pos
//{
//	Pos(int _x, int _y)
//	{
//		x = _x;
//		y = _y;
//	}
//	int x;
//	int y;
//};
//void dfs(int x, int y, int count);
//void firewilltransition(int x, int y);
//void firenottransition(int x, int y);
//void firetransition(int x, int y,int count);
//void fireextinction(int x, int y, int count);
//char arr[1002][1002] = { 0, };
//bool visted[1002][1002] = { 0, };
//bool isfired[1002][1002] = { 0, };
//vector<Pos> fireposition[1001];
//int dx[] = { 0,0,1,-1 };
//int dy[] = { 1,-1,0,0 };
//int result=INF;
//int w;
//int h;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	int x=0;
//	int y=0;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		result = INF;
//		cin >> w;
//		cin >> h;
//		for (int j = 1; j <= h; j++)
//		{
//			for (int k = 1; k <= w; k++)
//			{
//				visted[j][k] = false;
//				cin>>arr[j][k];
//				if (arr[j][k] == '*')
//				{
//					fireposition[1].push_back(Pos(k, j));
//					firewilltransition(k, j);
//				}
//				if (arr[j][k] == '@')
//				{
//					x = k;
//					y = j;
//				}
//			}
//		}
//		dfs(x, y, 0);
//		if (result == INF)
//			cout << "IMPOSSIBLE"<<'\n';
//		else
//			cout << result<<'\n';
//	}
//	return 0;
//}
//void dfs(int x, int y, int count)
//{
//	if (count >= result)
//		return;
//	if (x == 0 || y == 0 || x > w || y > h)
//	{
//		result = count;
//		return;
//	}
//	
//	//우,좌,상,하 순으로 순찰
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx>=0&&ny>=0&&nx<=1001&&ny<=1001 && visted[ny][nx] == false)
//		{
//			if (arr[ny][nx] == '\0')
//				dfs(nx, ny, count + 1);
//			if (arr[ny][nx] != '.'||isfired[ny][nx]==true) //&& arr[ny + 1][nx] == '*' && arr[ny - 1][nx] == '*' && arr[ny][nx + 1] == '*' && arr[ny][nx - 1] == '*')
//				continue;//비어있고 빈칸 옆에 불이 없을 경우에 이동
//			visted[ny][nx] = true;
//			//불 번지도록
//			for (int j = 0; j < fireposition[count].size(); j++)
//			{
//				int fx = fireposition[count][j].x;
//				int fy = fireposition[count][j].y;
//				firetransition(fx, fy, count + 1);
//			}
//			dfs(nx, ny, count + 1);
//			//불 끄기
//			for (int j = 0; j < fireposition[count].size(); j++)
//			{
//				int fx = fireposition[count][j].x;
//				int fy = fireposition[count][j].y;
//				fireextinction(fx, fy,count+1);
//			}
//			visted[ny][nx] = false;
//		}
//	}
//
//
//}
//void firetransition(int x, int y,int count)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx > 0 && ny > 0 && nx <= w && ny <= h)
//		{
//			if (arr[ny][nx] == '#')
//				continue;
//			arr[ny][nx] = '*';
//			firewilltransition(nx, ny);
//			fireposition[count].push_back(Pos(nx, ny));
//		}
//	}
//}
//void fireextinction(int x, int y, int count)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx > 0 && ny > 0 && nx <= w && ny <= h)
//		{
//			if (arr[ny][nx] == '#')
//				continue;
//			arr[ny][nx] = '.';
//			firenottransition(nx, ny);
//			fireposition[count].clear();
//		}
//	}
//}
//void firewilltransition(int x, int y)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx > 0 && ny > 0 && nx <= w && ny <= h)
//		{
//			if (arr[ny][nx] == '#')
//				continue;
//			isfired[ny][nx] = true;
//		}
//	}
//}
//void firenottransition(int x, int y)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx > 0 && ny > 0 && nx <= w && ny <= h)
//		{
//			if (arr[ny][nx] == '#')
//				continue;
//			isfired[ny][nx] = false;
//			
//		}
//	}
//}

//BFS
#define MAX 1000 + 1
#define X second
#define Y first
#include <iostream>
#include <queue>

using namespace std;

// 상하좌우
int dx[4] = { 0, 0,-1, 1 };
int dy[4] = { 1, -1, 0, 0 };

char map[MAX][MAX];
int w, h;

queue < pair<int, int>> sq;
queue < pair<int, int>> fq;

void MoveFire()
{
	int cnt = fq.size();
	for (int i = 0; i < cnt; i++)
	{
		pair<int, int> cur = fq.front();
		fq.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;
			if (map[ny][nx] != '.')
				continue;

			map[ny][nx] = '*';
			fq.push({ ny, nx });
		}
	}
}

int MoveS()
{
	int time = 0;
	while (!sq.empty())
	{
		time++;
		MoveFire();

		int cnt = sq.size();
		for (int i = 0; i < cnt; i++)
		{
			pair<int, int> cur = sq.front();
			sq.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w)
					return time;

				if (map[ny][nx] != '.')
					continue;

				map[ny][nx] = '@';
				sq.push({ ny, nx });
			}
		}
	}

	return -1;
}

void Reset(int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			map[y][x] = '.';
		}
	}
	while (!sq.empty())
		sq.pop();
	while (!fq.empty())
		fq.pop();
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> w >> h;
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> map[y][x];

				if (map[y][x] == '@')
					sq.push({ y, x });
				else if (map[y][x] == '*')
					fq.push({ y, x });
			}
		}
		int time = MoveS();
		if (time == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << time << endl;

		Reset(w, h);
	}

	return 0;
}