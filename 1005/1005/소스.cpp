#include <iostream>
#include <vector>
#include <queue>
//#include <map>
//#include <algorithm>

using namespace std;

int N;
int K;
vector<int> Adj[1001];//��������
int Timearr[1001];//�ǹ� ���� �ð�
int Degree[1001] = { 0, };//��������
int Result[1001] = { 0, };//�ּҽð�
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int T;
	int X;
	int Y;
	int W;
	int Goal;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		
		cin >> N;
		cin >> K;
		for (int j = 0; j < N; j++)
		{
			cin >> W;
			Timearr[i] = W;
			Degree[i] = 0;
		}
		for (int j = 0; j < K; j++)
		{
			cin >> X;
			cin >> Y;
			Adj[X].push_back(Y);
			Degree[Y]++;
		}
		cin >> Goal;
		//�� �Է� ���μ���

		queue<int> Q;
		while (int i = 1; i <= N; i++)
			if (Degree[i] == 0)Q.push(i);
		while (Degree[0] > 0)
		{
			int target = Q.front();
			Q.pop();

			for (int j = 0; j < Adj->size(); j++)
			{
				
				result[next] = max(result[next], result[u] + time[u]);
				if (--pre[next] == 0) Q.push(next);
				
			}
		}
		//����ϱ�
		//���� ����ֱ�
		//make_heap(arr, arr + 10, [](int _t1, int _t2) ->bool {
		//	return (_t1 < _t2);
		//	});
	}

	return 0;
}