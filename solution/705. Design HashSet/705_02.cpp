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

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
