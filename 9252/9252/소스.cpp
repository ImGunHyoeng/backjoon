//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//
//int main()
//{
//	string result;
//	string temp1;
//	string temp2;
//	string a;
//	string b;
//	cin >> a;
//	cin >> b;
//	//cin >> temp1;
//	//cin >> temp2;
//	//a = ' ' + temp1;
//	//b = ' ' + temp2;
//	vector<vector<int>> list(a.size()+1, vector<int>(b.size()+1));//값을 입력하기 위함
//	vector<vector<int>> c(a.size() + 1, vector<int>(b.size() + 1));
//	for (int i = 1; i <= a.size(); i++)
//	{
//		for (int j = 1; j <= b.size(); j++)
//		{
//			if (a[i-1] == b[j-1])
//			{
//				list[i][j] = list[i - 1][j - 1] + 1;
//				c[i][j] = 1;
//			}
//			else
//			{
//				list[i][j] = max(list[i][j - 1], list[i - 1][j]);
//				c[i][j] = 2;
//				if (list[i][j - 1] > list[i - 1][j])
//					c[i][j] = 3;
//			}
//
//		}
//	}
//	int i = a.size();
//	int j= b.size();
//
//	while (i >= 1 && j >= 1) {
//		if (list[i][j] > list[i - 1][j] && list[i - 1][j] == list[i][j - 1] && list[i][j - 1] == list[i - 1][j - 1]) {
//			result += b[j - 1];
//			i--;
//			j--;
//		}
//		else if (list[i - 1][j] > list[i][j - 1] && list[i - 1][j] == list[i][j]) {
//			i--;
//		}
//		else if (list[i - 1][j] < list[i][j - 1] && list[i][j - 1] == list[i][j]) {
//			j--;
//		}
//		else {
//			j--;
//		}
//	}
//
//	//while (row >= 1&&col>=1) {
//
//	//	if (c[row][col] == 3) {
//	//		row--;
//	//	}
//	//	else if (c[row][col] == 2) {
//	//		
//	//		col--;
//	//	}
//	//	else {
//	//		result += a[col];
//	//		row--, col--;
//	//	}
//
//	//}
//	for (int i = 1; i <= a.size(); i++)
//	{
//		for (int j = 1; j <= b.size(); j++)
//		{	
//			cout << list[i][j]<<" ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//	for (int i = 1; i <= a.size(); i++)
//	{
//		for (int j = 1; j <= b.size(); j++)
//		{
//			cout << c[i][j] << " ";
//		}
//		cout << '\n';
//	}
//	reverse(result.begin(), result.end());
//	cout << list[a.size()][b.size()]<<'\n';
//	cout << result;
//	//list.reserve(a.size());
//	//i,j
//	return 0;
//}

#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
string result;
int dp[1001][1001] = { 0, };

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string temp1, temp2;
	cin >> temp1;
	cin >> temp2;

	a = ' ' + temp1;
	b = ' ' + temp2;


	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			if (a[j] == b[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}



	int col = a.size() - 1;
	int row = b.size() - 1;

	while (dp[row][col]) {

		if (dp[row][col] == dp[row - 1][col]) {
			row--;
		}
		else if (dp[row][col] == dp[row][col - 1]) {
			col--;
		}
		else {
			result += a[col];
			row--, col--;
		}

	}

	for (int i = 1; i <= a.size(); i++)
	{
	for (int j = 1; j <= b.size(); j++)
	{	
		cout << dp[i][j]<<" ";
	}
	cout << '\n';
	}
	cout << '\n';
	//for (int i = 1; i <= a.size(); i++)
	//{
	//	for (int j = 1; j <= b.size(); j++)
	//	{
	//		cout << c[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	cout << dp[b.size() - 1][a.size() - 1] << endl;
	if (result.size() > 0) {
		reverse(result.begin(), result.end());
		cout << result << endl;
	}
	return 0;
}