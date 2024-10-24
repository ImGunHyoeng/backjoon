#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//부모 노드를 찾기
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
	//부모를 구할 때 재귀 적으로 자신의 부모의 값을 넣어서 구해야한다.
}
//두 부모 노드를 합치는 함수(부모가 작은 값으로 합침
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}
//같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;

}
class Edge
{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int weight)
	{
		node[0] = a;
		node[1] = b;
		distance = weight;
	}
	bool operator<(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};
int main()
{
	vector<Edge> arr;
	//priority_queue<int, vector<int>, greater<int>> heap;

	int V, E;
	int sum = 0;
	cin >> V;
	cin >> E;
	//크루스칼 정렬
	for (int i = 0; i < E; i++)
	{
		int a, b,distance;
		cin >> a;
		cin >> b;
		cin >> distance;
		arr.push_back({ a, b, distance });
	}
	sort(arr.begin(), arr.end());
	//부모값 설정
	int parent[10001] = { 0, };
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	//visited[1] = true;
	for(int i=0;i<arr.size();i++)
	{
		//부모같지 같다면 넘어감
		if (!(findParent(parent, arr[i].node[0], arr[i].node[1])))
		{
			sum+=arr[i].distance;
			unionParent(parent,arr[i].node[0],arr[i].node[1]);
		}
	}
	cout << sum;
	return 0;
}

//vector<pair<int, long long>> Cost[10001];
//long long Dist[10001] = { -2147483649, };
//int main()
//{
//	bool visited[10001] = { false, };
//	priority_queue<int, vector<int>, greater<int>> heap;
//
//	int V, E;
//	int count = 0;
//	cin >> V;
//	cin >> E;
//	visited[1] = true;
//	while (count != V - 1)
//	{
//
//	}
//
//	return 0;
//}