# 2181. Merge Nodes in Between Zeros

```cpp
ListNode* mergeNodes(ListNode* head) {
    ListNode dummy;
    auto p = &dummy;
    int sum = 0;
    head = head->next;
    while (head) {
        if (head->val == 0) {
            p->next = new ListNode(sum);
            p = p->next;
            sum = 0;
        }
        sum += head->val;
        head = head->next;
    }
    return dummy.next;
}
```
