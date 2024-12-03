#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int curSum = 0;
	bool minuscondition = false;
	int minussum = 0;
	int curnum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
		{
			if (minuscondition)
			{
				minussum += curnum;
				curnum = 0;
			}
			else
			{
				curSum += curnum;
				curnum = 0;
			}
			curSum -= minussum;
			minussum = 0;
			minuscondition = true;
			continue;
		}
		if (str[i] == '+')
		{
			if (minuscondition)
			{
				minussum += curnum;
				curnum = 0;
			}
			else
			{
				curSum += curnum;
				curnum = 0;
			}
			continue;
		}
		curnum *= 10;
		curnum += str[i]-'0';
	}
	if (minuscondition)
	{
		minussum += curnum;
		curSum -= minussum;
	}
	else
	{
		curSum += curnum;
	}
	cout << curSum;
	return 0;
}