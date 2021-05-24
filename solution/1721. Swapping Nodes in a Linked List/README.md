# 1721. Swapping Nodes in a Linked List

## Solution - swap value

```cpp
ListNode* swapNodes(ListNode* head, int k) {
    auto p = head;
    ListNode *p1 = nullptr, *p2 = head;
    while (--k)
        p = p->next;
    p1 = p;

    while (p->next) {
        p = p->next;
        p2 = p2->next;
    }

    swap(p1->val, p2->val);
    return head;
}
```
