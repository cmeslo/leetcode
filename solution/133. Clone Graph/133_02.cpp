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
        
        unordered_map<int, Node*> copies;
        queue<Node*> todo;
        
        copies[node->val] = new Node(node->val);
        todo.push(node);
        
        while (!todo.empty()) {
            Node* cur = todo.front(); todo.pop();
            
            for (Node* next : cur->neighbors) {
                if (copies.find(next->val) == copies.end()) {
                    copies[next->val] = new Node(next->val);
                    todo.push(next);
                }
                copies[cur->val]->neighbors.push_back(copies[next->val]);
            }
        }
        
        return copies[node->val];
    }
};
