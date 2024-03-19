//#include <iostream>
//#include <string>
//#include <algorithm>
//
//int main()
//{
//	using std::string;
//	using std::cin;
//	using std::cout;
//
//	int size;
//	string originstr;
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
//		cout << originstr.substr(0, 11) << "..." << originstr.substr(size-11, 11);
//		return 0;
//	}
//
//	for (int i = 0; i < size - 22; i++)
//	{
//		if (middlestr.at(i) != 46)
//			continue;
//		if (middlestr.at(i + 1))
//		{
//			cout << originstr.substr(0, 9) << "......" << originstr.substr(size-10, 10);
//			return 0;
//		}
//	}
//	
//	cout << originstr.substr(0, 11) << "..." << originstr.substr(size-11, 11);
//	return 0;
//	
//
//
//}