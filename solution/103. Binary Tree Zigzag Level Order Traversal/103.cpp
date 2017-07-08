#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		vector<vector<int>> ans;

		if (nullptr == root) return ans;

		queue<TreeNode*> q;

		q.push(root);

		int currentLevelCount = 1;
		int nextLevelCount = 0;
		int leftToRight = 1;

		while (!q.empty())
		{
			vector<int> currentLevel;

			nextLevelCount = 0;
			for (int i = 0; i < currentLevelCount; ++i)
			{
				TreeNode* current;

				current = q.front();
				q.pop();

				currentLevel.push_back(current->val);

				if (nullptr != current->left) {
					q.push(current->left);
					nextLevelCount += 1;
				}
				if(nullptr != current->right) {
					q.push(current->right);
					nextLevelCount += 1;
				}
			}
			if (leftToRight == 0) std::reverse(currentLevel.begin(), currentLevel.end());

			leftToRight == 1 ? leftToRight = 0 : leftToRight = 1;

			currentLevelCount = nextLevelCount;
			ans.push_back(currentLevel);
		}
		return ans;
	}

};

void main()
{
	//TreeNode* t = nullptr;

	TreeNode* t = new TreeNode(1);

	t->left = new TreeNode(2);
	t->left->left = new TreeNode(4);
	t->left->left->left = new TreeNode(6);
	t->right = new TreeNode(3);
	t->right->right = new TreeNode(5);
	t->right->right->right = new TreeNode(7);

// 	t->left = new TreeNode(9);
// 	t->right = new TreeNode(20);
// 	t->right->left = new TreeNode(15);
// 	t->right->right = new TreeNode(7);

	auto ans = new Solution;

	auto v = ans->zigzagLevelOrder(t);
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		auto vInt = *i;
		for (auto j = vInt.begin(); j != vInt.end(); ++j){
			cout << *j << ", ";
		}
		cout << endl;
	}
}