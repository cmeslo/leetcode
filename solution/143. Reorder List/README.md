# 143. Reorder List

## Solution 1: deque

```cpp
void reorderList(ListNode* head) {
    if (!head) return;

    deque<ListNode*> q;
    auto* cur = head;
    while (cur) {
        q.push_back(cur);
        cur = cur->next;
    }

    ListNode *p1 = nullptr, *p2 = nullptr;
    while (!q.empty()) {
        p1 = q.front(); q.pop_front();
        if (p2) p2->next = p1;
        if (q.empty()) {
            p1->next = nullptr;
            break;
        }

        p2 = q.back(); q.pop_back();
        p1->next = p2;
        if (q.empty()) {
            p2->next = nullptr;
            break;
        }
    }
}
```

## Solution 2: cut and merge (推薦)

### C++

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto p1 = head, p2 = reverse(slow->next);
        slow->next = nullptr;
        
        while (p1 && p2) {
            auto next1 = p1->next;
            auto next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }
    
private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            auto next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
```

### Java

```java
class Solution {
    public void reorderList(ListNode head) {
        if (head == null) return;
        
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode p2 = reverse(slow.next);
        slow.next = null;
        
        ListNode p1 = head;
        while (p1 != null && p2 != null) {
            ListNode tmp1 = p1.next;
            ListNode tmp2 = p2.next;
            p1.next = p2;
            p2.next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
    }
    
    private ListNode reverse(ListNode node) {
        ListNode pre = null;
        while (node != null) {
            ListNode tmp = node.next;
            node.next = pre;
            pre = node;
            node = tmp;
        }
        return pre;
    }
}
```

## Solution 3: Two pointers

```cpp
void reorderList(ListNode* head) {
    vector<int> A;
    auto p = head;
    while (p) {
        A.push_back(p->val);
        p = p->next;
    }
    int i = 0, j = A.size() - 1;
    bool flag = true;
    while (i <= j) {
        if (flag)
            head->val = A[i++];
        else
            head->val = A[j--];
        flag = !flag;
        head = head->next;
    }
}
```
