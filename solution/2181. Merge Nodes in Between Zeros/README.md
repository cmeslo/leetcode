# 2181. Merge Nodes in Between Zeros

```cpp
ListNode* mergeNodes(ListNode* head) {
    vector<int> A;
    while (head) {
        if (head->val == 0)
            A.push_back(head->val);
        else {
            if (A.back() == 0)
                A.push_back(head->val);
            else
                A.back() += head->val;
        }
        head = head->next;
    }
    ListNode dummy;
    auto pre = &dummy;
    for (int x : A) {
        if (x == 0) continue;
        pre->next = new ListNode(x);
        pre = pre->next;
    }
    return dummy.next;
}
```
