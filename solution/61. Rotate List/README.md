# 61. Rotate List

1. 找到中斷點
2. 斷開後重新連接

```cpp
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) return head;

    // 1. count list size
    auto *p = head, *tail = head;
    int n = 0;
    while (p) {
        ++n;
        tail = p;
        p = p->next;
    }
    k %= n;
    if (k == 0) return head;

    // 2. find the break point
    auto *pre = head, *cur = head;
    int left = n - k;
    while (left--) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = nullptr;

    // 3. concatenate two list
    tail->next = head;

    return cur;
}
```
