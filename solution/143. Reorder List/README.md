# 143. Reorder List

## deque

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

## cut and merge

```cpp
void reorderList(ListNode* head) {
    if (!head) return;

    // 1. find the middle node
    auto *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. cut and reverse the second list
    ListNode *head2 = nullptr;
    ListNode *last = slow->next;
    slow->next = nullptr;
    while (last) {
        auto *tmp = last->next;
        last->next = head2;
        head2 = last;
        last = tmp;
    }

    // 3. merge two list
    while (head && head2) {
        auto *tmp1 = head->next, *tmp2 = head2->next;
        head->next = head2;
        head2->next = tmp1;
        head = tmp1;
        head2 = tmp2;
    }
}
```
