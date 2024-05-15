#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;
char arr[1001][1001];
int result=INF;
vector<int> fireposition[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int w;
	int h;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		result = INF;
		cin >> w;
		cin >> h;
		for (int j = 0; j < w; j++)
		{
			for (int k = 0; k < h; k++)
			{
				cin>>arr[j][k];
			}
		}
		if (result == INF)
			cout << "IMPOSSIBLE";
		else
			cout << result;
	}
	return 0;
}