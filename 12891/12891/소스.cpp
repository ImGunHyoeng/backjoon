#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct cmp
{
	bool operator()(pair<int, char>& a, pair<int, char>& b)
	{
		if (a.first != b.first) {
			return a.first < b.first;
		}
		// int 값이 같을 경우 char 값을 내림차순 정렬
		return a.second > b.second;
	}
};
struct 
{
	bool operator()(char a, char b)
	{
		return a < b;
	}
}MyStruct;



bool charcmp(char a, char b)
{
	return a < b;
}

int main()
{
	int count = 0;
	vector<char> arr;
	priority_queue<pair<int, char>,vector<pair<int,char>>, cmp> pq;
	//priority_queue<pair<int, char>,vector<pair<int,char>>, greater<pair<int,char>>> pq;
	vector<int> goal(4, 0);
	vector<int> cur(4, 0);
	int n;
	int p;
	cin >> n;
	cin >> p;
	char temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> goal[0];
	cin >> goal[1];
	cin >> goal[2];
	cin >> goal[3];
	for (int i = 0; i < p; i++)
	{
		if (arr[i] == 'A')
			cur[0]++;
		if (arr[i] == 'C')
			cur[1]++;
		if (arr[i] == 'G')
			cur[2]++;
		if (arr[i] == 'T')
			cur[3]++;
		pq.push({ i,arr[i] });
	}//초기 윈도우 세팅
	
	sort(arr.begin(), arr.end(), MyStruct);
	 
	for (int i = p; i < n; i++)
	{

		if (goal[0] <= cur[0] && goal[1] <= cur[1] && goal[2] <= cur[2] && goal[3] <= cur[3])
			count++;

		if (pq.top().second == 'A')
			cur[0]--;
		if (pq.top().second == 'C')
			cur[1]--;
		if (pq.top().second == 'G')
			cur[2]--;
		if (pq.top().second == 'T')
			cur[3]--;
		pq.pop();


		if (arr[i] == 'A')
			cur[0]++;
		if (arr[i] == 'C')
			cur[1]++;
		if (arr[i] == 'G')
			cur[2]++;
		if (arr[i] == 'T')
			cur[3]++;
		pq.push({ i,arr[i] });
		//if (goal[0] <= cur[0] && goal[1] <= cur[1] && goal[2] <= cur[2] && goal[3] <= cur[3])
		//	count++;
	}

	if (goal[0] <= cur[0] && goal[1] <= cur[1] && goal[2] <= cur[2] && goal[3] <= cur[3])
		count++;
	cout << count;
	return 0;
}