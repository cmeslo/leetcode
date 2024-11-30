class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> cnt(32);
        for (int x : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((x >> i) & 1)
                    cnt[i]++;
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if ((k >> i) & 1) {
                if (cnt[i] % 2 == 0)
                    ++res;
            } else {
                if (cnt[i] % 2 == 1)
                    ++res;
            }
        }
        return res;
    }
};
