# 203. Remove Linked List Elements

## Solution 1: Recursion

```cpp
ListNode* removeElements(ListNode* head, int val) {
    if (!head) return nullptr;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}
```

## Solution 2: Iteration

```cpp
ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val)
        head = head->next;
    auto cur = head;
    while (cur) {
        auto p = cur->next;
        while (p && p->val == val)
            p = p->next;
        cur->next = p;
        cur = cur->next;
    }
    return head;
}
```

or

```cpp
ListNode* removeElements(ListNode* head, int val) {
    while (head && head->val == val) {
        auto* tmp = head;
        head = head->next;
        delete tmp;
    }

    auto* cur = head;
    while (cur) {
        while (cur->next && cur->next->val == val) {
            auto* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        cur = cur->next;
    }

    return head;
}
```
