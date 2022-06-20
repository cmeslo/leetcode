# 1290. Convert Binary Number in a Linked List to Integer

## C++

```cpp
int getDecimalValue(ListNode* head) {
    int ans = 0;

    while (head) {
        ans = (ans << 1) | head->val;
        head = head->next;
    }

    return ans;
}
```

## Java

```java
public int getDecimalValue(ListNode head) {
    int res = 0;
    while (head != null) {
        res = (res << 1) | head.val;
        head = head.next;
    }
    return res;
}
```
