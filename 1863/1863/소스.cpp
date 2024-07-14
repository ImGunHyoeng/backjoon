#include <iostream>
#include <stack>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int> st;
	int n;
	int count = 0;
	cin >> n;

	int x, y;

	st.push(0);//stack과 비교하기 위함
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		while (!st.empty()&&y<st.top())
		{
			st.pop();
			count++;
		}
		if(st.top()!=y)
			st.push(y);
		
	}

	while (!st.empty() && 0 < st.top())
	{
		st.pop();
		count++;
	}
	cout << count;

	return 0;
}