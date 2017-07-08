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

	bool isBalanced(TreeNode* root)
	{
		if (nullptr == root) return true;

		if (!isBalanced(root->left)) return false;
		if (!isBalanced(root->right)) return false;

		int leftMaxDepth = maxDepth(root->left);
		int rightMaxDepth = maxDepth(root->right);

		if (abs(leftMaxDepth - rightMaxDepth) > 1) {
			return false;
		}
		else {
			return true;
		}
	}

	int maxDepth(TreeNode* root)
	{
		if (nullptr == root) return 0;

		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);

		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}

	int abs(int x) {
		return x > 0 ? x : -x;
	}
};

void main()
{
	//TreeNode* t = nullptr;
	
	TreeNode* t = new TreeNode(1);

	/*t->left = new TreeNode(2);
	t->left->left = new TreeNode(3);
	t->left->right = new TreeNode(3);
	t->left->left->left = new TreeNode(4);
	t->left->left->right = new TreeNode(4);
	t->left->right->left = new TreeNode(4);
	t->left->right->right = new TreeNode(4);
	t->left->left->left->left = new TreeNode(5);
	t->left->left->left->right = new TreeNode(5);

	t->right = new TreeNode(2);
	t->right->right = new TreeNode(3);
	t->right->left = new TreeNode(3);
	t->right->left->left = new TreeNode(4);
	t->right->left->right = new TreeNode(4);*/
	
	t->left = new TreeNode(2);
	t->left->left = new TreeNode(3);
	t->left->left->left = new TreeNode(4);
	t->right = new TreeNode(2);
	t->right->right = new TreeNode(3);
	t->right->right->right = new TreeNode(4);

	auto ans = new Solution;

	cout << ans->isBalanced(t) << endl;
}