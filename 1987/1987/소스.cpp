#include <iostream>
using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char Arr[20][20] = {0,};
	bool visited[26] = { 0, };

	int R;
	int C;
	cin >> R;
	cin >> C;
	int Colcount = 0;
	int Rowcount = 0;
	while (1)
	{
		cin >> Arr[Rowcount][Colcount];
		if (R * C == (Colcount + 1) * (Rowcount + 1))
			break;
		if (Colcount + 1 == C)
		{
			Rowcount++;
			Colcount = 0;
			continue;
		}
			Colcount++;
	}
	visited[Arr[0][0] - 65] = true;//알파벳 확인


	return 0;
}