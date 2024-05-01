#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Start;
	int Goal;

	cin >> Start;
	cin >> Goal;

	//vector<int> bfsArr;
	queue<pair<int, int>> bfsArr;
	bool bfsVisited[100001] = { false, };
	int parent[100001] = { 0, };
	//���⿡�� ������ ���� �ε����� ��ȣ�� �Է��س��´�.
	vector<int> resultArrIndex;
	vector<int> resultArr;
	int resultLayer = 0;
	//bfsArr.push_back(Start);
	bfsArr.push({ Start,0 });
	bfsVisited[Start] = true;
	int i = 0;
	int sum = 0;
	int location;
	//���̾� ������ 3���� �����鼭 ���������ϴ�.
	while (1)
	{
		location= bfsArr.front().first;
		resultLayer = bfsArr.front().second;
		bfsArr.pop();
		if (location == Goal)
		{
			resultArrIndex.push_back(i);
			break;
		}
		//if (sum > bfsArr.size())
		if (location * 2 >= 0 && location * 2 <= 100000 && bfsVisited[location * 2] == false)
		{
			parent[location * 2] = location;
			bfsArr.push({location * 2,resultLayer+1});
			bfsVisited[location *2] = true;
		}
		if (location + 1 >= 0 && location + 1 <= 100000 && bfsVisited[location + 1] == false)
		{
			parent[location +1] = location;
			bfsArr.push({location + 1,resultLayer+1});
			bfsVisited[location + 1] = true;
		}
		if (location - 1 >= 0 && location - 1 <= 100000 && bfsVisited[location - 1] == false)
		{
			parent[location -1] = location;
			bfsArr.push({location - 1,resultLayer+1});
			bfsVisited[location - 1] = true;
		}
	}

	cout << resultLayer<< '\n';

	int temp = resultArrIndex[0];
	location = Goal;
	while (location!=Start)
	{
		resultArr.push_back(location);
		location = parent[location];
	}
	resultArr.push_back(Start);
	reverse(resultArr.begin(), resultArr.end());
	
	for (auto it = resultArr.begin(); it != resultArr.end(); it++)
		cout << *it << ' ';


	return 0;
}
