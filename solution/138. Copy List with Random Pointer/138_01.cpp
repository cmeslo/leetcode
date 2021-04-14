/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;
        
        Node* cur = head;
        while (cur) {
            copies[cur] = new Node(cur->val);
            cur = cur->next;
        }
        
        cur = head;
        while (cur) {
            copies[cur]->next = copies[cur->next];
            copies[cur]->random = copies[cur->random];
            cur = cur->next;
        }
        
        return copies[head];
    }
};
