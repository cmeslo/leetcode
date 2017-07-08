#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		if (nullptr == root) return ans;

		stack<TreeNode*> st;

		st.push(root);

		while (!st.empty())
		{
			TreeNode* current = st.top();
			st.pop();

			ans.push_back(current->val);

			if (nullptr != current->left) st.push(current->left);
			if (nullptr != current->right) st.push(current->right);
		}
		std::reverse(ans.begin(), ans.end());

		return ans;
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
	t->right->left = new TreeNode(6);
	t->right->right = new TreeNode(7);

	auto ans = new Solution;
	vector<int> v = ans->postorderTraversal(t);
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i){
		cout << *i << ", ";
	}
	cout << endl;
}