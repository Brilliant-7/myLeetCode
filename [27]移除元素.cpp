class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		// 双指针
		int i = 0;
		for (size_t j = 0; j < nums.size(); j++)
		{
			if (nums[j] != val) {
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};