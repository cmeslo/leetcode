/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (copies.find(node->val) != copies.end()) return copies[node->val];
        
        Node* new_node = new Node(node->val);
        copies[node->val] = new_node;
        
        for (Node* n : node->neighbors)
            new_node->neighbors.push_back(cloneGraph(n));
        
        return new_node;
    }
    
private:
    unordered_map<int, Node*> copies;
};
