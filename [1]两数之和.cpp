// 暴力求解
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int cnt1 = 0;
		int temp;
		vector<int> result;

		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			int cnt2 = cnt1 + 1;
			for (auto iter2 = iter + 1; iter2 != nums.end(); iter2++)
			{
				temp = *iter + *iter2;
				if (temp == target) {
					result.push_back(cnt1);
					result.push_back(cnt2);
					return result;
				}
				cnt2++;
			}
			cnt1++;
		}
		return result;
	}
};


// hash表
class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int> hash;

		for (int i = 0; i < nums.size(); i++) {
			auto iter = hash.find(target - nums[i]);

			if (iter != hash.end()) {
				return vector<int>{ iter->second, i };
			};
			hash[nums[i]] = i;
		}
		return vector<int>();
	}
};