#include <iostream>
#include <vector>
<<<<<<< HEAD
using namespace std;
vector<long long>arr;
vector<long long>tree;
long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;

	return tree[node] = max(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}
int main()
{
	long long result=0;
	int n;
	cin >> n;
	int k;
	cin >> k;
	
	tree.assign(4 * k + 1, 0);
	for (int i = 0; i <n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	init(arr, tree, 1, 0, k-1);

	//update() 몇번 칸
	//int count = 1;
	//for (int i = 0; i <= n-k+1; i++)
	//{
	//	if (count == (k + 1) / 2)
	//	{
	//		result += arr[i];
	//		continue;
	//	}
	//	count++;
	//}
	cout << result;
	return 0;
=======
#include <deque>
using namespace std;

int n, k;

inline int mid(int s, int e) { return s + (e - s) / 2; }

void update(vector<int>& tree, int node, int start, int end, int idx, int diff)
{
    if (idx < start || idx > end) return;//범위를 벗어남 의미가 start부터 end사이의 값이 몇개 있는지 의미하는건데 범위를 벗어남

    tree[node] += diff;

    if (start != end)
    {
        int m = mid(start, end);
        update(tree, node * 2, start, m, idx, diff);
        update(tree, node * 2 + 1, m + 1, end, idx, diff);
    }
}

int query(vector<int>& tree, int node, int start, int end, int kth)
{
    if (start == end) 
        return end;
    int m = mid(start, end);
    int left_val = tree[node * 2];

    if (kth <= left_val) return query(tree, node * 2, start, m, kth);
    return query(tree, node * 2 + 1, m + 1, end, kth - left_val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    vector<int> segtree(65535 * 4);
    deque<int> dq;
    long long res = 0;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        dq.push_back(x);
        update(segtree, 1, 0, 65535, x, 1);

        if (dq.size() == k)
        {
            res += query(segtree, 1, 0, 65535, (k + 1) / 2);
            int target = dq.front();
            dq.pop_front();
            update(segtree, 1, 0, 65535, target, -1);
        }

    }

    cout << res;
>>>>>>> ae46bafe6e95435278ddd04213e32185105380fc
}