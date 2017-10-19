/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        TreeLinkNode *head = NULL, *prev = NULL, *cur = root;
        
        while (cur) {
            
            while (cur) {
                if (cur->left) {
                    if (prev == NULL) {
                        head = cur->left;
                    } else {
                        prev->next = cur->left;
                    }
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev == NULL) {
                        head = cur->right;
                    } else {
                        prev->next = cur->right;
                    }
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = NULL;
            prev = NULL;
        }
    }
};
