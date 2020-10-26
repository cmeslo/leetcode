# 449. Serialize and Deserialize BST

利用中序遍歷

c++ 可以用 istringstream 簡化字符串操作

```cpp
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "x";
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
private:
    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        iss >> val;
        if (val == "x") return nullptr;
        
        auto *root = new TreeNode(stoi(val));
        root->left = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
        return root;
    }
};
```
