#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> arr;
int number = 0; // 구하고자 하는 소수의 범위
int primeNum[4000001];

void primeNumberSieve()
{
    // primeNum 배열 초기화
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    // 소수 출력
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