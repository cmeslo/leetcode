# 445. Add Two Numbers II #

## [445_01.cpp](https://github.com/cmeslo/leetcode/blob/master/solution/445.%20Add%20Two%20Numbers%20II/445_01.cpp), [445_01.java](https://github.com/cmeslo/leetcode/blob/master/solution/445.%20Add%20Two%20Numbers%20II/445_01.java) ##
Stack. 

How to iterate:
```cpp
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
```
