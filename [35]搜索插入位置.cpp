#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 二分查找
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return 0;
        }
        int low = 0, high = nums.size() - 1;
        int mid = 0;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (target < nums[mid])
            {
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else if (target == nums[mid])
            {
                return mid;
            }
        }
        return (target > nums[low]) ? low + 1 : low;
    }
};
int main()
{
    Solution t;
    vector<int> vec = {1, 3, 5, 6};
    cout << t.searchInsert(vec, 7) << endl;

    system("pause");
    return 0;
}