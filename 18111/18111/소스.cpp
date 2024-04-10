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

	//최고 값 구하기
	int topvalue = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (topvalue < zinform[i][j])
				topvalue = zinform[i][j];
		}
	}

	//시간과 높이
	int result[2];
	result[0]=-1;

	//위에서 낮은 순으로 구하기
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
		if (plusblock + B < minusblock)//파인곳보다 채워야할 블록이 적은 경우에 해결하지 못함.
			continue;
		//이제 걸린시간 계산과 등록하는 것 하기
		//왜냐면 위에서 안되는 경우를 확정지었기에 되는 경우의 값만 들어옴

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