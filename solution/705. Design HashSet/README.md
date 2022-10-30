# 705. Design HashSet

題目定為Easy，再看看數字長度要求，應該不是要求實現一個真的```set```

## Solution 1: vector

### 一維數組
```cpp
class MyHashSet {
private:
    vector<int> data;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(1000000, 0);
    }
    
    void add(int key) {
        data[key] = 1;
    }
    
    void remove(int key) {
        data[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key] == 1;
    }
};
```

### 二維數組，利用hash 節省一點空間

插入相應數字時才分配空間

```cpp
// Runtime: 112 ms, Your runtime beats 90.95 % of cpp submissions.
// Memory Usage: 96 MB, Your memory usage beats 27.68 % of cpp submissions.

class MyHashSet {
private:
    vector<vector<int>> data;
    const int M = 1000;
    
public:
    MyHashSet() {
        data.resize(M);
    }
    
    void add(int key) {
        auto& a = data[key % M];
        if (a.empty())
            a.resize(M + 1, 0);
        a[key / M] = 1;
    }
    
    void remove(int key) {
        auto& a = data[key % M];
        if (a.empty()) return;
        a[key / M] = 0;
    }
    
    bool contains(int key) {
        int hash = key % M;
        auto& a = data[hash];
        if (a.empty()) return false;
        return a[key / M];
    }
};
```

# Solution 2: BST

```cpp
// Runtime: 84 ms, Your runtime beats 98.48 % of cpp submissions.
// Memory Usage: 40.8 MB, Your memory usage beats 85.95 % of cpp submissions.

class BSTNode {
public:
    int val;
    BSTNode *left, *right;
    BSTNode(int val): val(val), left(nullptr), right(nullptr) {}
};

class MyHashSet {
public:
    MyHashSet(): root(nullptr) {
    }
    
    void add(int key) {
        if (!root) {
            root = new BSTNode(key);
            return;
        }
        
        BSTNode *pre = nullptr, *cur = root;
        while (cur) {
            if (key == cur->val) return;
            
            pre = cur;
            if (key < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (key < pre->val)
            pre->left = new BSTNode(key);
        else
            pre->right = new BSTNode(key);
    }
    
    void remove(int key) {
        root = remove(root, key);
    }
    
    bool contains(int key) {
        auto p = root;
        while (p) {
            if (p->val == key) return true;
            if (key < p->val)
                p = p->left;
            else
                p = p->right;
        }
        return false;
    }

private:
    BSTNode* root;
    
    BSTNode* remove(BSTNode* node, int key) {
        if (!node) return node;
        
        if (key < node->val)
            node->left = remove(node->left, key);
        else if (node->val < key)
            node->right = remove(node->right, key);
        else {
            BSTNode *new_node = nullptr;
            if (!node->left)
                new_node = node->right;
            else if (!node->right)
                new_node = node->left;
            else {
                BSTNode *pre = nullptr;
                new_node = node->right;
                while (new_node->left) {
                    pre = new_node;
                    new_node = new_node->left;
                }
                new_node->left = node->left;
                if (pre) {
                    pre->left = new_node->right;
                    new_node->right = node->right;
                }
            }
            return new_node;
        }
        return node;
    }
};
```
