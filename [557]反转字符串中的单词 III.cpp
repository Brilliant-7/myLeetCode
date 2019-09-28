class Solution {
public:
	string reverseWords(string s) {
		if (s.empty()) {
			return s;
		}
		string result;
		vector<string> vec;
		SegStringBySpace(s, vec);

		for (size_t i = 0; i < vec.size(); i++)
		{
			reverse(vec[i].begin(), vec[i].end());
			result += vec[i];
			if (i != vec.size() - 1) {
				result += ' ';
			}
		}
		return result;
	}
private:
	void SegStringBySpace(const string& str, vector<string>& vec) {
		if (str.empty()) {
			return;
		}

		string temp = str;
		int pos = temp.find(' ');

		while (pos != temp.npos) {
			vec.push_back(temp.substr(0, pos));
			temp = temp.substr(pos + 1, str.size());
			pos = temp.find(' ');
		}
		if (!temp.empty()) {
			vec.push_back(temp);
		}
	}
};
// answer is above！！！