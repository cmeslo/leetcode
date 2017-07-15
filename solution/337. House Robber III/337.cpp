#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	unordered_map<TreeNode*, int> robMap, passMap;

	int rob(TreeNode* root) {
		robMap.clear(), passMap.clear();

		return max(robRoot(root), passRoot(root));
	}

	int robRoot(TreeNode* root)
	{
		if (!root) return 0;
		if (robMap.count(root)) return robMap[root];

		robMap[root] = root->val + passRoot(root->left) + passRoot(root->right);

		return robMap[root];
	}

	int passRoot(TreeNode* root)
	{
		if (!root) return 0;
		if (passMap.count(root)) return passMap[root];

		passMap[root] =
			max(robRoot(root->left), passRoot(root->left)) +
			max(robRoot(root->right), passRoot(root->right));

		return passMap[root];
	}
};

void main()
{
	auto ans = new Solution;

// 	TreeNode *test = new TreeNode(3);
// 	test->left = new TreeNode(2);
// 	test->left->right = new TreeNode(3);
// 	test->right = new TreeNode(3);
// 	test->right->right = new TreeNode(1);

// 	TreeNode *test = new TreeNode(3);
// 	test->left = new TreeNode(4);
// 	test->right = new TreeNode(5);
// 	test->left->left = new TreeNode(1);
// 	test->left->right = new TreeNode(3);
// 	test->right->right = new TreeNode(1);

	TreeNode *test = new TreeNode(4);
	test->left = new TreeNode(1);
	test->left->left = new TreeNode(2);
	test->left->left->left = new TreeNode(3);

	cout << ans->rob(test) << endl;
}