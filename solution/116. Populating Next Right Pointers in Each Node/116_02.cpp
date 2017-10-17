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
        queue<TreeLinkNode*> q;
        if (root != NULL) q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeLinkNode* cur = q.front(); q.pop();

                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
                if (i < size - 1) cur->next = q.front();
            }
        }
    }
};
