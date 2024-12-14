# 237. Delete Node in a Linked List

## C++

```cpp
void deleteNode(ListNode* node) {
    // 寫法一
    // node->val = node->next->val;
    // node->next = node->next->next;
    
    // 寫法二 - 解引用
    // ListNode* tmp = node->next;
    *node = *(node->next);
    // delete tmp;
    
    // 寫法二
    // *node = *(node->next);
    
    // 寫法四
    // node->val = node->next->val;
    // ListNode *tmp = node->next;
    // node->next = tmp->next;
    // delete tmp;
}
```
