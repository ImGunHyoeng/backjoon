//#include <iostream>
//#include <queue>
//#include <bitset>
//#include <string>
//
//using namespace std;
// 
//int dp[100000] = { 0, };
//int ans;
//int n;
//
//int btod(string binary)
//{
//	int 
//	int res;
//	for (int i = 1; a >= 1; i *= 10) {
//		res = (a % 2) * i + res;
//		a /= 2;
//	}
//}
//
//int dtob(string binary)
//{
//	int
//		int res;
//	for (int i = 1; a >= 1; i *= 10) {
//		res = (a % 2) * i + res;
//		a /= 2;
//	}
//}
//
//
//void bfs(int start)
//{
//	
//	queue<pair<int, int>> queue;
//	queue.push({ 0,0 });
//	get_binary
//	for (int i = 0; i < n; i++)
//	{
//		//비트마스킹 처리
//		for (int j = 0; j < 3; j++)
//		{
//			
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//	int start;
//	cin >> n;
//	cin >> ans;
//	cin >> start;
//	bfs(start);
//	return 0;
//}


#include <iostream>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n, ans = MAX, cnt = 0;
string st, dt, temp;

void input() {
    cin >> n;
    cin >> st;
    cin >> dt;
}

void lightOn(int idx) {
    if (idx > 0) temp[idx - 1] = (temp[idx - 1] == '0') ? '1' : '0';
    temp[idx] = (temp[idx] == '0') ? '1' : '0';
    if (idx < n - 1) temp[idx + 1] = (temp[idx + 1] == '0') ? '1' : '0';
}

void solve(int first) {
    temp = st;
    cnt = 0;
    if (first == 0) {
        temp[0] = (temp[0] == '0') ? '1' : '0';
        temp[1] = (temp[1] == '0') ? '1' : '0';
        cnt++;
    }
    for (int i = 1; i < n; i++) {
        if (temp[i - 1] != dt[i - 1]) {
            lightOn(i);
            cnt++;
        }
    }
    if (temp == dt) ans = min(ans, cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve(0);
    solve(1);
    if (ans != MAX) cout << ans << "\n";
    else cout << -1 << "\n";
    return 0;
}