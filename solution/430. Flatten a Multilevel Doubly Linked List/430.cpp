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
    Node* flatten(Node* head) {
        Node *cur = head;
        
        while (cur) {
            if (cur->child) {
                Node* tmp = cur->next;

                cur->next = cur->child;
                cur->child->prev = cur;
                
                Node* tail = getTailNode(cur->child);
                if (tmp) {
                    tmp->prev = tail;
                    tail->next = tmp;
                }

                cur->child = nullptr;
            }
            cur = cur->next;
        }
        
        return head;
    }
    
private:
    Node* getTailNode(Node* node) {
        while (node && node->next) node = node->next;
        return node;
    }
};
