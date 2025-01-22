class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        const int n = nums.size();
        int res = 0;
        for (int state = 0; state < (1 << n); ++state) {
            int x = 0;
            for (int i = 0; i < n; ++i) {
                if ((state >> i) & 1)
                    x ^= nums[i];
            }
            res += x;
        }
        return res;
    }
};
