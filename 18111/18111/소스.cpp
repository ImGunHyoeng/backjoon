#include <iostream>
using namespace std;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, B;
	cin >> N;
	cin >> M;
	cin >> B;

	int** zinform = new int*[N];
	for (int i = 0; i < N; i++)
	{
		zinform[i] = new int[M];
	}

	//int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> zinform[i][j];
		}
	}

	//�ְ� �� ���ϱ�
	int topvalue = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (topvalue < zinform[i][j])
				topvalue = zinform[i][j];
		}
	}

	//�ð��� ����
	int result[2];
	result[0]=-1;

	//������ ���� ������ ���ϱ�
	for (int i = topvalue; i >= 0; i--)
	{

		int time;
		int height;
		int plusblock = 0;
		int minusblock = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (i < zinform[y][x])
					plusblock+= zinform[y][x]-i;
				if (i > zinform[y][x])
					minusblock+= i- zinform[y][x];
			}
		}
		if (plusblock + B < minusblock)//���ΰ����� ä������ ����� ���� ��쿡 �ذ����� ����.
			continue;
		//���� �ɸ��ð� ���� ����ϴ� �� �ϱ�
		//�ֳĸ� ������ �ȵǴ� ��츦 Ȯ�������⿡ �Ǵ� ����� ���� ����

		time= minusblock + plusblock * 2;
		height = i;
		if (result[0] == -1)
		{
			result[0] = time;
			result[1] = height;
			continue;
		}
		if (result[0] > time)
		{
			result[0] = time;
			result[1] = height;
		}
	}
	cout << result[0] << ' ' << result[1];
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << zinform[i][j]<<' ';
	//	}
	//	cout << '\n';
	//}
	
	for (int i = 0; i < N; i++)
	{
		delete [] zinform[i];
	}
	delete[] zinform;
	return 0;
}