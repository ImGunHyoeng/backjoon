#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct User
{
	int starttime;
	int endtime;
	int sitnum;
	User(int st, int et)
	{
		starttime = st;
		endtime = et;
		sitnum =- 1;
	}
};
bool comparest(User a, User b)
{
	return a.starttime < b.starttime;
}
bool compareet(User a, User b)
{
	return a.endtime < b.endtime;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<User> user;
	
	int N;

	cin >> N;
	//User* user = new User[N];
	int* userrecord = new int[N];
	//�ʱ�ȭ
	int st, et;
	for (int i = 0; i < N; i++)
	{
		cin >> st;
		cin >> et;
		user.push_back(User(st, et));
		userrecord[i] = 0;
	}

	sort(user.begin(), user.end(), comparest);//ó���� ������� �ֱ�


	int left = 1;
	int right = N;
	int mid = (left + right) / 2;
	bool istrue = false;
	while (left <= right)
	{
		mid = (left + right) / 2;
		vector<User> sittinguser;
		for(int i=0;i<N;i++)
			userrecord[i] = 0;
		for (int i = 0; i < mid; i++)
		{
			sittinguser.push_back(user.at(i));//������� ������ ������ �־���
			sittinguser.at(i).sitnum = i;//�ڸ����� ���ý����ش�. 0,1,2,3
			userrecord[i] +=1;
		}

		if (sittinguser.size() == N)//���� �ʹ� ���� Ŀ�� ��� ����� �� ���� ���
			istrue = true;
		else {
			sort(sittinguser.begin(), sittinguser.end(), compareet);//������ �ð����� �������ش�.

			for (int i = mid; i <= N; i++)
			{
				if (i == N)//��� ����� �����ٴ� �ǹ�
				{
					istrue = true;
					break;
				}
				if (user.at(i).starttime < sittinguser.at(0).endtime)//�ڸ��� ���� �� ���� ��츦 �ǹ�.
				{
					istrue = false;
					break;
				}
				
				userrecord[sittinguser.at(0).sitnum] += 1;//�ɾ��ִ� �ڸ��� �ϳ� �� �߰�
				
				user.at(i).sitnum = sittinguser.at(0).sitnum;//�ڸ� ������ֱ�
				sittinguser.erase(sittinguser.begin());
				sittinguser.push_back(user.at(i));//�ش��ϴ� �ڸ��� ������ ��� �߰���.
				sort(sittinguser.begin(), sittinguser.end(), compareet);//���ö����� ������ ����Ǳ⿡ �������ش�.
				
			}
		}
		if (istrue)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left<<'\n';
	for (int i = 0; i < left; i++)
		cout << userrecord[i] << ' ';
	return 0;
}