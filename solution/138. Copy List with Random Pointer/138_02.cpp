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
        if (!head) return head;
        
        // 1. insert copy nodes
        auto p = head;
        while (p) {
            Node* copy = new Node(p->val);
            copy->next = p->next;
            p->next = copy;
            p = copy->next;
        }
        
        // 2. copy random pointer
        p = head;
        while (p) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        
        // 3. split two links
        auto ans = head->next;
        p = head;
        while (p && p->next) {
            auto tmp = p->next;
            p->next = tmp->next;
            p = tmp;
        }
        
        return ans;
    }
};
