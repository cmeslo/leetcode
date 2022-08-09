# 421. Maximum XOR of Two Numbers in an Array #

## Solution 1: Bit Manipulation (421_01.cpp) ##

```cpp
// Runtime: 294 ms, Your runtime beats 86.68 % of cpp submissions.
// Memory Usage: 50.5 MB, Your memory usage beats 97.91 % of cpp submissions.

int findMaximumXOR(vector<int>& nums) {
    int res = 0, mask = 0;

    for (int i = 31; i >= 0; --i) {
        mask |= 1 << i;
        unordered_set<int> prefix;

        int expect = res | (1 << i);
        for (int x : nums) {
            int a = mask & x; // expect = a ^ b, --> b = expect ^ a
            if (prefix.count(expect ^ a)) { // 當我確實可以得到 expect
                res = expect;
                break;
            }
            prefix.insert(a);
        }
    }

    return res;
}
```

## Solution 2: Trie (421_02.cpp) ##

```cpp
// Runtime: 200 ms, Your runtime beats 98.97 % of cpp submissions.
// Memory Usage: 79.2 MB, Your memory usage beats 35.69 % of cpp submissions.

class TrieNode {
public:
    TrieNode* next[2];
    int val;
    TrieNode(): val(0) {
        next[0] = next[1] = nullptr;
    };
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode root;
        for (int x : nums) {
            auto cur = &root;
            for (int i = 31; i >= 0; --i) {
                int bit = (x >> i) & 1;
                if (!cur->next[bit])
                    cur->next[bit] = new TrieNode();
                cur = cur->next[bit];
            }
            cur->val = x;
        }
        
        int res = 0;
        for (int x : nums) {
            auto cur = &root;
            for (int i = 31; i >= 0; --i) {
                int expect = !((x >> i) & 1);
                if (cur->next[expect])
                    cur = cur->next[expect];
                else
                    cur = cur->next[!expect];
            }
            res = max(res, x ^ cur->val);
        }
        return res;
    }
};
```

or

```cpp
class TrieNode {
public:
    vector<TrieNode*> childs;
    TrieNode(): childs(2) {}
    ~TrieNode() {
        for (auto& child : childs)
            delete child;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode root;
        
        for (int n : nums) {
            auto* cur = &root;
            for (int i = 31; i >= 0; --i) {
                int bit = (n >> i) & 1;
                auto& node = cur->childs[bit];
                if (!node) node = new TrieNode();
                cur = node;
            }
        }
        
        int ans = 0;
        for (int n : nums) {
            auto* cur = &root;
            int tmp = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (n >> i) & 1;
                if (cur->childs[1 - bit]) {
                    tmp |= (1 << i);
                    cur = cur->childs[1 - bit];
                } else {
                    cur = cur->childs[bit];
                }
            }
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};
```
