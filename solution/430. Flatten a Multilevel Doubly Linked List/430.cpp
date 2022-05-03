/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* tail;
    
    Node* flatten(Node* head) {
        auto p = head;
        while (p) {
            if (p->child) {
                auto next = flatten(p->child);
                next->prev = p;
                tail->next = p->next;
                if (p->next) p->next->prev = tail;
                p->next = p->child;
                p->child = nullptr;
            }
            tail = p;
            p = p->next;
        }
        return head;
    }
};
