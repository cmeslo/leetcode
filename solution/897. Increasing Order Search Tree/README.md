# 897. Increasing Order Search Tree

## 解釋：

最初的想法是，先拼接左子樹和右子樹，然後再按照 <strong>新左子樹->root->新右子樹</strong> 這樣拼接起來。

```cpp
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        
        auto* left = increasingBST(root->left);
        auto* right = increasingBST(root->right);
        
        root->left = nullptr;
        root->right = nullptr;
        
        if (left) {
            auto* tmp = left;
            while (tmp->right)
                tmp = tmp->right;
            tmp->right = root;
        } else {
            left = root;
        }

        root->right = right;
        
        return left;
    }
};
```

但其實上面的解法有個缺點，因為我不知道 <strong>新左子樹</strong> 的尾，所以要用一個while循環找出來。

解決方法是、再用一個額外的pointer指向現在處理到的尾巴 (tail)，這樣代碼也會變得清晰：

```cpp
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        cur_ = &dummy;
        inorder(root);
        return dummy.right;
    }
    
private:
    TreeNode* cur_;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        
        root->left = nullptr;
        cur_->right = root;
        cur_ = root;
        
        inorder(root->right);
    }
};
```
Time: O(N)
