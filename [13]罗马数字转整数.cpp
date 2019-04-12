class Solution {
public:
	int romanToInt(string s) {
		int result = 0;
		
		// 遍历每一个字符，若该字符小于右边则减，若该字符大于右边则加
		for (size_t i = 0; i < s.size(); i++)
		{
			if (roman[s[i]] < roman[s[i + 1]]) {
				result = result - roman[s[i]];
			}
			else {
				result = result + roman[s[i]];
			}
		}
		return result;
	}
protected:
	unordered_map<char, int>roman = {
	{ 'I',1 },
	{ 'V',5 },
	{ 'X',10 },
	{ 'L',50 },
	{ 'C',100 },
	{ 'D',500 },
	{ 'M',1000 } };
};