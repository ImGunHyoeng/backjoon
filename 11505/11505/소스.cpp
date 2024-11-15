#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class SegmentTree {
public:
    SegmentTree(const std::vector<long long>& data);
    long long query(long long left, long long right); // ���� �� ���� �Լ�
    void update(long long index, long long value); // ���� �� ������Ʈ �Լ�

private:
    std::vector<long long> tree; // ���׸�Ʈ Ʈ�� �迭
    long long n; // ���� �迭�� ũ��

    void build(const std::vector<long long>& data, long long node, long long start, long long end); // Ʈ�� ���� �Լ�
    long long query(long long node, long long start, long long end, long long left, long long right); // ���� �Լ�
    void update(long long node, long long start, long long end, long long index, long long value); // ������Ʈ �Լ�
};

SegmentTree::SegmentTree(const std::vector<long long>& data) {
    n = data.size();
    long long height = std::ceil(std::log2(n));
    long long maxSize = 2 * std::pow(2, height) - 1;
    tree.resize(maxSize, 0);
    build(data, 0, 0, n - 1);
}

// Ʈ�� ���� �Լ� ����
void SegmentTree::build(const std::vector<long long>& data, long long node, long long start, long long end) {
    if (start == end) {
        tree[node] = data[start] % 1000000007;
    }
    else {
        long long mid = (start + end) / 2;
        build(data, 2 * node + 1, start, mid);
        build(data, 2 * node + 2, mid + 1, end);
        tree[node] = (tree[2 * node + 1] * tree[2 * node + 2]) % 1000000007;
    }
}

long long SegmentTree::query(long long left, long long right) {
    return query(0, 0, n - 1, left, right);
}

// ���� �� ���� �Լ� ���� (����� ����)
long long SegmentTree::query(long long node, long long start, long long end, long long left, long long right) {
    if (right < start || end < left) {
        return 1; // ���� ���� ���
    }
    if (left <= start && end <= right) {
        return tree[node] % 1000000007; // ���� ���� ���
    }
    long long mid = (start + end) / 2;
    long long multiflyLeft = query(2 * node + 1, start, mid, left, right);
    long long multiflyRight = query(2 * node + 2, mid + 1, end, left, right);
    return (multiflyLeft * multiflyRight)% 1000000007;
}

void SegmentTree::update(long long index, long long value) {
    update(0, 0, n - 1, index, value);
}

// ���� �� ������Ʈ �Լ� ���� (����� ����)
void SegmentTree::update(long long node, long long start, long long end, long long index, long long value) {
    if (start == end) {
        tree[node] = value % 1000000007;
    }
    else {
        long long mid = (start + end) / 2;
        if (index <= mid) {
            update(2 * node + 1, start, mid, index, value);
        }
        else {
            update(2 * node + 2, mid + 1, end, index, value);
        }
        tree[node] = (tree[2 * node + 1] * tree[2 * node + 2]) % 1000000007;
    }
}

int main()
{
    vector<long long> arr;
    long long N;
    long long M;
    long long K;
    cin >> N;
    cin >> M;
    cin >> K;
    for (long long i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }

    SegmentTree segTree(arr);
    long long A, B, C;
    for (long long i = 0; i < M + K; i++)
    {
        cin >> A;
        cin >> B;
        cin >> C;
        if (A == 1)
        {
            segTree.update(B-1, C);
        }
        else
        {
            cout<<segTree.query(B-1, C-1)<<"\n";
        }
    }
	return 0;
}