# 653. Two Sum IV - Input is a BST

## Solution 1: DFS

```cpp
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (pre.count(k - root->val))
            return true;
        pre.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
    
private:
    unordered_set<int> pre;
};
```

## Solution 2: Inorder traversal + two pointers

```cpp
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        
        for (int i = 0, j = nums.size() - 1; i < j;) {
            if (nums[i] + nums[j] == k) return true;
            if (nums[i] + nums[j] < k)
                ++i;
            else
                --j;
        }
        return false;
    }
    
private:
    void inorder(TreeNode* node, vector<int>& nums) {
        if (!node) return;
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }
};
```

or

```cpp
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        
        for (int i = 0, j = nums.size() - 1; i < j;) {
            if (nums[i] + nums[j] == k) return true;
            if (nums[i] + nums[j] < k)
                ++i;
            else
                --j;
        }
        return false;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        
        auto cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            auto node = st.top(); st.pop();
            nums.push_back(node->val);
            if (node->right) cur = node->right;
        }
    }
};
```
