# 328. Odd Even Linked List

## Solution: Two pointers

```
x y x y
    a b

x y x
    a b
```

### C++

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

### Java

```java
public ListNode oddEvenList(ListNode head) {
    if (head == null) return head;
    
    ListNode evenHead = head.next;
    ListNode a = head, b = head.next;
    while (b != null && b.next != null) {
        a.next = b.next;
        a = a.next;
        b.next = a.next;
        b = b.next;
    }
    a.next = evenHead;
    return head;
}
```

### Python

```py
def oddEvenList(self, head):
    if not head: return None
    
    evenHead = head.next
    a, b = head, head.next
    while b and b.next:
        a.next = b.next
        a = a.next
        b.next = a.next
        b = b.next
    a.next = evenHead
    return head
```
