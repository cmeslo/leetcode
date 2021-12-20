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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        preorder(root, 0, ans);
        return ans;
    }
    
private:
    void preorder(Node* root, int depth, vector<vector<int>>& ans) {
        if (!root) return;
        while (ans.size() <= depth) ans.push_back({});
        ans[depth].push_back(root->val);
        for (auto* child : root->children)
            preorder(child, depth+1, ans);
    }
};
