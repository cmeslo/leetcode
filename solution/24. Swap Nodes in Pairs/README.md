# 24. Swap Nodes in Pairs

## Solution1 - Recursive (24_01.cpp)

```cpp
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    auto* cur = head->next;
    head->next = swapPairs(cur->next);
    cur->next = head;

    return cur;
}
```
