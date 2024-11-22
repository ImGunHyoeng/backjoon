#include <iostream>

using namespace std;

int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int cnt, n, r;
int order[8];
int vec[64][64] = { 0, };

void combination(int now, int pos)
{
	if (now == r)
	{
		for (int i = 0; i < r; i++)
		{
			//vec[cnt][i]
			cout << arr[order[i]] << " ";
		}
		cout << endl;
		//cnt++;

		return;
	}

	for (int idx = pos; idx <= n; idx++)
	{
		order[now] = idx;
		combination(now + 1, idx + 1);
	}
}

int main()
{
	cin >> n;
	cin >> r;

	combination(0, 1);
}