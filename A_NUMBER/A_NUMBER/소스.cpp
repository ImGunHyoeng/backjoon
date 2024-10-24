#include <iostream>
#include <string>
#include <limits>

using namespace std;
int main()
{
	//입력의 길이, 정답 뒤의 부분만 가져오기 재귀식으로 풀이
	int N;
	cin >> N;
	long long result;
	int length = 0;
	int maxval = 1;
	//값 구하기, 나누기 10으로 하면 제귀로 해서 자리수값을 구할 수 있다. 비효율적
	//string으로 해서 길이를 구하고 이를 활용
	
	for (int i = N-1; i >= 1; i--)
	{
		int backnum = 0;
		string temp = to_string(i);
		length = temp.size();
		result = i * i;

		//뒷자리 수 구하기 한번에 하면 된다.
		backnum = result % ((int)(pow(10,length)));
		if (backnum != i)
			continue;
		maxval = i;
		break;
	}
	cout << maxval;

	return 0;
}