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

	//지우는 개수,쌓는 개수
	int arr[2];
	//위에서 낮은 순으로 구하기
	for (int i = topvalue; i >= 0; i--)
	{
		int plusblock=0;
		int minusblock=0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (i < zinform[y][x])
					plusblock++;
				if (i > zinform[y][x])
					minusblock++;
			}
		}
		if (plusblock + B - minusblock != 0)//땅을 고를수 없는 경우
			continue;
		//이제 걸린시간 계산과 등록하는 것 하기
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << zinform[i][j]<<' ';
		}
		cout << '\n';
	}
	
	for (int i = 0; i < N; i++)
	{
		delete [] zinform[i];
	}
	delete[] zinform;
	return 0;
}