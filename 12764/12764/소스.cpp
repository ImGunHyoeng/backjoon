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
	//초기화
	int st, et;
	for (int i = 0; i < N; i++)
	{
		cin >> st;
		cin >> et;
		user.push_back(User(st, et));
		userrecord[i] = 0;
	}

	sort(user.begin(), user.end(), comparest);//처음온 순서대로 넣기


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
			sittinguser.push_back(user.at(i));//순서대로 정렬한 유저를 넣어줌
			sittinguser.at(i).sitnum = i;//자리값을 세팅시켜준다. 0,1,2,3
			userrecord[i] +=1;
		}

		if (sittinguser.size() == N)//만약 너무 값이 커서 모든 사람을 다 앉힌 경우
			istrue = true;
		else {
			sort(sittinguser.begin(), sittinguser.end(), compareet);//끝나는 시간으로 소팅해준다.

			for (int i = mid; i <= N; i++)
			{
				if (i == N)//모든 사람을 앉혔다는 의미
				{
					istrue = true;
					break;
				}
				if (user.at(i).starttime < sittinguser.at(0).endtime)//자리에 앉을 수 없는 경우를 의미.
				{
					istrue = false;
					break;
				}
				
				userrecord[sittinguser.at(0).sitnum] += 1;//앉아있는 자리에 하나 값 추가
				
				user.at(i).sitnum = sittinguser.at(0).sitnum;//자리 등록해주기
				sittinguser.erase(sittinguser.begin());
				sittinguser.push_back(user.at(i));//해당하는 자리에 나가고 사람 추가됨.
				sort(sittinguser.begin(), sittinguser.end(), compareet);//들어올때마다 순서가 변경되기에 소팅해준다.
				
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