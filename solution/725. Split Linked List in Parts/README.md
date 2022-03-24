# 725. Split Linked List in Parts

```cpp
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ans(k, nullptr);
    if (!head) return ans;

    int n = 0;
    for (auto p = head; p; p = p->next, ++n);
    int len = n / k, remains = n % k;

    ListNode *pre = nullptr, *cur = head;
    for (int i = 0; i < k; ++i, --remains) {
        ans[i] = cur;
        for (int j = 0; j < len + (remains > 0); ++j) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
    }
    return ans;
}
```
