# 116. Populating Next Right Pointers in Each Node #

## Solution 1: BFS ([116_01.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/116_01.cpp))

```cpp
Node* connect(Node* root) {
    if (!root) return root;
    
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        for (int i = q.size(); i > 0; --i) {
            auto cur = q.front(); q.pop();
            cur->next = i != 1 ? q.front(): nullptr;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return root;
}
```


## Solutoin 2: DFS ([116_02.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/116_03.cpp))

```cpp
void connect(TreeLinkNode *root) {
    if (!root) return;
    if (root->left) {
        root->left->next = root->right;
        if (root->next) root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
}
```

## Solution 3: Pointer ([116_03.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/116.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node/116_04.cpp))

Use ```start``` pointer to record first node of each layer, ```cur``` pointer to traverse each layer. O(1) space.
