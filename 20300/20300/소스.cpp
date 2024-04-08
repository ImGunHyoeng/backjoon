#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int min = -1;
	vector<long long> vec;
	int N;
	cin >> N;
	long long *arr = new long long[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		vec.push_back(arr[i]);
	}
	sort(vec.begin(), vec.end());//오름차순 정렬

	long long containe = 0;
	long long result = 0;
	if (N % 2 != 0)
	{
		result = vec[N - 1];
		N -= 1;
	}

	for (int i = 0; i < N / 2; i++)
	{
		containe = vec[i] + vec[(N - 1) -i];
		if (containe > result)
			result = containe;
	}
	cout << result;
	


	return 0;
}