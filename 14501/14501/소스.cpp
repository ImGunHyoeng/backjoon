#include <iostream>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int price[16] = { 0, };
	int time[16] = { 0, };
	int DP[21] = { 0, };
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> time[i];
		cin >> price[i];
	}

	for (int i = N; i >= 1; i--) 
	{
		if (i + time[i] > N + 1)//������������ ���� ��츸 �����ϰ� ó��
		{
			DP[i] = DP[i + 1];
			continue;//���⿡�� ���� ���Ѱ��� �������� ���� ���ؼ� �ִ밪�� �־��־���Ѵ�.
		}
		DP[i] = max(DP[i + 1], price[i] + DP[i+time[i]]);
	}
	
	cout << DP[1];


	return 0;
}