class Solution {
public:
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
};
