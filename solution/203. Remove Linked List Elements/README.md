# 203. Remove Linked List Elements #

## [203_01.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/203.%20Remove%20Linked%20List%20Elements/203_01.cpp) ##
Iteration.

## [203_02.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/203.%20Remove%20Linked%20List%20Elements/203_02.cpp) ##
Recursion.

```cpp
ListNode* removeElements(ListNode* head, int val) {
    if (!head) return nullptr;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}
```
