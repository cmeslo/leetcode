# 606. Construct String from Binary Tree

```cpp
class Solution {
public:
    string tree2str(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }
    
private:
    void dfs(TreeNode* node, string& res) {
        if (!node) return;
        
        res += to_string(node->val);
        if (!node->left && !node->right) return;
        
        // 為了保留子樹的左右關係，左子樹一定要keep，即使是 null
        res.push_back('(');
        dfs(node->left, res);
        res.push_back(')');

        if (!node->right) return;
        res.push_back('(');
        dfs(node->right, res);
        res.push_back(')');
    }
};
```
