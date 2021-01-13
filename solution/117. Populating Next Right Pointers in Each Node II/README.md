# 117. Populating Next Right Pointers in Each Node II #

## Queue ([117_01.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/117.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node%20II/117_01.cpp)) ##

Time: O(n)

Space: O(n)

```cpp
void connect(TreeLinkNode *root) {
    if (!root) return;

    queue<TreeLinkNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeLinkNode *cur = q.front(); q.pop();
            if (i < size - 1) cur->next = q.front();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
}
```

## Three pointer ([117_02.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/117.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node%20II/117_02.cpp)) ##

Iterate level by level with 3 pointer

Time: O(n)

Space: O(1)

```cpp
void connect(TreeLinkNode *root) {
    if (!root) return;
    
    TreeLinkNode *head = NULL, *prev = NULL, *cur = root;
    
    while (cur) {
        while (cur) {
            if (cur->left) {
                if (prev == NULL) {
                    head = cur->left;
                } else {
                    prev->next = cur->left;
                }
                prev = cur->left;
            }
            if (cur->right) {
                if (prev == NULL) {
                    head = cur->right;
                } else {
                    prev->next = cur->right;
                }
                prev = cur->right;
            }
            cur = cur->next;
        }
        cur = head;
        head = NULL;
        prev = NULL;
    }
}
```

2021/01/13 updated:

```cpp
Node* connect(Node* root) {
    Node *head = root;
    Node *firstChild = nullptr;
    Node *cur = nullptr;
    
    while (head) {
        if (head->left) {
            if (cur) {
                cur->next = head->left;
                cur = cur->next;
            } else {
                firstChild = cur = head->left;
            }
        }
        if (head->right) {
            if (cur) {
                cur->next = head->right;
                cur = cur->next;
            } else {
                firstChild = cur = head->right;
            }
        }
        
        if (!(head = head->next)) {
            head = firstChild;
            firstChild = cur = nullptr;
        }
    }
    
    return root;
}
```

## Recursive ([117_03.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/117.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node%20II/117_03.cpp))

Time: O(n)

Space: O(n)

```cpp
Node* connect(Node* root) {
    if (!root) return root;
    
    auto *p = root->next;
    while (p) {
        if (p->left) {
            p = p->left; break;
        }
        if (p->right) {
            p = p->right; break;
        }
        p = p->next;
    }
    
    if (root->right) root->right->next = p;
    if (root->left) root->left->next = root->right ? root->right : p;
    
    connect(root->right);
    connect(root->left);
    
    return root;
}
```

## Dummy node ([117_04.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/117.%20Populating%20Next%20Right%20Pointers%20in%20Each%20Node%20II/117_04.cpp))

使用 Dummy node 記錄下一層的頭節點（最左邊的節點），

第2（117_02.cpp）和第4（117_04.cpp）種解法才是真正符合follow up的要求，

<strong>重點是，模擬 level order traversal 時，怎樣找到下一層的front節點</strong>。

Time: O(n)

Space: O(1)

```cpp
Node* connect(Node* root) {
    auto *head = root;
    
    while (head) {
        Node dummy(0); // 用 dummy.next 保存下一層的 first child
        Node *cur = &dummy;
        
        while (head) {
            if (head->left) {
                cur->next = head->left;
                cur = cur->next;
            }
            if (head->right) {
                cur->next = head->right;
                cur = cur->next;
            }
            head = head->next;
        }
        head = dummy.next;
    }
    
    return root;
}
```
