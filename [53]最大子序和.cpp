class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int thisSum = 0, maxSum = nums[0];
        for (size_t i = 0; i < nums.size(); i++)
        {
            thisSum += nums[i];
            if (thisSum > maxSum)
            {
                maxSum = thisSum;
            }
            else if (thisSum < 0)
            {
                thisSum = 0;
            }
        }
        return maxSum;
    }
};