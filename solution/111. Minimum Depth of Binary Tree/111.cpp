#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root)
	{
		if (nullptr == root) return 0;

		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);

		if (leftDepth == 0) {
			return rightDepth + 1;
		}

		if (rightDepth == 0) {
			return leftDepth + 1;
		}

		return leftDepth > rightDepth ? rightDepth + 1 : leftDepth + 1;
	}
};

void main()
{
	//TreeNode* t = nullptr;
	TreeNode* t = new TreeNode(1);
	t->left = new TreeNode(2);
	//t->left->left = new TreeNode(1);

	//t->left = new TreeNode(2);
	//t->left->left = new TreeNode(1);
	t->right = new TreeNode(2);
	t->right->right = new TreeNode(1);

	auto ans = new Solution;

	cout << ans->minDepth(t) << endl;
}