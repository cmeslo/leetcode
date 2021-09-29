# 92. Reverse Linked List II

## 寫法一：

```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *L = nullptr, *R = nullptr;
    ListNode *l = nullptr, *r = nullptr;
    // L l . . . r R ==> L r . . . l R

    // find L, l
    auto cur = head;
    while (left > 1) {
        L = cur;
        cur = cur->next;
        --left, --right;
    }
    l = cur;

    // find r, R and reverse
    r = nullptr;
    while (right >= 1) {
        R = cur->next;
        cur->next = r;
        r = cur;
        cur = R;
        --right;
    }

    if (L) L->next = r;
    else head = r; // in case L doesn't exist
    l->next = R;

    return head;
}
```

## 寫法二 (簡潔一些)：

```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *L = &dummy, *R = nullptr;
    ListNode *l = nullptr, *r = nullptr;
    L->next = head;
    // L l . . . r R ==> L r . . . l R

    // find L, l
    auto cur = &dummy;
    for (int i = 0; i < left - 1; ++i)
        cur = cur->next;
    L = cur;
    l = cur = cur->next;

    // find r, R and reverse
    for (int i = left; i <= right; ++i) {
        R = cur->next;
        cur->next = r;
        r = cur;
        cur = R;
    }

    L->next = r;
    l->next = R;

    return dummy.next;
}
```
