class Solution
{
public:
    // 快慢指针遍历数组
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        int i = 0;
        for (size_t j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};