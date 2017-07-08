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

	vector<vector<int>> levelOrderBottom(TreeNode* root) {

		vector<vector<int>> ans;

		if (nullptr == root) return ans;

		queue<TreeNode*> temp;
		temp.push(root);
		int currentLevelNodeCount = 1;

		while (!temp.empty())
		{
			vector<TreeNode*> temp2;
			vector<int> v;
			int nextLevelNodeCount = 0;
			for (int i = 0; i < currentLevelNodeCount; ++i)
			{
				TreeNode* current = temp.front();
				temp.pop();

				v.push_back(current->val);

				if (nullptr != current->left) {
					temp2.push_back(current->left);
					nextLevelNodeCount += 1;
				}
				if (nullptr != current->right) {
					temp2.push_back(current->right);
					nextLevelNodeCount += 1;
				}
			}
			for (auto i = temp2.begin(); i != temp2.end(); ++i) {
				temp.push(*i);
			}

			currentLevelNodeCount = nextLevelNodeCount;
			ans.push_back(v);
		}

		std::reverse(ans.begin(), ans.end());

		return ans;
	}
};

void main()
{
	//TreeNode* t = nullptr;

	TreeNode* t = new TreeNode(1);

// 	t->left = new TreeNode(2);
// 	t->left->left = new TreeNode(4);
// 	//t->left->left->left = new TreeNode(5);
// 	t->right = new TreeNode(3);
// 	t->right->right = new TreeNode(5);
// 	//t->right->right->right = new TreeNode(4);

	t->left = new TreeNode(9);
	t->right = new TreeNode(20);
	t->right->left = new TreeNode(15);
	t->right->right = new TreeNode(7);

	auto ans = new Solution;

	auto v = ans->levelOrderBottom(t);
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		auto vInt = *i;
		for (auto j = vInt.begin(); j != vInt.end(); ++j){
			cout << *j << ", ";
		}
		cout << endl;
	}
}