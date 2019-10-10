class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		vector<string> strOfRow(numRows, string());
		int index = 2 * (numRows - 1);
		int pos = 0;

		for (int i = 0; i < s.size(); i++) {
			pos = i % index;
			if (pos < numRows)
				strOfRow[pos].push_back(s[i]);
			else
				strOfRow[index - pos].push_back(s[i]);
		}

		string zStr;
		for (auto it : strOfRow)
			zStr += it;

		return zStr;
	}
};