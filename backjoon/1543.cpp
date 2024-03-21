//#include <iostream>
//#include <string>
//
//using namespace std;
//int main()
//{
//
//	int researchWordCount=0;
//	string input;
//	string researchword;
//	getline(cin, input);
//	getline(cin, researchword);
//	
//	int wordSize =(int)researchword.length();
//	int wordCount = 0;
//
//	if (input.length() < researchword.length())
//	{
//		cout << 0;
//	}
//	else {
//		for (int i = 0;i<=input.length()-1; i++)
//		{
//			if (researchword[wordCount] != input[i])
//			{
//				i -= wordCount;
//				wordCount = 0;
//				continue;
//			}
//			//같은 문자일 경우만 남음
//			wordCount++;
//
//			if (wordCount == wordSize)
//			{
//				researchWordCount++;
//				wordCount = 0;
//			}
//
//		}
//		cout << researchWordCount;
//	}
//	
//	return 0;
//}