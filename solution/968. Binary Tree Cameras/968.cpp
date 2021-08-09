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
enum class State { NONE = 0, CAMERA = 1, COVERED = 2 };

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == State::NONE) ++res_;
        return res_;
    }
    
private:
    int res_ = 0;
    
    State dfs(TreeNode* root) {
        if (!root) return State::COVERED;
        
        State left = dfs(root->left);
        State right = dfs(root->right);
        
        if (left == State::NONE || right == State::NONE) {
            ++res_;
            return State::CAMERA;
        }
        
        if (left == State::COVERED && right == State::COVERED) return State::NONE;
        
        return State::COVERED; // 經過上面兩個 if 之後，left, right 中只少有一個 camera，而另一個是 camera 或者 covered
    }
};
