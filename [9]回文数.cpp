class Solution {
public:
	bool isPalindrome(int x) {
		stringstream ss;
		string str1,str2;
		// 将int转化为string类型进行处理
		ss << x;
		ss >> str1;
		for (auto iter = str1.rbegin(); iter != str1.rend(); iter++)
		{
			str2.push_back(*iter);
		}
		for (size_t i = 0; i < str1.size(); i++)
		{
			if (str1[i] != str2[i]) {
				return false;
			}
		}
		return true;
	}
};