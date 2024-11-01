//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> arr;
//vector<int> result;
//
//int binarySearch(int start, int end, int target)
//{
//	int pos = 0;
//	while (start < end)
//	{
//		int mid = start+(end-start)/2;
//		
//		if (target <= arr[mid])
//			end= mid;//������ ó�� ���� ��Ȳ�� �Ȼ���, �ߺ��� ���� ��쿡 ���ܰ� ���� �� �ִ�.
//		else
//			start = mid + 1;
//
//	}
//	return end;
//}
//int main()
//{
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		int temp;
//		cin >> temp;
//		arr.push_back(temp);
//		result.push_back(0);
//	}
//	int j = 0;//result�� ũ�⸦ �ǹ���
//	result[0] = arr[0];
//	int i = 1;
//	for(i=1;i<N;i++)
//	{
//		if (result[j] < arr[i]) 
//		{//i�� j���� ū ���
//			result[j + 1] = arr[i];//i �������� �ǹ���
//			j += 1;
//		}
//		else {
//			int pos = binarySearch(0, arr.size()-1, arr[i]);
//			result[pos] = arr[i];
//		}
//	}
//	cout << j+1;
//
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[40001];
int lis[40001];

int binarySearch(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (lis[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return right;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int j = 0;
	lis[0] = arr[0];
	int i = 1;
	while (i < n) {
		if (lis[j] < arr[i]) {
			lis[j + 1] = arr[i];
			j += 1;
		}
		else {
			int pos = binarySearch(0, j, arr[i]);
			lis[pos] = arr[i];
		}
		i += 1;
	}
	cout << j + 1;
	return 0;
}