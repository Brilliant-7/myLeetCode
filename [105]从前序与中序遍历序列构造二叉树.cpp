/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& vin) {
        		if (pre.empty() || vin.empty()) {
			return NULL;
		}
		TreeNode* root = new TreeNode(pre[0]);

		int pos = 0;
		while (root->val != vin[pos]) {
			pos++;
		}

		vector<int> pre_left;
		vector<int> pre_right;
		for (size_t i = 1; i < pre.size(); i++)
		{
			if (i <= pos) {
				pre_left.push_back(pre[i]);
			}
			else {
				pre_right.push_back(pre[i]);
			}
		}

		vector<int> vin_letf;
		vector<int> vin_right;
		for (size_t i = 0; i < vin.size(); i++)
		{
			if (i < pos) {
				vin_letf.push_back(vin[i]);
			}
			else if (i > pos) {
				vin_right.push_back(vin[i]);
			}
		}

		int leftLength = vin_letf.size();
		int rightLength = vin_right.size();

		if (leftLength > 0) {
			//构建左子树
			root->left = buildTree(pre_left, vin_letf);
		}
		if (rightLength > 0) {
			//构建右子树
			root->right = buildTree(pre_right, vin_right);
		}
		return root;
	}
};