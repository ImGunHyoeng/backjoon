#include <iostream>
#include <vector>
using namespace std;
vector<long long>arr;
vector<long long>tree;
long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;

	return tree[node] = max(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}
int main()
{
	long long result=0;
	int n;
	cin >> n;
	int k;
	cin >> k;
	
	tree.assign(4 * k + 1, 0);
	for (int i = 0; i <n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	init(arr, tree, 1, 0, k-1);

	//update() ¸î¹ø Ä­
	//int count = 1;
	//for (int i = 0; i <= n-k+1; i++)
	//{
	//	if (count == (k + 1) / 2)
	//	{
	//		result += arr[i];
	//		continue;
	//	}
	//	count++;
	//}
	cout << result;
	return 0;
}