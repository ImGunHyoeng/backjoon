#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isCan = true;
class trieNode
{

public:
	bool isEnd;
	trieNode *chirdren[10];
	trieNode() :isEnd(false), chirdren()
	{
		
	}
	~trieNode()
	{
		
	}

	void insert(string str, int depth)
	{
		if (depth == str.length())
		{
			isEnd = true;
			return;
		}

		if ( nullptr == chirdren[str[depth] - '0'] )
		{
			chirdren[str[depth] - '0'] = new trieNode();
		}

		chirdren[str[depth] - '0']->insert(str, depth + 1);
	}

	void find(string str, int depth)
	{
		if (depth == str.length() && isEnd)
			return;
		if (depth != str.length() && isEnd)
		{
			isCan= false;
			return;
		}

		if(nullptr!=chirdren[str[depth]-'0'])
			chirdren[str[depth] - '0']->find(str, depth + 1);
	}
};
int main()
{
	
	vector<string> vec;
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		trieNode root;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string temp;
			cin >> temp;
			vec.push_back(temp);
			root.insert(temp, 0);
		}
		for (int i = 0; i < n; i++)
		{
			root.find(vec[i], 0);
		}
		if(isCan)
			cout<<"YES"<<"\n";
		else
			cout << "NO" << "\n";
		isCan = true;
		vec.clear();
	}

	return 0;
}