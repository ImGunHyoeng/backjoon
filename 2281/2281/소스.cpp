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
//	//계산한 적 있으면 바로 리턴
//	if (dp[idx] < INT_MAX)
//		return dp[idx];
//
//	int remain = m - names[idx]; //뒤에 다음 이름을 이어붙일 수 있는지 계산하기 위한 변수
//
//	for (int i = idx + 1; i <= n && remain >= 0; i++) {
//		//i번째 이름을 계속 이어붙여가본다. 물론 줄을 넘지 않는 선에서..(remain >= 0)
//		if (i == n) {
//			//줄을 넘지 않고 모든 이름을 이어붙인 경우다.. 그러면 마지막 줄이라는 말이니까 무조건 dp[idx] = 0이 된다.
//			dp[idx] = 0;
//			break;
//		}
//		dp[idx] = min(dp[idx], remain * remain + solution(i)); //재귀 호출
//		remain -= names[i] + 1; //names[i]를 이어붙였으므로 이름 사이의 빈 칸(1) + names[i] 길이만큼을 remain(남은 칸 수)에서 빼준다.
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