/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findPath(root, target);
        vector<int> res;
        search(root, 0, k, res);
        return res;
    }
    
private:
    unordered_map<TreeNode*, int> dist;
    
    void findPath(TreeNode* root, TreeNode* target) {
        if (!root) return;
        
        if (root == target) {
            dist[root] = 0;
            return;
        }
        findPath(root->left, target);
        if (dist.count(root->left)) {
            dist[root] = dist[root->left] + 1;
            return;
        }
        findPath(root->right, target);
        if (dist.count(root->right)) {
            dist[root] = dist[root->right] + 1;
            return;
        }
    }
    
    void search(TreeNode* root, int d, const int& k, vector<int>& res) {
        if (!root) return;
        if (dist.count(root)) d = dist[root];
        if (d == k) {
            res.push_back(root->val);
        }
        search(root->left, d + 1, k, res);
        search(root->right, d + 1, k, res);
    }
};
