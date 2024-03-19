//#include <iostream>
//#include <queue>
//
//int main()
//{
//	struct cowvote
//	{
//		int first;
//		int second;
//		int index;
//	};
//	struct cmp 
//	{
//		bool operator()(cowvote &a, cowvote& b) 
//		{
//			return a.first > b.first;
//		}
//	};
//	using namespace std;
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N;
//	int K;
//	int input1=0;
//	int input2=0;
//	cowvote temp={ 0,0,0 };
//	cin >> N;
//	cin >> K;
//	priority_queue<cowvote, vector<cowvote>, cmp> queue;
//	
//
//	for (int i = 0;  i < N && cin >> input1>> input2 ; i++)
//	{
//		queue.push(cowvote{ input1,input2,i + 1 });
//	}
//
//	for (int i = 0; i < N-K; i++)
//	{
//		queue.pop();
//	}
//	for (int i = 0; i < K; i++)
//	{
//		if (temp.second < queue.top().second)
//		{
//			temp = queue.top();
//		}
//		queue.pop();
//
//	}
//	cout << temp.index;
//
//	
//
//	return 0;
//}