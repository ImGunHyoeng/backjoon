#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}

}
int main()
{
	vector<pair<int, int>> arr;
	int n;
	cin >> n;
	int x;
	int y;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		arr.push_back({ x,y });
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].first << " " <<arr[i].second << "\n";
	}
	return 0;
}