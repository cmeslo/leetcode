/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
private:
    void dfs(Node* node, vector<int>& ans) {
        if (!node) return;
        ans.push_back(node->val);
        for (auto child : node->children)
            dfs(child, ans);
    }
};
