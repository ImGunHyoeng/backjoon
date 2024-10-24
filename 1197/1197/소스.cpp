#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//next, distance
vector<pair<int, long long>> Cost[10001];
long long Dist[10001] = {-2147483649,};
int main()
{
	bool visited[10001] = { false,};
	priority_queue<int, vector<int>, greater<int>> heap;

	int V, E;
	int count = 0;
	cin >> V;
	cin >> E;
	visited[1] = true;
	while(count != V - 1)
	{

	}
	
	return 0;
}