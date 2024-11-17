#include <iostream>
#include <vector>
#include <list>//이미 체크된 값을 처리하기 위함.
using namespace std;

void update(vector<int>& tree, int node, int start, int end, int idx, int diff)
{
	if (idx < start || idx > end) return;//범위를 벗어남 의미가 start부터 end사이의 값이 몇개 있는지 의미하는건데 범위를 벗어남

	tree[node] += diff;

	if (start != end)
	{
		int m = start + (end - start) / 2;
		update(tree, node * 2, start, m, idx, diff);
		update(tree, node * 2 + 1, m + 1, end, idx, diff);
	}
}

int query(vector<int>& tree, int node, int start, int end, int kth)
{
	if (start == end)
		return end;
	int m = start + (end - start) / 2;
	int left_val = tree[node * 2];

	if (kth <= left_val) return query(tree, node * 2, start, m, kth);
	return query(tree, node * 2 + 1, m + 1, end, kth - left_val);
}

int delNum(vector<int>& tree,int node, int s, int e, int del) // (루트노드, 시작, 끝, 제거번호)
{
	tree[node]--;
	if (s == e) return 0;
	else
	{
		int mid = s + (e - s) / 2;
		if (del <= mid) return delNum(tree,2 * node, s, mid, del);
		else return delNum(tree,2 * node + 1, mid + 1, e, del);
	}
}

int main()
{
	int N;
	int K;
	
	cin >> N;
	cin >> K;
	vector<int> tree(4*N,0);

	for (int i = 1; i <= N; i++)
	{
		update(tree, 1, 1, N, i, 1);//값 초기화
	}
	int index = 1;
	cout << "<";
	for (int i = 0; i < N; i++)
	{
		int size = N - i;
		index+= K - 1;

		if (index % size == 0) index = size;
		else if (index > size) index %= size;


		// 다음 순서에 해당하는 번호 받아오기
		int num = query(tree,1, 1, N, index);

		// 해당 번호 제거 하기
		delNum(tree,1, 1, N, num);

		if (i == N - 1) cout << num;
		else cout << num << ", ";
	}
	cout << ">";
	return 0;
}