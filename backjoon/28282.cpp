//#include <iostream>
//int main()
//{
//	using std::cin;
//	using std::cout;
//	std::ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	
//	long long X = 0;
//	long long K = 0;
//	long long temp = 0;
//	long long count = 0;
//
//	cin >> X;
//	cin >> K;
//	long long* left = new  long long[K+1];
//	for (int i = 0; i < K+1; i++)
//		left[i] = 0;
//	long long* right= new long long[K+1];
//	for (int i = 0; i < K+1; i++)
//		right[i] = 0;
//	for (int i = 0; i < X&&cin>>temp; i++)
//	{
//		left[temp]++;
//	}
//	
//	for (int i = 0; i < X&&cin>>temp; i++)
//	{
//		right[temp]++;
//	}
//	
//
//	for (int i=1; i < K+1; i++)
//	{
//		if (left[i] == 0)
//			continue;
//		count += left[i] * (X - right[i]);
//	}
//	cout << count;
//	return 0;
//}