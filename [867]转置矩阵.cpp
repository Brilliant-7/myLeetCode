class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {

		vector<vector<int>> res;
		vector<int> temp;

		int rows = A.size();
		int cols = A[0].size();

		for (size_t i = 0; i < cols; i++)
		{
			for (size_t j = 0; j < rows; j++)
			{
				temp.push_back(A[j][i]);
			}
			res.push_back(temp);
			temp.clear();
		}

		return res;
	}
};
