#include <iostream>
#include <string>
#include <limits>

using namespace std;
int main()
{
	//�Է��� ����, ���� ���� �κи� �������� ��ͽ����� Ǯ��
	int N;
	cin >> N;
	long long result;
	int length = 0;
	int maxval = 1;
	//�� ���ϱ�, ������ 10���� �ϸ� ���ͷ� �ؼ� �ڸ������� ���� �� �ִ�. ��ȿ����
	//string���� �ؼ� ���̸� ���ϰ� �̸� Ȱ��
	
	for (int i = N-1; i >= 1; i--)
	{
		int backnum = 0;
		string temp = to_string(i);
		length = temp.size();
		result = i * i;

		//���ڸ� �� ���ϱ� �ѹ��� �ϸ� �ȴ�.
		backnum = result % ((int)(pow(10,length)));
		if (backnum != i)
			continue;
		maxval = i;
		break;
	}
	cout << maxval;

	return 0;
}