#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 800000 * 3;
int dist[801];
vector<pair<int, int>> a[801];
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
int N, E;
void daikstra(int start)
{
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[start] = 0;
	priority_queue <pair<int, int>>pq;
	pq.push({ 0,start });//거리값,노드 인덱스
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (dist[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++)
		{
			//인접 노드
			int next = a[current][i].second;
			//인접노드 거쳐서
			int nextdistance = distance + a[current][i].first;
			if (nextdistance < dist[next])
			{
				dist[next] = nextdistance;
				pq.push({ -nextdistance,next });
			}

		}
	}
}
int main()
{
	int result = INF;

	cin >> N;
	cin >> E;
	
	for (int i = 0; i < E; i++)
	{
		int x, y, c;
		cin >> x;
		cin >> y;
		cin >> c;
		a[x].push_back({ c,y });
		a[y].push_back({ c,x });
	}
	int v1, v2;
	cin >> v1;
	cin >> v2;
	//int temp = 0;
	daikstra(1);
	//for (int i = 1; i <= N; i++)
	//	cout <<i<< dist[i]<<' '<< '\n';
	//cout << '\n';
	sToV1 = dist[v1];
	sToV2 = dist[v2];

	daikstra(v1);
	//for (int i = 1; i <= N; i++)
	//	cout << i << dist[i] << ' ' << '\n';
	//cout << '\n';
	V1ToV2 = dist[v2];
	V1ToN = dist[N];

	daikstra(v2);
	//for (int i = 1; i <= N; i++)
	//	cout << i << dist[i] << ' ' << '\n';
	//cout << '\n';
	//V1ToV2 = dist[v1];
	V2ToN = dist[N];

	result = min(result, sToV1 + V1ToV2 + V2ToN);
	result = min(result, sToV2 + V1ToV2 + V1ToN);
	if (V1ToV2 == INF || result == INF)cout << -1;
	else cout << result;
}