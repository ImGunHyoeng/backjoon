///*
//가볍게 생각하면 선택정렬을 할 때 최소값과 index를 변경할 때 i와 j의 거리를 측정
//
//	해당하는 인덱스의 값이 몇번 변하는지를 측정
//*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//bool cmp(pair<int, int> a, pair<int, int> b)
//{
//	return a.first < b.first;
//}
//
//int main()
//{
//	
//	
//	int n;
//	cin >> n;
//	vector<pair<int,int>> arr;//first value,second index
//	map<int, int> ct;
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//		
//		arr.push_back({ temp,i }); 
//		ct.insert({ i,0 });
//	}
//	sort(arr.begin(), arr.end(),cmp);
//	int index = 0;
//	int length;
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		int min = 500001;
//		//index = arr[i].second;//index 값 구하기 가능
//	
//		//
//		//auto it=find(arr.begin(), arr.end(), i);
//		//it
//		//for (int j = i; j < n; j++)
//		//{
//		//	if (min > arr[j])
//		//	{
//		//		min = arr[j];//번호 이름
//		//		index = j;
//		//	}
//		//}
//		
//		if (arr[i].second== i)
//			continue;
//
//		temp =arr[i].second;//i의 인덱스
//		for (int j = i; j < n; j++)
//		{
//			if (arr[j].second == i)
//			{
//				index = j;
//				break;
//			}
//		}
//		length = abs(arr[i].second - arr[index].second);
//
//		arr[i].second = index;
//		arr[index].second= temp;
//
//		ct[arr[index].first-1] += length;
//		ct[arr[i].first-1] += length;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << ct[i] << " ";
//	}
//	return 0;
//}
#include <iostream>
using namespace std;

int n;
int arr[500001] = { 0 };
int numInfo[500001] = { 0 };
int answerCounts[500001] = { 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];

        numInfo[arr[i]] = i;  // 특정숫자가 몇번째 인덱스에 있는지 저장.
    }

    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] == i) continue;

        int targetIndex = numInfo[i]; // 현재 자리로 옮겨야 할 숫자 i가 있는 인덱스.

        answerCounts[arr[i]] += targetIndex - i;
        answerCounts[i] += targetIndex - i;

        numInfo[i] = i;
        numInfo[arr[i]] = targetIndex;
        arr[targetIndex] = arr[i];
        arr[i] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", answerCounts[i]);
    }
}