# 328. Odd Even Linked List

## Solution: Two pointers

```
x y x y
    a b

x y x
    a b
```

```cpp
ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;

    auto second_head = head->next;
    auto a = head, b = head->next;
    while (b && b->next) {
        a->next = b->next;
        a = a->next;
        b->next = a->next;
        b = b->next;
    }
    a->next = second_head;
    return head;
}
```
