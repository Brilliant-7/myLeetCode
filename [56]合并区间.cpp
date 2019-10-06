class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		// 排序
		sort(intervals.begin(), intervals.end());

		vector<vector<int>> merges;

		for (auto it : intervals)
		{
			if (merges.empty() || merges.back().back() < it.front())
			{
				merges.push_back(it);
			}
			else
			{
				merges.back().back() = (merges.back().back() > it.back()) ? merges.back().back() : it.back();
			}
		}

		return merges;
	}
};