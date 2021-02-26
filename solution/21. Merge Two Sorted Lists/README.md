# 21. Merge Two Sorted Lists

## Recursive (21_01.cpp)
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 || !l2)
        return l1 ? l1 : l2;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}
```

## Iterative (21_02.cpp)

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    auto *tail = &dummy;

    while (l1 && l2) {
        auto& p = l1->val < l2->val ? l1 : l2;
        tail->next = p;
        p = p->next;
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;

    return dummy.next;
}
```
