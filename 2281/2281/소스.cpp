//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//const int N_MAX = 1000;
//int n, m;
//vector<int> dp(N_MAX, INT_MAX);
//vector<int> names(N_MAX, 0);
//
//int solution(int idx) {
//	//����� �� ������ �ٷ� ����
//	if (dp[idx] < INT_MAX)
//		return dp[idx];
//
//	int remain = m - names[idx]; //�ڿ� ���� �̸��� �̾���� �� �ִ��� ����ϱ� ���� ����
//
//	for (int i = idx + 1; i <= n && remain >= 0; i++) {
//		//i��° �̸��� ��� �̾�ٿ�������. ���� ���� ���� �ʴ� ������..(remain >= 0)
//		if (i == n) {
//			//���� ���� �ʰ� ��� �̸��� �̾���� ����.. �׷��� ������ ���̶�� ���̴ϱ� ������ dp[idx] = 0�� �ȴ�.
//			dp[idx] = 0;
//			break;
//		}
//		dp[idx] = min(dp[idx], remain * remain + solution(i)); //��� ȣ��
//		remain -= names[i] + 1; //names[i]�� �̾�ٿ����Ƿ� �̸� ������ �� ĭ(1) + names[i] ���̸�ŭ�� remain(���� ĭ ��)���� ���ش�.
//	}
//
//	return dp[idx];
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		cin >> names[i];
//
//	dp[n - 1] = 0;
//
//	cout << solution(0) << endl;
//
//	return 0;
//}
#include <iostream>

#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int p[1111], d[1111];

int go(int i) {
    int& ret = d[i];
    if (ret != -1) return ret;

    ret = INF;
    for (int j = i, sum = p[i]; j < n && sum < m + 1; j++, sum += p[j] + 1) {
        if (j == n - 1) {
            ret = 0;
        }
        else {
            int rest = m - sum;
            ret = min(ret, rest * rest + go(j + 1));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    memset(d, -1, sizeof(d));
    cout << go(0);
}