# 23. Merge k Sorted Lists

## Solution 1: brute force + recursive

Time complexity: ```O(kN)```

可以AC，但 runtime 非常差。

### code (23_01.cpp)

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

## Solution 2: heap

最優方法，也最簡潔。

Time complexity: ```O(Nlogk)```

### 自定義比較函數，lambda 寫法 (23_02.cpp)：

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto comp = [&](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

    for (auto node : lists)
        if (node) pq.push(node);

    ListNode dummy(0);
    auto tail = &dummy;
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        if (top->next)
            pq.push(top->next);
        tail = tail->next = top;
    }
    return dummy.next;
}
```

### 自定義比較函數，struct 寫法：

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        for (auto node : lists)
            if (node) pq.push(node);
        
        ListNode dummy(0);
        auto tail = &dummy;
        while (!pq.empty()) {
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return dummy.next;
    }
    
private:
    struct comp {
        bool operator() (const ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};
```

### 自定義比較函數，class 寫法：

```cpp
class Comp {
public:
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        
        for (auto node : lists)
            if (node) pq.push(node);
        
        ListNode dummy(0);
        auto tail = &dummy;
        while (!pq.empty()) {
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return dummy.next;
    }
};
```

## Solution 3: divide-and-conquer + merge two sorted lists

通過這個方法，可以學到

1. 分治合併數組時，處理index的技巧
2. 分治的時間複雜度分析方法

Time complexity: ```O(logk*(kn))```
```
k/2*(2n) + k/4*(4n) + k/8*(8n) + ... + (k/2^logk)*(2^logk*n)
= kn + kn + kn + ... + kn
= logk * (kn)
```

### code (23_03.cpp)

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int n = lists.size();
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
            n = (n + 1) / 2;
        }
        return lists[0];
    }
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return l1 ? l1 : l2;
        
        ListNode dummy(0);
        auto* tail = &dummy;
        while (l1 && l2) {
            auto& tmp = l1->val < l2->val ? l1 : l2;
            tail = tail->next = tmp;
            tmp = tmp->next;
        }
        auto& tmp = l1 ? l1 : l2;
        while (tmp) {
            tail = tail->next = tmp;
            tmp = tmp->next;
        }
        return dummy.next;
    }
};
```

reference: https://leetcode.com/problems/merge-k-sorted-lists/discuss/10531/Sharing-my-straightforward-C%2B%2B-solution-without-data-structure-other-than-vector
