#include <iostream>
#include <queue>
using namespace std;
static char Arr[21][21] = { 0, };
static bool visited[27] = { 0, };
static int pathlength[21][21] = { 0, };
static int R;
static int C;
static int count_;
void dfs(int Row, int Col);

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	//bool visitedNode[20][20] = {0,};
	//queue<pair<int,int>> que;

	cin >> R;
	cin >> C;
	int Colcount = 0;
	int Rowcount = 0;
	while (1)
	{
		cin >> Arr[Rowcount][Colcount];
		if (R * C == (Colcount + 1) * (Rowcount + 1))
			break;
		if (Colcount + 1 == C)
		{
			Rowcount++;
			Colcount = 0;
			continue;
		}
			Colcount++;
	}
	visited[Arr[0][0] - 65] = true;//알파벳 확인
	//visitedNode[0][0]= true;//노드 확인

	//que.push({0,0});
	int Row= 0;
	int Col = 0;
	count_ = 1;
	pathlength[0][0] = 1;
	dfs(0, 0);
	//while (!que.empty())
	//{
	//	Row = que.front().first;
	//	Col = que.front().second;
	//	//visitedNode[Row][Col] = true;
	//	visited[Arr[Row][Col] - 65] = true;
	//	que.pop();
	//	//if (Arr[Row + 1][Col] != visited[Arr[Row + 1][Col] - 65])
	//	if (Row+1 <= R)
	//	//if(!visitedNode[Row+1][Col])
	//	if(!visited[Arr[Row + 1][Col] - 65])
	//	{
	//		
	//		pathlength[Row + 1][Col] = pathlength[Row][Col] + 1;
	//		if (pathlength[Row + 1][Col] > count)
	//			count = pathlength[Row + 1][Col];
	//		//que.push(Arr[Row + 1][Col]);
	//		//visitedNode[Row + 1][Col] = true;
	//		//visited[Arr[Row + 1][Col] - 65] = true;
	//		que.push({ Row + 1,Col });
	//	}
	//	if (Row-1 >= 0)
	//	//if (!visitedNode[Row - 1][Col])
	//	if (!visited[Arr[Row - 1][Col] - 65])
	//	//if(Arr[Row-1][Col]!=visited[Arr[Row + 1][Col] - 65])
	//	{

	//		pathlength[Row - 1][Col] = pathlength[Row][Col] + 1;
	//		if (pathlength[Row - 1][Col] > count)
	//			count = pathlength[Row - 1][Col];
	//		//que.push(Arr[Row - 1][Col]);
	//		//visitedNode[Row - 1][Col] = true;
	//		//visited[Arr[Row - 1][Col] - 65] = true;
	//		que.push({ Row - 1,Col });
	//	}
	//	//if(Arr[Row][Col+1]!=visited[Arr[Row + 1][Col] - 65])
	//	if (Col + 1 <= C)
	//	//if (!visitedNode[Row ][Col+1])
	//	if (!visited[Arr[Row ][Col+1] - 65])
	//	{
	//		pathlength[Row ][Col+1] = pathlength[Row][Col] + 1;
	//		if (pathlength[Row ][Col+1] > count)
	//			count = pathlength[Row ][Col+1];
	//		//que.push(Arr[Row ][Col+1]);
	//		//visitedNode[Row ][Col+1] = true;
	//		//visited[Arr[Row ][Col+1] - 65] = true;
	//		que.push({ Row,Col+1 });
	//	}
	//	if (Col -1 >= 0)
	//	//if (!visitedNode[Row][Col-1])
	//	if (!visited[Arr[Row][Col - 1] - 65])
	//	{
	//		pathlength[Row ][Col-1] = pathlength[Row][Col] + 1;
	//		if (pathlength[Row ][Col-1] > count)
	//			count = pathlength[Row ][Col-1];
	//		//que.push(Arr[Row ][Col-1]);
	//		//visitedNode[Row ][Col-1] = true;
	//		//visited[Arr[Row ][Col-1] - 65] = true;
	//		que.push({ Row,Col - 1 });
	//	}
	//}
	cout << count_;
	

	return 0;
}
void dfs(int Row, int Col)
{
	int Rowtemp = Row;
	int Coltemp = Col;
	//visitedNode[Row][Col] = true;
	//visited[Arr[Row][Col] - 65] = true;
	//que.pop();
	//if (Arr[Row + 1][Col] != visited[Arr[Row + 1][Col] - 65])
	Rowtemp = Row + 1;
	if (Rowtemp <= R-1)
		//if(!visitedNode[Row+1][Col])
		if (!visited[Arr[Rowtemp][Col] - 65])
		{

			pathlength[Rowtemp][Col] = pathlength[Row][Col] + 1;
			if (pathlength[Rowtemp][Col] > count_)
				count_ = pathlength[Rowtemp][Col];
			//que.push(Arr[Rowtemp][Col]);
			//visitedNode[Rowtemp][Col] = true;
			visited[Arr[Rowtemp][Col] - 65] = true;
			dfs(Rowtemp, Col);
			visited[Arr[Rowtemp][Col] - 65] = false;
			//que.push({ Row + 1,Col });
		}
	Rowtemp = Row - 1;
	if (Rowtemp >= 0)
		//if (!visitedNode[Row - 1][Col])
		if (!visited[Arr[Rowtemp][Col] - 65])
			//if(Arr[Row-1][Col]!=visited[Arr[Row + 1][Col] - 65])
		{
			pathlength[Rowtemp][Col] = pathlength[Row][Col] + 1;
			if (pathlength[Rowtemp][Col] > count_)
				count_ = pathlength[Rowtemp][Col];
			//que.push(Arr[Rowtemp][Col]);
			//visitedNode[Rowtemp][Col] = true;
			visited[Arr[Rowtemp][Col] - 65] = true;
			dfs(Rowtemp, Col);
			visited[Arr[Rowtemp][Col] - 65] = false;
			//que.push({ Row - 1,Col });
		}
	//if(Arr[Row][Col+1]!=visited[Arr[Row + 1][Col] - 65])
	Coltemp = Col+ 1;
	if (Coltemp <= C-1)
		//if (!visitedNode[Row ][Col+1])
		if (!visited[Arr[Row][Coltemp] - 65])
		{
			pathlength[Row][Coltemp] = pathlength[Row][Col] + 1;
			if (pathlength[Row][Coltemp] > count_)
				count_ = pathlength[Row][Coltemp];
			//que.push(Arr[Row ][Col+1]);
			//visitedNode[Row ][Col+1] = true;
			visited[Arr[Row][Coltemp] - 65] = true;
			dfs(Row, Coltemp);
			visited[Arr[Row][Coltemp] - 65] = false;
			//que.push({ Row,Col + 1 });
		}
	Coltemp= Col- 1;

	if (Coltemp>= 0)
		//if (!visitedNode[Row][Col-1])
		if (!visited[Arr[Row][Coltemp] - 65])
		{
			pathlength[Row][Coltemp] = pathlength[Row][Col] + 1;
			if (pathlength[Row][Coltemp] > count_)
				count_ = pathlength[Row][Coltemp];
			//que.push(Arr[Row ][Col-1]);
			//visitedNode[Row ][Col-1] = true;
			visited[Arr[Row ][Coltemp] - 65] = true;
			dfs(Row, Coltemp);
			visited[Arr[Row ][Coltemp] - 65] = false;
			//que.push({ Row,Coltemp });
		}
	return;
}

