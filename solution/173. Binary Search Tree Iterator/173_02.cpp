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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        int val;
        
        while (cur) {
            if (cur->left) {
                auto *tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;
                if (!tmp->right) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    val = cur->val;
                    tmp->right = nullptr;
                    cur = cur->right;
                    break;
                }
            } else {
                val = cur->val;
                cur = cur->right;
                break;
            }
        }
        
        return val;
    }
    
    bool hasNext() {
        return cur;
    }
    
private:
    TreeNode *cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
