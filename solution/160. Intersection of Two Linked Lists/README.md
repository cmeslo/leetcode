# 160. Intersection of Two Linked Lists

## Solution 1 - coloring

有點取巧的方法，因為Node的取值範圍是 ```1 <= Node.val <= 10^5```，不會出現 0 或 負數。

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto a = headA, b = headB;
    while (a) {
        a->val *= -1;
        a = a->next;
    }

    ListNode* ans = nullptr;
    while (b) {
        if (!ans && b->val < 0) {
            ans = b;
            break;
        }
        b = b->next;
    }

    a = headA; // recover to the original list
    while (a) {
        a->val *= -1;
        a = a->next;
    }
    return ans;
}
```
