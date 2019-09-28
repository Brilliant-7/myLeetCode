class Solution {
public:
	// 滑动窗口法 [left, right)
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> hash;
        
		int len = 0;
		int left = 0, right = 0;
		while (left < s.size() && right < s.size())
		{
			if (hash.find(s[right]) == hash.end())
			{
				hash.insert(s[right]);
				right++;
			}
			else
			{
				hash.erase(s[left]);
				left++;
			}
			len = (len > hash.size()) ? len : hash.size();
		}
		return len;
	}
};