# 25. Reverse Nodes in k-Group

## Solution 1: Recursion

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) return nullptr;

    auto p = head;
    for (int t = 0; t < k; ++t) {
        if (!p) return head;
        p = p->next;
    }

    ListNode* pre = nullptr;
    auto cur = head;
    for (int i = 0; i < k && cur; ++i) {
        auto tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head->next = reverseKGroup(cur, k);
    return pre;
}
```

## Solution 2: Iteration

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    int len = 0;
    auto p = head;
    while (p) {
        ++len;
        p = p->next;
    }

    ListNode* ans = head;
    ListNode* tail = head;
    int groups = len / k;
    for (int i = 0; i < groups; ++i) {
        ListNode* new_tail = head;
        ListNode* pre = nullptr;
        for (int j = 0; j < k; ++j) {
            auto tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        if (i == 0) ans = pre;
        tail->next = pre;
        tail = new_tail;
    }
    tail->next = head;
    return ans;
}
```
