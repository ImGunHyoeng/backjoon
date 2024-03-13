#include <iostream>
#include <queue>

int main()
{
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int K;
	int input1;
	int input2;
	cin >> N;
	cin >> K;

	priority_queue <pair<int,int>, vector<pair<int, int>>,less<pair<int,int>>> queue;
	

	for (int i = 0; cin >> input1 && cin >> input2 && i < N; i++)
		queue.push(pair<int,int>{ input1,input2 });

	for (int i = 0; i < N-K; i++)
	{
		queue.pop();
	}

	

	return 0;
}