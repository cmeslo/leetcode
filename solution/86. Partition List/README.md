# 86. Partition List

分成兩條 list，

```list1``` 所有 node 都小於 ```x```，

```list2``` 所有 node 都大於等於 ```x```，

最後拼接 ```list1 -> list2```。

```cpp
ListNode* partition(ListNode* head, int x) {
    ListNode dummy1(0), dummy2(0);
    auto p1 = &dummy1, p2 = &dummy2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p1->next = dummy2.next;
    p2->next = nullptr;
    return dummy1.next;
}
```
