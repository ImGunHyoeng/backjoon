///*
//������ �����ϸ� ���������� �� �� �ּҰ��� index�� ������ �� i�� j�� �Ÿ��� ����
//
//	�ش��ϴ� �ε����� ���� ��� ���ϴ����� ����
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
//		//index = arr[i].second;//index �� ���ϱ� ����
//	
//		//
//		//auto it=find(arr.begin(), arr.end(), i);
//		//it
//		//for (int j = i; j < n; j++)
//		//{
//		//	if (min > arr[j])
//		//	{
//		//		min = arr[j];//��ȣ �̸�
//		//		index = j;
//		//	}
//		//}
//		
//		if (arr[i].second== i)
//			continue;
//
//		temp =arr[i].second;//i�� �ε���
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

        numInfo[arr[i]] = i;  // Ư�����ڰ� ���° �ε����� �ִ��� ����.
    }

    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] == i) continue;

        int targetIndex = numInfo[i]; // ���� �ڸ��� �Űܾ� �� ���� i�� �ִ� �ε���.

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