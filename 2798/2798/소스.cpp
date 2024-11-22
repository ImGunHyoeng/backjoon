#include <iostream>

using namespace std;
int arr[101] = { -1, };
int goal = 0;
int result = -1;
int r = 3;
int order[3];
int n;
void combination(int now, int pos)
{
	if (now == r)
	{
		int sum = 0;
		for (int i = 0; i < r; i++) 
		{
			sum += order[i];
		}
		if (sum > goal)
			return;
		if (sum > result)
			result = sum;
	}
	else
	{
		for (int i = pos; i <= n; i++)
		{
			order[now] = arr[i];
			combination(now + 1, i + 1);
		}
	}
}

int main()
{
	
	cin >> n;
	cin >> goal;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	combination(0, 1);

	cout << result;
	return 0;
}