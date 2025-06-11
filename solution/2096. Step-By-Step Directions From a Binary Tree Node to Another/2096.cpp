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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path;
        string startPath = dfs(root, startValue, path);
        string destPath = dfs(root, destValue, path);
        // cout << startPath << endl << destPath << endl;
        
        // remove same prefix
        int i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) ++i;
        
        // if (i == startPath.size())
        //     return destPath;
        // if (i == destPath.size())
        //     return string(startPath.size() - i, 'U');
        
        string l = string(startPath.size() - i, 'U');
        string r = destPath.substr(i);

        return l + r;
    }
    
private:
    string dfs(TreeNode* node, int val, string& path) {
        if (!node) return "";
        if (node->val == val) return path;
        
        path.push_back('L');
        string l = dfs(node->left, val, path);
        path.pop_back();
        if (!l.empty()) return l;
        
        path.push_back('R');
        string r = dfs(node->right, val, path);
        path.pop_back();
        return r;
    }
};


// U U U ... R L

// U*n + path_to_dest

// L L L
// L R L
