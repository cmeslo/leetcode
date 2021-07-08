# 19. Remove Nth Node From End of List

## 解釋

用雙指針 slow, fast

```py
X -> X -> X -> Y -> X -> X    比如 n = 3，fast 先向前走 4 步
s              f

X -> X -> X -> Y -> X -> X    然後再一起移動
     s              f

X -> X -> X -> Y -> X -> X    直至 fast 不能再走
          s              f

X -> X -> X ------> X -> X    去掉 slow->next，完。
          s              f
```

## Code

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    auto fast = &dummy;
    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    auto slow = &dummy;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    auto tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;

    return dummy.next;
}
```
