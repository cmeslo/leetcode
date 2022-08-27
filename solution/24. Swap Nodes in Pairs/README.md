# 24. Swap Nodes in Pairs

## Solution 1 - Recursive (24_01.cpp)

```cpp
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    auto* cur = head->next;
    head->next = swapPairs(cur->next);
    cur->next = head;

    return cur;
}
```

## Solution 2 - Iterative (24_02.cpp)

```
0 1 2 3 4
p c t

0 2 1 3 4
p t c
```

```cpp
ListNode* swapPairs(ListNode* head) {
    ListNode dummy;
    dummy.next = head;
    auto pre = &dummy, cur = head;
    while (cur && cur->next) {
        auto tmp = cur->next;
        pre->next = tmp;

        cur->next = tmp->next;
        tmp->next = cur;

        pre = cur;
        cur = cur->next;
    }
    return dummy.next;
}
```
