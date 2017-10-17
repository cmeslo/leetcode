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
        int level = 1;
        queue<TreeLinkNode*> q;
        if (root != NULL) q.push(root);
        
        while (!q.empty()) {
            for (int i = 0; i < level; ++i) {
                if (q.empty()) break;
                TreeLinkNode* cur = q.front();
                q.pop();

                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
                cur->next = (!q.empty() && i != level - 1) ? q.front() : NULL;
            }
            level <<= 1;
        }
    }
};
