class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;

        int size = nums.size();
        backtrack(size, res, nums, 0);

        return res;
    }

    void backtrack(int size, vector<vector<int>> &res, vector<int> &nums, int first)
    {
        if (first == nums.size())
            res.push_back(nums);

        for (int i = first; i < nums.size(); i++)
        {
            swap(nums[first], nums[i]);
            backtrack(size, res, nums, first + 1);
            // 还原数组
            swap(nums[i], nums[first]);
        }
    }
};