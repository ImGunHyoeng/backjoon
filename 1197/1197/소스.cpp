#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//�θ� ��带 ã��
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
	//�θ� ���� �� ��� ������ �ڽ��� �θ��� ���� �־ ���ؾ��Ѵ�.
}
//�� �θ� ��带 ��ġ�� �Լ�(�θ� ���� ������ ��ħ
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}
//���� �θ� �������� Ȯ��
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
	//ũ�罺Į ����
	for (int i = 0; i < E; i++)
	{
		int a, b,distance;
		cin >> a;
		cin >> b;
		cin >> distance;
		arr.push_back({ a, b, distance });
	}
	sort(arr.begin(), arr.end());
	//�θ� ����
	int parent[10001] = { 0, };
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	//visited[1] = true;
	for(int i=0;i<arr.size();i++)
	{
		//�θ��� ���ٸ� �Ѿ
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