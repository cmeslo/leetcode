# 138. Copy List with Random Pointer

## Solution 1: map (138_01.cpp)

- Time complexity: ```O(n)```
- Space complexity: ```O(n)```

```cpp
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> copies;

    Node* cur = head;
    while (cur) {
        copies[cur] = new Node(cur->val);
        cur = cur->next;
    }

    cur = head;
    while (cur) {
        copies[cur]->next = copies[cur->next];
        copies[cur]->random = copies[cur->random];
        cur = cur->next;
    }

    return copies[head];
}
```

## Solution 2: O(1) space (138_02.cpp)

3 steps:
  1. copy and insert each nodes to the original list
  2. copy random
  3. split duplicated nodes as answer
  
  ![138_02.png](https://github.com/cmeslo/leetcode/blob/master/solution/138.%20Copy%20List%20with%20Random%20Pointer/138_02.png?raw=true)

- Time complexity: ```O(n)```
- Space complexity: ```O(1)```

```cpp
Node* copyRandomList(Node* head) {
    if (!head) return head;

    // 1. insert copy nodes
    auto p = head;
    while (p) {
        Node* copy = new Node(p->val);
        copy->next = p->next;
        p->next = copy;
        p = copy->next;
    }

    // 2. copy random pointer
    p = head;
    while (p) {
        if (p->random)
            p->next->random = p->random->next;
        p = p->next->next;
    }

    // 3. split two links
    auto ans = head->next;
    p = head;
    while (p && p->next) {
        auto tmp = p->next;
        p->next = tmp->next;
        p = tmp;
    }

    return ans;
}
```

reference [here](https://discuss.leetcode.com/topic/7594/a-solution-with-constant-space-complexity-o-1-and-linear-time-complexity-o-n) and [here](http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html).
