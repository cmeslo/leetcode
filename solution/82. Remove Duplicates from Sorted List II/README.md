# 82. Remove Duplicates from Sorted List II

## Iterative (82_01.cpp)

```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0);
    auto tail = &dummy;

    auto pre = head;
    while (pre) {
        auto cur = pre->next;

        while (cur && pre->val == cur->val)
            cur = cur->next;

        if (pre->next == cur) 
            tail = tail->next = pre;

        pre = cur;
    }
    tail->next = nullptr; // [1,2,2]

    return dummy.next;
}
```

## Recursive (82_02.cpp)

```cpp
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode dummy(0);
    auto cur = &dummy;

    auto tmp = head;
    while (tmp && head->val == tmp->val)
        tmp = tmp->next;

    if (head->next == tmp) {
        head->next = deleteDuplicates(tmp);
        cur->next = head;
    } else {
        cur->next = deleteDuplicates(tmp);
    }
    return dummy.next;
}
```
