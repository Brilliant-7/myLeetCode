class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minPrice = INT_MAX;
		int maxProfit = 0;
		int curProfit = 0;
		for (size_t i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minPrice)
			{
				minPrice = prices[i];
			}
			else
			{
				curProfit = prices[i] - minPrice;
				if (curProfit > maxProfit)
				{
					maxProfit = curProfit;
				}
			}
		}
		return maxProfit;
	}
};