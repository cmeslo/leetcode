# 1305. All Elements in Two Binary Search Trees

## 1305_01.cpp

dfs and sort

```cpp
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        dfs(root1, list1);
        dfs(root2, list2);
        list1.insert(list1.end(), list2.begin(), list2.end());
        sort(list1.begin(), list1.end());
        return list1;
    }
    
private:
    void dfs(TreeNode* node, vector<int>& list) {
        if (!node) return;
        
        list.push_back(node->val);
        dfs(node->left, list);
        dfs(node->right, list);
    }
};
```

## 1305_02.cpp

dfs and merge

```cpp
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        dfs(root1, list1);
        dfs(root2, list2);
        
        vector<int> ans;
        int i1 = 0, i2 = 0;
        while (i1 < list1.size() && i2 < list2.size())
            ans.push_back(list1[i1] < list2[i2] ? list1[i1++] : list2[i2++]);
            
        if (i1 == list1.size())
            while (i2 < list2.size())
                ans.push_back(list2[i2++]);
        
        if (i2 == list2.size())
            while (i1 < list1.size())
                ans.push_back(list1[i1++]);
                
        return ans;
    }
    
private:
    void dfs(TreeNode* node, vector<int>& list) {
        if (!node) return;
        
        dfs(node->left, list);
        list.push_back(node->val);
        dfs(node->right, list);
    }
};
```
