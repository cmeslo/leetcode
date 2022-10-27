# 173. Binary Search Tree Iterator

## 解釋：

重點是中序遍歷的非 recursive 實現方法。

### 方法一 (stack)：

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
        TreeNode* ret = st.top(); st.pop();
        if (ret->right) {
            auto p = ret->right;
            while (p) {
                st.push(p);
                p = p->left;
            }
        }
        return ret->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
private:
    stack<TreeNode*> st;
};
```

### 方法二 (Morris Traversal)：

Morris Traversal 的重點是：
```
1. cur 永遠指向袓先
2. 要多走一輪才會知道有環存在
3. 建立環後向左走，拆掉環後向右走
```

```cpp
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        int val;
        
        while (cur) {
            if (cur->left) {
                auto *tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;
                if (!tmp->right) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    val = cur->val;
                    tmp->right = nullptr;
                    cur = cur->right;
                    break;
                }
            } else {
                val = cur->val;
                cur = cur->right;
                break;
            }
        }
        
        return val;
    }
    
    bool hasNext() {
        return cur;
    }
    
private:
    TreeNode *cur;
};
```
