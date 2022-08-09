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


// 0 0 1 0 1 <--5
// 1 1 0 0 1 <--25
// 1 1 1 0 0 <--28
