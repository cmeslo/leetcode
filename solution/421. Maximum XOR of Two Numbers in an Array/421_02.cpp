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
