#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> arr;
int number = 0; // ���ϰ��� �ϴ� �Ҽ��� ����
int primeNum[4000001];

void primeNumberSieve()
{
    // primeNum �迭 �ʱ�ȭ
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) ������ ���� �̹� �˻������Ƿ� j�� i*i ���� �˻����ش�.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    // �Ҽ� ���
    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0)
        {
            arr.push_back(primeNum[i]);
            //printf("%d\n", primeNum[i]);
        }
    }
}
int main()
{
    
    cin >> number;
    primeNumberSieve();
    int left = 0, right = 0;
    int sum = 0;
    int size = 0;
    int ct = 0;
    while (left < arr.size())
    {
        if (sum == number)
        {
            ct++;
            sum -= arr[left];
            left++;
        }
        else if (sum < number)
        {
            if (right >= arr.size())
                break;
            sum += arr[right];
            right++;
            
        }
        else
        {
            sum -= arr[left];
            left++;
        }
    }
    cout << ct;
}