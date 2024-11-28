//#include <iostream>
//#include <map>
//#include <vector>
//
//using namespace std;
//int x = 0, y = 0, z = 0, k = 0, mx = -1;
//int n;
//map<int, int> mp;
//vector<int> vec;
//void findLeft(int s1, int e1, int s2, int e2)
//{
//	if (e1 == -1 || s2 == n)
//		return;
//	int left=s1, right=s2;
//	int sum = 0;
//	for (int i = 0; i < (n / 2); i++)
//	{
//		y = vec[left];
//		z = vec[right];
//		sum = (x + y + z);
//		if (mp.find(sum)!=mp.end())
//		{
//			if (mx < sum)
//				mx = sum;
//		}
//		if (left < e1)
//			left++;
//		if (right < abs(e2))
//			right++;
//
//	}
//}
//int main()
//{
//
//	
//	cin >> n;
//	int temp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		vec.push_back(temp);
//		mp.insert({ temp,temp });
//	}
//	for (int i = 0; i < n; i++)
//	{
//		x = vec[i];
//		findLeft(0, i - 1, i + 1, n - 1);
//	}
//	cout << mx;
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int num;
    cin >> num;;

    int arr[1005];
    vector<int> two;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + num);

    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            two.push_back(arr[i] + arr[j]);
        }
    }

    sort(two.begin(), two.end());

    int result = 0;
    for (int i = 0; i < num; i++) {
        for (int j = i; j < num; j++) {
            if (binary_search(two.begin(), two.end(), arr[j] - arr[i])) {
                result = max(result, arr[j]);
            }
        }
    }

    cout << result;
}