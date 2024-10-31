#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//�θ� ��带 ã��
//#define XY pair<float,float>
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
	//�θ� ���� �� ��� ������ �ڽ��� �θ��� ���� �־ ���ؾ��Ѵ�.
}
//�� �θ� ��带 ��ġ�� �Լ�(�θ� ���� ������ ��ħ
void unionParent(int parent[], int a, int b)
{
	//�������� �Ÿ��� �ϸ� ���� ��찡 ����
	//1��и�,2��и�,3��и�,4��и� �̷������� �켱���� ���ϱ�
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
	int node[2];//��
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
	//ũ�罺Į ����
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
	//�θ� ����
	int parent[101] = { 0, };
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	//visited[1] = true;
	for (int i = 0; i < EdgeCT.size(); i++)
	{
		//�θ��� ���ٸ� �Ѿ
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