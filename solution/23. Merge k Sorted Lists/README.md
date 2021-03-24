# 23. Merge k Sorted Lists

## Solution 1: brute force + recursive

可以AC，但 runtime 非常差。

### 23_01.cpp

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int p = -1;
    for (int i = 0; i < lists.size(); ++i) {
        if (!lists[i]) continue;
        if (p == -1 || lists[i]->val < lists[p]->val)
            p = i;
    }
    if (p == -1) return nullptr;

    auto* head = lists[p];
    if (head) {
        lists[p] = lists[p]->next;
        head->next = mergeKLists(lists);
    }
    return head;
}
```
