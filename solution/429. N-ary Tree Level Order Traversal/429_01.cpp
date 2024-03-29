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
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            vector<int> cur;
            for (int size = q.size(); size > 0; --size) {
                auto node = q.front(); q.pop();
                cur.push_back(node->val);
                for (auto child : node->children)
                    q.push(child);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
