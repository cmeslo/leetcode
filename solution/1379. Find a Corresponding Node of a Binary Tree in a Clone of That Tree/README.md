# 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

## DFS (1379_01.cpp)

```cpp
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (!original || original == target) return cloned;

    auto* left = getTargetCopy(original->left, cloned->left, target);
    if (left) return left;
    return getTargetCopy(original->right, cloned->right, target);
}
```

## BFS (1379_02.cpp)

```cpp
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    queue<TreeNode*> q1, q2;
    q1.push(original);
    q2.push(cloned);

    while (!q1.empty()) {
        auto* p1 = q1.front(); q1.pop();
        auto* p2 = q2.front(); q2.pop();
        if (p1 == target) return p2;
        if (p1->left) {
            q1.push(p1->left);
            q2.push(p2->left);
        }
        if (p1->right) {
            q1.push(p1->right);
            q2.push(p2->right);
        }
    }

    return nullptr;
}
```
