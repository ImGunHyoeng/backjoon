#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int p[1000001];
vector<int> range;

int init(int left, int right, int node) {
	if (left == right) return range[node] = p[left];//리프노드를 의미함.
	int mid = (left + right) / 2;
	return range[node] = max(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));//두개의 노드중에서 큰값을 부모노드의 값으로 지정
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (nodeRight < left || right < nodeLeft) return 0;//노드가 해당하는 범위를 벗어났다는 의미
	if (left <= nodeLeft && nodeRight <= right) return range[node];//해당하는 노드가 소속되어있다는 의미이다. 이렇게 해야 해당하는 구간에 있는 전부의 값을 가지고 와서 사용할 수있다.
	int mid = (nodeLeft + nodeRight) / 2;
	return max(query(left, right, node * 2, nodeLeft, mid), (query(left, right, node * 2 + 1, mid + 1, nodeRight)));//범위에 해당이 되지 않아서 자식노드에서 max값을 가져와서 비교 
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> p[i];
	range.resize(N*4 +1);//완전이진트리 사용
	init(0, N - 1, 1);//이진트리 생성,node는 해당하는 노드를 의미함.
	for (int i = M - 1; i <= N - M ; i++) {//0을 루트로 잡았기 때문
		int lo = i - M + 1;//왼쪽 시야범위
		int hi = i + M - 1;//오른쪽 시야범위
		cout << query(lo, hi, 1, 0, N - 1) << " ";
	}
}