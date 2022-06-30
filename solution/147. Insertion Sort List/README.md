# 147. Insertion Sort List

```cpp
ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(0);

    while (head) {
        auto *tmp = head->next;
        auto *cur = &dummy;
        while (cur->next && cur->next->val <= head->val)
            cur = cur->next;

        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }

    return dummy.next;
}
```
