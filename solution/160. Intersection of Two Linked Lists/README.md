# 160. Intersection of Two Linked Lists

## Solution 1 - coloring

### 解釋：

有點取巧的方法，因為Node的取值範圍是 ```1 <= Node.val <= 10^5```，不會出現 0 或 負數，

所以先遍歷 list A，沿途標記成負數，再遍歷 list B，遇到的第一個負數就是答案了，

不過最後要把負值恢復回來。

### Code：

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto a = headA, b = headB;
    while (a) {
        a->val *= -1;
        a = a->next;
    }

    ListNode* ans = nullptr;
    while (b) {
        if (b->val < 0) {
            ans = b;
            break;
        }
        b = b->next;
    }

    a = headA; // recover to the original list
    while (a) {
        a->val *= -1;
        a = a->next;
    }
    return ans;
}
```

## Solution 2 - 這題的正規做法

### 解釋：

指針 a 從頭開始走到 list A 的尾時，接着走去 list B 的頭，然後繼續走；

指針 b 從頭開始走到 list B 的尾時，接着走去 list A 的頭，然後繼續走；

這時指針 a 和 b 走的路線一樣長，

list A 和 list B 有相交時，a 和 b 就會在同一點相遇，沒有相交時就會走到對方的尾（nullptr）。

### Code：

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto a = headA, b = headB;
    while (a != b) {
        a = (a ? a->next : headB);
        b = (b ? b->next : headA);
    }
    return a;
}
```
