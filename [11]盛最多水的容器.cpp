class Solution
{
public:
	// 暴力法
	int maxArea_1(vector<int> &height)
	{
		int maxCapcity = 0;
		int curCapcity = 0;
		int minHeight = 0;

		for (size_t i = 0; i < height.size(); i++)
		{
			for (size_t j = i + 1; j < height.size(); j++)
			{
				curCapcity = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
				if (curCapcity > maxCapcity)
					maxCapcity = curCapcity;
			}
		}
		return maxCapcity;
	}

	// 双指针
	int maxArea_2(vector<int> &height)
	{
		int maxCapcity = 0;
		int curCapcity = 0;
		int left = 0;
		int right = height.size() - 1;

		while (left < right)
		{
			curCapcity = (right - left) * (height[left] < height[right] ? height[left++] : height[right--]);
			if (curCapcity > maxCapcity)
				maxCapcity = curCapcity;
		}

		return maxCapcity;
	}
};