# 445. Add Two Numbers II #

## Solution 1: stack ([445_01.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/445.%20Add%20Two%20Numbers%20II/445_01.cpp), [445_01.java](https://github.com/cmeslo/leetcode/blob/master/solution/445.%20Add%20Two%20Numbers%20II/445_01.java)) ##
Stack. 

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }

    ListNode *cur = new ListNode(0);
    int sum = 0;
    while (!s1.empty() || !s2.empty()) {
        if (!s1.empty()) {sum += s1.top(); s1.pop();}
        if (!s2.empty()) {sum += s2.top(); s2.pop();}
        ListNode *head = new ListNode(sum / 10);
        cur->val = sum % 10;
        head->next = cur;
        cur = head;
        sum /= 10;
    }
    return cur->val != 0 ? cur : cur->next;
}
```

or

```cpp
// Your runtime beats 94.77 % of cpp submissions.

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> st1, st2;
    while (l1) {
        st1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        st2.push(l2->val);
        l2 = l2->next;
    }

    ListNode *head = nullptr;
    int sum = 0;
    while (!st1.empty() || !st2.empty() || sum) {
        if (!st1.empty()) {
            sum += st1.top(); st1.pop();
        }
        if (!st2.empty()) {
            sum += st2.top(); st2.pop();
        }

        auto tmp = head;
        head = new ListNode(sum % 10);
        head->next = tmp;

        sum /= 10;
    }

    return head;
}
```

## Solution 2: reverse list ([445_02.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/445.%20Add%20Two%20Numbers%20II/445_02.cpp))

時間換空間

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode dummy;
        auto p = &dummy;
        int a = 0, b = 0, carry = 0;
        while (l1 || l2 || carry) {
            a = 0, b = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode((a + b + carry) % 10);
            carry = (a + b + carry) / 10;
            p = p->next;
        }
        return reverse(dummy.next);
    }
    
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        while (node) {
            auto next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};
```
