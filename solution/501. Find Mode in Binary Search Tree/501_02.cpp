/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        mode_cnt = max_cnt;
        cnt = 0;
        inorder(root);
        return res;
    }

private:
    int val = 0;
    int cnt = 0, max_cnt = 0, mode_cnt = 0;
    vector<int> res;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        visit(root);
        inorder(root->right);
    }

    void visit(TreeNode* node) {
        if (val == node->val) {
            ++cnt;
        } else {
            val = node->val;
            cnt = 1;
        }

        if (cnt > max_cnt) {
            max_cnt = cnt;
        }
        if (cnt == mode_cnt) {
            res.push_back(val);
        }
    }
};
