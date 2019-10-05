class Solution {
public:

	// 二维动态规划
	// dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;

		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));

		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = cols - 1; j >= 0; j--)
			{
				if (i != rows - 1 && j != cols - 1)
				{
					dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
				}
				else if (i == rows - 1 && j != cols - 1)  // 最后一行
				{
					dp[i][j] = grid[i][j] + dp[i][j + 1];
				}
				else if (i != rows - 1 && j == cols - 1)  // 最后一列
				{
					dp[i][j] = grid[i][j] + dp[i + 1][j];
				}
				else
				{
					dp[i][j] = grid[i][j];
				}
			}
		}

		return dp[0][0];
	}
};