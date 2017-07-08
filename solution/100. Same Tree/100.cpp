#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (nullptr == p && nullptr == q) return true;

		if (nullptr != p && nullptr != q && p->val == q->val)
		{
			if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
				return true;
			}
		}
		return false;
	}
};

void main()
{
//	TreeNode* t = nullptr;

	TreeNode* t = new TreeNode(1);

	t->left = new TreeNode(2);
	t->left->left = new TreeNode(4);
	t->left->left->left = new TreeNode(6);
	t->right = new TreeNode(3);
	t->right->right = new TreeNode(5);
	t->right->right->right = new TreeNode(7);

//	TreeNode* t2 = nullptr;
	TreeNode* t2 = new TreeNode(1);
	t2->left = new TreeNode(2);
	t2->left->left = new TreeNode(4);
	t2->left->left->left = new TreeNode(6);
	t2->right = new TreeNode(3);
	t2->right->right = new TreeNode(5);
	t2->right->right->right = new TreeNode(7);

// 	t->left = new TreeNode(9);
// 	t->right = new TreeNode(20);
// 	t->right->left = new TreeNode(15);
// 	t->right->right = new TreeNode(7);

	auto ans = new Solution;

	auto v = ans->isSameTree(t, t2);
	v ? cout << "is same" << endl : cout << "is not same" << endl;
}