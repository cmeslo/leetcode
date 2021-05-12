# 637. Average of Levels in Binary Tree

```cpp
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            auto cur = q.front(); q.pop();
            sum += cur->val;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        ans.push_back(sum / size);
    }

    return ans;
}
```
