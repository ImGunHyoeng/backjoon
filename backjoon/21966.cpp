//#include <iostream>
//#include <string>
//#include <algorithm>
//
//int main()
//{
//	using std::cin;
//	using std::cout;
//	using std::string;
//	std::ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int size;
//	string originstr;
//	string changestr;
//
//	cin >> size;
//	cin >> originstr;
//	if (size <= 25)
//	{
//		cout << originstr;
//		return 0 ;
//	}
//	string middlestr;
//	middlestr = originstr.substr(11, size - 22);
//
//
//	if (middlestr.at(size - 22 - 1) == 46)
//	{
//		changestr += originstr.substr(0, 11);
//		changestr += "...";
//		changestr += originstr.substr(size - 11, 11);
//		cout << changestr;
//		return 0;
//	}
//
//	for (int i = 0; i < size - 22; i++)
//	{
//		if (middlestr.at(i) != 46)
//			continue;
//		if (middlestr.at(i + 1))
//		{
//			changestr += originstr.substr(0, 9);
//			changestr += "......";
//			changestr += originstr.substr(size - 10, 10);
//			break;
//		}
//	}
//	
//	cout << changestr;
//	return 0;
//	
//
//
//}