# 450. Delete Node in a BST

重點是分情況討論

## 450_01.cpp

找到節點後純粹替換節點裡的值，代碼較短

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val == key) {
        if (root->left && root->right) {
            auto* min = root->right;
            while (min->left) min = min->left;
            root->val = min->val;
            root->right = deleteNode(root->right, min->val);
        } else {
            auto* new_root = root->left ? root->left : root->right;
            root->left = root->right = nullptr;
            delete root;
            return new_root;
        }
    }
    return root;
}
```

## 450_02.cpp

真正的交換兩個節點，代碼較長

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val == key) {
        TreeNode* new_root;
        if (!root->left)
            new_root = root->right;
        if (!root->right)
            new_root = root->left;
        else {
            TreeNode* parent = root;
            new_root = root->right;
            while (new_root->left) {
                parent = new_root;
                new_root = new_root->left;
            }
            if (parent != root) {
                parent->left = new_root->right;
                new_root->right = root->right;
            }
            new_root->left = root->left;
        }
        delete root;
        return new_root;
    }

    return root;
}
```
