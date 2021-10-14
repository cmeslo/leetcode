# 141. Linked List Cycle

## Solution: Floyd cycle detection algorithm
Floyd cycle detection algorithm, similar [problem](https://leetcode.com/problems/linked-list-cycle-ii/description/) - [142. Linked List Cycle II](https://github.com/cmeslo/leetcode/tree/master/solution/142.%20Linked%20List%20Cycle%20II)

```cpp
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```
