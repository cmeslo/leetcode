# 421. Maximum XOR of Two Numbers in an Array #

## 421_01.cpp ##
Find pair(s) whoes Left bits can XOR to max. This is O(32n), which is still O(n).

[Explanation 1](https://discuss.leetcode.com/topic/63213/java-o-n-solution-using-bit-manipulation-and-hashmap/7)

[Explanation 2](https://segmentfault.com/a/1190000007283296)

```cpp
int findMaximumXOR(vector<int>& nums) {
    int max = 0, mask = 0;

    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);

        unordered_set<int> s;
        for (int n : nums) {
            s.insert(n & mask);
        }

        int tmp = max | (1 << i);

        for (int prefix : s) {
            if (s.find(prefix ^ tmp) != s.end()) {
                max = tmp;
                break;
            }
        }
    }
    return max;
}
```

## 421_02.cpp ##

Use Trie

```cpp
class TrieNode {
public:
    TrieNode* childs[2];
    TrieNode() {
        childs[0] = childs[1] = nullptr;
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

or (array faster than vector>

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
