# 430. Flatten a Multilevel Doubly Linked List

```cpp
class Solution {
public:
    Node* tail;
    
    Node* flatten(Node* head) {
        auto p = head;
        while (p) {
            if (p->child) {
                auto next = flatten(p->child);
                next->prev = p;
                tail->next = p->next;
                if (p->next) p->next->prev = tail;
                p->next = p->child;
                p->child = nullptr;
            }
            tail = p;
            p = p->next;
        }
        return head;
    }
};
```
