# 382. Linked List Random Node

## 382_01.cpp

Count the length of list.

```cpp
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        len = 0;
        
        while (head) {
            ++len;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand() % len;
        
        auto *cur = head;
        while (pos-- > 0)
            cur = cur->next;
        
        return cur->val;
    }
    
private:
    ListNode *head;
    int len;
};
```

## Reservoir Sampling (382_02.cpp)

### 水塘抽樣算法解釋

在不知道樣本數目多少的情況下，仍然能夠以 1/n 概率選中各個數字的算法

```
1/i
 ^----第一個數字出現，抽中的概率 100%

1/i * (1 - 1/(i+1))
           ^---------第二個數字出現，但它沒有被抽中的概率

1/i * (1 - 1/(i+1)) * (1 - 1/(i+2))
                            ^---------第三個數字出現，但它沒有被抽中的概率

1/i * (1 - 1/(i+1)) * (1 - 1/(i+2)) * ... * (1 - 1/n)
                                                ^---------最後一個數字出現，但它沒有被抽中的概率

1/i * i/(i+1) * (i+1)/(i+2) * ... * (n-1)/n = 1/n
                                               ^-----------最後換算一下可以得出結果為 1/n
```

也就是說，每次都會

有 1/i 的概率會改變選中的數字，

有 1 - 1/i 的概率不改變選中的數字


### Code

```cpp
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        auto *cur = this->head;
        int val = cur->val;
        int i = 1;
        while (cur) {
            if (rand() % i++ == 0) // 中了 1/i，要改變了
                val = cur->val;
            cur = cur->next;
        }
        
        return val;
    }
    
private:
    ListNode* head;
};
```

1/i 可以用 rand() % i == 0

```cpp
while (cur) {
    if (rand() % i++ == 0)
        val = cur->val;
    cur = cur->next;
}
```

也可以用 rand() % i == i - 1 來表示，就是取第一個數或者最後一個數的意思

```cpp
while (cur) {
    if (rand() % i == i - 1)
        val = cur->val;
    ++i;
    cur = cur->next;
}
```
