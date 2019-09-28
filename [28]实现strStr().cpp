#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	// BF算法（暴力解法）
	int strStr1(string haystack, string needle) {
		int haystackSize = haystack.size();
		int needleSize = needle.size();

		if (needleSize == 0) {
			return 0;
		}
		if (haystackSize < needleSize) {
			return -1;
		}

		int haystackPtr = 0;
		int needlePtr = 0;
		while (haystackPtr < haystackSize && needlePtr < needleSize) {
			if (haystack[haystackPtr] == needle[needlePtr]) {
				//匹配成功
				haystackPtr++;
				needlePtr++;
			}
			else {
				//匹配失败
				haystackPtr = haystackPtr - needlePtr + 1;
				needlePtr = 0;
			}
		}
		if (needlePtr == needleSize) {
			return haystackPtr - needlePtr;
		}
		else {
			return -1;
		}
	}
	//KMP
	int strStr2(string haystack, string needle) {
		int haystackSize = haystack.size();
		int needleSize = needle.size();
		vector<int> next = GetNext(needle);

		int haystackPtr = 0;
		int needlePtr = 0;
		while (haystackPtr < haystackSize && needlePtr < needleSize) {
			if (haystack[haystackPtr] == needle[needlePtr]) {
				//匹配成功
				haystackPtr++;
				needlePtr++;
			}
			else {
				//匹配失败
				if (needlePtr > 0) {
					needlePtr = next[needlePtr - 1];
				}
				else {
					haystackPtr++;
				}
			}
		}

		if (needlePtr == needleSize) {
			return haystackPtr - needlePtr;
		}
		else {
			return -1;
		}
	}
private:
	vector<int> GetNext(const string& pattern) {
		int size = pattern.size();
		vector<int> next(size, 0);
		int index = 0;
		for (int i = 1; i < size;)
		{
			if (pattern[i] == pattern[index]) {
				next[i] = index + 1;
				index++;
				i++;
			}
			else {
				if (index > 0) {
					index = next[index - 1];
				}
				else {
					next[i] = 0;
					i++;
				}
			}
		}
		return next;
	}
};
// answer is above！！！


int main() {
	Solution t;
	string haystack = "abcxabcdabcdabcy", needle = "abcdabcy";
	t.strStr2(haystack, needle);

	system("pause");

	return 0;
}