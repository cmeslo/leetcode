# 142. Linked List Cycle II

## 142.cpp
Floyd cycle detection algorithm, similar problem - [287. Find the Duplicate Number](https://github.com/cmeslo/leetcode/tree/master/solution/287.%20Find%20the%20Duplicate%20Number).

```cpp
ListNode *detectCycle(ListNode *head) {
    auto *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return nullptr;

    auto *begin = head;
    while (begin != slow) {
        begin = begin->next;
        slow = slow->next;
    }

    return begin;
}
```

### Why the distance from start node to entry node as same as meet node to entry node ?

proof by changjinglu in [discuss](https://discuss.leetcode.com/topic/25913/my-easy-understood-solution-with-o-n-time-and-o-1-space-without-modifying-the-array-with-clear-explanation/10)

When they meet, assume slow tag move s steps, fast tag move 2s steps, the circle length is c.
There must be:

2s = s + n*c

=> s = n*c....(1)

Then, assume the length from start point to entry point is x, and the length from the entry
point to the meet point is a.
There must be: s = x+a....(2)

So, from (1) and (2)

x+a = s = n*c

=> x+a = n*c

=> x+a = (n-1)*c+c

=> x = (n-1)*c+c-a

c-a means the length from the meetpoint to the entry point.

LHS means: the new tag from start point move x steps.

RHS means: the slow tag moves (n-1) cycles plus the length from the meetpoint to the entry point.

So, we can get the entry point when the new tag meet the slow tag.
