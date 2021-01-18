# 173. Binary Search Tree Iterator

## 解釋：

重點是中序遍歷的非recursive實現方法。

```cpp
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto *cur = st.top(); st.pop();
        int val = cur->val;
        
        if (cur->right) {
            auto *tmp = cur->right;
            while (tmp) {
                st.push(tmp);
                tmp = tmp->left;
            }
        }
        
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
private:
    stack<TreeNode*> st;
};
```
