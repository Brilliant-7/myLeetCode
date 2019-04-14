#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string pattern;

		if (strs.empty()) {
			return pattern;
		}
		else if (strs.size() == 1) {
			return strs[0];
		}

		// 最小字符串长度
		int min_size = strs[0].size();
		for (size_t i = 0; i < strs.size(); i++)
		{
			if (strs[i].size() < min_size) {
				min_size = strs[i].size();
			}
		}
		// 找出前两个字符串的公共字符串
		for (size_t i = 0; i < min_size; i++)
		{
			if (strs[0].at(i) == strs[1].at(i)) {
				pattern.push_back(strs[0].at(i));
			}
			else
				break;
		}

		// 将得到的公共字符串于之后的元素逐个比较
		// noPos记录的是不匹配点的位置，删除[noPos,pattern.size())的公共字符串
		int noPos = 0;
		for (size_t i = 2; i < strs.size(); i++)
		{
			for (size_t j = 0; j < pattern.size(); j++)
			{
				if (strs[i].at(j) != pattern.at(j)) {
					noPos = j;
					pattern.erase(noPos, pattern.size());
					noPos = 0;
					break;
				}
			}
		}

		return pattern;
	}
};
// 以上为解答

void SegStringByComma(const string &str, vector<string> &vec) {
	// 以逗号作为分隔符，分割字符串
	if (str.empty()) {
		return;
	}

	string temp = str;
	int pos = temp.find(',');

	while (pos != temp.npos) {
		vec.push_back(temp.substr(0, pos));
		temp = temp.substr(pos + 1, str.size());
		pos = temp.find(',');
	}
	if (!temp.empty()) {
		vec.push_back(temp);
	}
}

int main() {
	Solution t;
	string input;
	vector<string> vec = { "ac","ac","a","a" };

	//cin >> input;
	//SegStringByComma(input, vec);
	t.longestCommonPrefix(vec);

	system("pause");
	return 0;
}