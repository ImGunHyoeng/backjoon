#include <iostream>

using namespace std;
struct SweetGold 
{
	int time;
	int money;
};
SweetGold walk[101];
SweetGold bike[101];
int DynamicProgram[101][2] = {0,};
int maxMoney = 0;
int n;
int dp(int count, int limit);
int main()
{
	int limit;
	cin >> n;
	cin >> limit;
	for (int i = 0; i < n; i++)
	{
		cin >> walk[i].time >> walk[i].money >> bike[i].time >> bike[i].money;
	}

	cout<<dp(0, limit);
	return 0;
}
int dp(int count, int limit)
{
	if (count == n)
		return 0;
	
	if (limit - walk[count].time >= 0)DynamicProgram[count][0] = max(DynamicProgram[count][0], dp(count + 1, limit - walk[count].time) + walk[count].money);
	if (limit - bike[count].time >= 0)DynamicProgram[count][1] = max(DynamicProgram[count][1], dp(count + 1, limit - bike[count].time) + bike[count].money);
	return max(DynamicProgram[count][0], DynamicProgram[count][1]);
}