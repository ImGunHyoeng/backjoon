#include <iostream>
#include <vector>
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
}