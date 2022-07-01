# 147. Insertion Sort List

## Solution: Insertion sort

### C++

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

優化版本，不必每次由頭開始:

```cpp
// Runtime: 16 ms, Your runtime beats 94.19 % of cpp submissions.
// Memory Usage: 9.4 MB, Your memory usage beats 99.91 % of cpp submissions.

ListNode* insertionSortList(ListNode* head) {
    ListNode dummy;
    auto cur = &dummy;

    while (head) {
        auto tmp = head->next;
        if (cur->val > head->val) cur = &dummy;
        while (cur->next && cur->next->val <= head->val)
            cur = cur->next;
        head->next = cur->next;
        cur->next = head;
        head = tmp;
    }

    return dummy.next;
}
```

### Java

```java
public ListNode insertionSortList(ListNode head) {
    ListNode dummy = new ListNode();
    ListNode pre = dummy;
    while (head != null) {
        ListNode temp = head.next;
        if (head.val < pre.val) pre = dummy;
        while (pre.next != null && pre.next.val < head.val)
            pre = pre.next;
        head.next = pre.next;
        pre.next = head;
        head = temp;
    }
    return dummy.next;
}
```

### Python

```py
def insertionSortList(self, head):
    dummy = ListNode(0)
    pre = dummy
    while head:
        temp = head.next
        if head.val < pre.val:
            pre = dummy
        while pre.next and pre.next.val < head.val:
            pre = pre.next
        head.next = pre.next
        pre.next = head
        head = temp
    return dummy.next
```
