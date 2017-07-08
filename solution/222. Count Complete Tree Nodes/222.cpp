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
	int countNodes(TreeNode* root)
	{
		if (nullptr == root) return 0;

		int h = getHeight(root);

		if (h-1 == getHeight(root->right)) {
			return (1 << h) + countNodes(root->right);
		}
		else {
			return (1 << (h - 1)) + countNodes(root->left);
		}
	}

	int getHeight(TreeNode* root)
	{
		if (nullptr == root) return -1;

		int height = 0;
		while (root->left) {
			height += 1;
			root = root->left;
		}
		return height;
	}
};

void main()
{
//	TreeNode* t = nullptr;

	TreeNode* t = new TreeNode(1);

	t->left = new TreeNode(2);
	t->right = new TreeNode(3);
	t->left->left = new TreeNode(4);
	t->left->right = new TreeNode(5);

	auto ans = new Solution;

	cout << ans->countNodes(t) << endl;
}