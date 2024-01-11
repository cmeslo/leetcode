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
    vector<TreeNode*> allPossibleFBT(int n) {
        // if (n % 2 == 0) return {};
        if (n == 1) return { new TreeNode(0) };
        
        vector<TreeNode*> res;
        for (int i = 1; i < n - 1; i += 2) {
            vector<TreeNode*> leftNodes = allPossibleFBT(i);
            vector<TreeNode*> rightNodes = allPossibleFBT(n - i - 1);
            for (auto& l : leftNodes) {
                for (auto& r : rightNodes) {
                    TreeNode* node = new TreeNode(0);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};


// 0 1 2 3 4 5 6
// x x x x x x x
//   ^   ^   ^

