#include <iostream>

using namespace std;

int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int cnt, n, r;
int order[8];


void combination(int now, int pos)
{
	if (now == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << arr[order[i]] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = pos; i <= n; i++)
	{
		order[now] = arr[i];
		combination(now + 1, i);
	}
}

int main()
{
	cin >> n;
	cin >> r;

	combination(0, 1);
}