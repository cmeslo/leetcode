# 445. Add Two Numbers II #

## [445_01.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/445.%20Add%20Two%20Numbers%20II/445_01.cpp), [445_01.java](https://github.com/cmeslo/leetcode/blob/master/solution/445.%20Add%20Two%20Numbers%20II/445_01.java) ##
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

時間換空間

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode *ans = nullptr;
        ListNode *cur = nullptr;
        int carry = 0;
        while (l1 || l2 || carry) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            
            int sum = a + b + carry;
            if (!cur) {
                cur = new ListNode(sum % 10);
                ans = cur;
            } else {
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
            }
            carry = sum / 10;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return reverseList(ans);
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            auto *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
```
