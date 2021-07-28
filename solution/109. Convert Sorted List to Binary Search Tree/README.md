# 109. Convert Sorted List to Binary Search Tree

## Solution: Recursive

1. 找中點作為 TreeNode
2. 斷開中點
3. 遞歸處理左、右 List

```cpp
TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;

    ListNode* prev = nullptr;
    auto slow = head, fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    auto root = new TreeNode(slow->val);
    if (prev) {
        prev->next = nullptr;
        root->left = sortedListToBST(head);
    }
    root->right = sortedListToBST(slow->next);
    return root;
}
```
