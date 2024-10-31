#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//부모 노드를 찾기
//#define XY pair<float,float>
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
	//부모를 구할 때 재귀 적으로 자신의 부모의 값을 넣어서 구해야한다.
}
//두 부모 노드를 합치는 함수(부모가 작은 값으로 합침
void unionParent(int parent[], int a, int b)
{
	//원점과의 거리로 하면 같은 경우가 생김
	//1사분면,2사분면,3사분면,4사분면 이런식으로 우선순위 정하기
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
class Point
{
public:
	int myNum;
	double XY[2];
	Point(int Num,double ax, double ay)
	{
		myNum = Num;
		XY[0] = ax;
		XY[1] = ay;
		//distance = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
	}
	//bool operator<(Edge& edge)
	//{
	//	return this->distance < edge.distance;
	//}
};
class Edge
{
public:
	int node[2];//점
	double distance;
	Edge(Point axy, Point bxy)
	{
		node[0] = axy.myNum;
		node[1] = bxy.myNum;
		distance = getLength(axy, bxy);
	}
	double getLength(Point a, Point b)
	{
		
		return sqrt(pow(a.XY[0] - b.XY[0],2) + pow(a.XY[1] - b.XY[1],2));
	}
	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};
int main()
{
	vector<Point> PointCT;
	vector<Edge> EdgeCT;
	//priority_queue<int, vector<int>, greater<int>> heap;

	int V;
	double sum = 0;
	cin >> V;
	//cin >> E;
	//크루스칼 정렬
	for (int i = 1; i <= V; i++)
	{
		double a, b;
		cin >> a;
		cin >> b;
		PointCT.push_back({i, a, b});
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			EdgeCT.push_back(Edge{ PointCT[i],PointCT[j] });
		}
	}
	sort(EdgeCT.begin(), EdgeCT.end());
	//부모값 설정
	int parent[101] = { 0, };
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	//visited[1] = true;
	for (int i = 0; i < EdgeCT.size(); i++)
	{
		//부모같지 같다면 넘어감
		if (!(findParent(parent, EdgeCT[i].node[0], EdgeCT[i].node[1])))
		{
			sum += EdgeCT[i].distance;
			unionParent(parent, EdgeCT[i].node[0], EdgeCT[i].node[1]);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << sum;
	return 0;
}