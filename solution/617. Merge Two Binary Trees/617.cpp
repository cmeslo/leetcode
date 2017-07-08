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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

		if (t1 == nullptr && t2 != nullptr) {
			return t2;
		}
		if (t1 != nullptr && t2 == nullptr) {
			return t1;
		}
		if (t1 == nullptr && t2 == nullptr) {
			return nullptr;
		}

		t1->val = t1->val + t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};

void main()
{
	auto t1 = new TreeNode(1);
	t1->left = new TreeNode(2);
	t1->left->left = new TreeNode(3);

	auto t2 = new TreeNode(1);
	t2->right = new TreeNode(2);
	t2->right->right = new TreeNode(3);

	auto ans = new Solution;
	auto t3 = ans->mergeTrees(t1, t2);
	cout << "done" << endl;
}