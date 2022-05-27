# 450. Delete Node in a BST

重點是分情況討論。

## Solution 1: 450_01.cpp

找到要刪除的 ```節點A``` 後，用 ```節點B``` 的 值 ```b``` 替換 ```節點A``` 裡的值 ```key```，再遞歸刪掉剛替換的 ```節點B```，代碼較短。

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else if (root->val == key) {
        if (root->left && root->right) {
            auto mn = root->right;
            while (mn->left)
                mn = mn->left;
            root->val = mn->val;
            root->right = deleteNode(root->right, mn->val);
        } else {
            auto new_root = root->left ? root->left : root->right;
            delete root;
            return new_root;
        }
    }

    return root;
}
```

## Solution 2: 450_02.cpp

真正的交換兩個節點，代碼較長。

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    else {
        TreeNode* new_root = nullptr;
        if (!root->left)
            new_root = root->right;
        else if (!root->right)
            new_root = root->left;
        else {
            TreeNode* pre = nullptr;
            new_root = root->right;
            while (new_root->left) {
                pre = new_root;
                new_root = new_root->left;
            }
            if (pre) {
                pre->left = new_root->right;
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
