struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty()) {
			return NULL;
		}
		TreeNode* root = new TreeNode(postorder.back());

		int pos = 0;
		while (root->val != inorder[pos]) {
			pos++;
		}

		vector<int> post_left;
		vector<int> post_right;
		for (size_t i = 0; i < postorder.size() - 1; i++)
		{
			if (i < pos) {
				post_left.push_back(postorder[i]);
			}
			else {
				post_right.push_back(postorder[i]);
			}
		}

		vector<int> vin_letf;
		vector<int> vin_right;
		for (size_t i = 0; i < inorder.size(); i++)
		{
			if (i < pos) {
				vin_letf.push_back(inorder[i]);
			}
			else if (i > pos) {
				vin_right.push_back(inorder[i]);
			}
		}

		int leftLength = vin_letf.size();
		int rightLength = vin_right.size();

		if (leftLength > 0) {
			//构建左子树
			root->left = buildTree(vin_letf, post_left);
		}
		if (rightLength > 0) {
			//构建右子树
			root->right = buildTree(vin_right, post_right);
		}
		return root;
	}
};
// answer is above！！！