/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *head = root;
        Node *firstChild = nullptr;
        Node *cur = nullptr;
        
        while (head) {
            if (head->left) {
                if (cur) {
                    cur->next = head->left;
                    cur = cur->next;
                } else {
                    firstChild = cur = head->left;
                }
            }
            if (head->right) {
                if (cur) {
                    cur->next = head->right;
                    cur = cur->next;
                } else {
                    firstChild = cur = head->right;
                }
            }
            
            if (!(head = head->next)) {
                head = firstChild;
                firstChild = cur = nullptr;
            }
        }
        
        return root;
    }
};
