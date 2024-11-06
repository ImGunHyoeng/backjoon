#include <iostream>
#include <queue>

using namespace std;

priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l, x;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push({ x, i });
        while (pq.top().second < i - l + 1) pq.pop();//최소값만 구하기에 이를 top의 값으로만 계산
        cout << pq.top().first << " ";
    }
}


//덱으로 풀이 방법
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    deque <pair <int, int>> d;
    int n, l, x;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (!d.empty() && d.front().second < i - l + 1) d.pop_front();
        while (!d.empty() && d.back().first > x) d.pop_back();
        d.push_back({ x, i });
        cout << d.front().first << " ";
    }
}