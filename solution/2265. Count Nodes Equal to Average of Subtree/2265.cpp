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
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return res;
    }

private:
    int res = 0;

    pair<int, int> postOrder(TreeNode* node) {
        if (!node) return {0, 0};
        auto [l_sum, l_cnt] = postOrder(node->left);
        auto [r_sum, r_cnt] = postOrder(node->right);
        int sum = l_sum + r_sum + node->val;
        int cnt = l_cnt + r_cnt + 1;
        if (sum / cnt == node->val)
            ++res;
        return {sum, cnt};
    }
};
