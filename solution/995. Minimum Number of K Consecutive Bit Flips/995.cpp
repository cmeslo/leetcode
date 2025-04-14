class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> F(n + 1);
        int res = 0, f = 0;
        if (nums[0] == 0) {
            F[0] += 1;
            F[k] -= 1;
            f = 1;
            ++res;
        }
        for (int i = 1; i < n; ++i) {
            f += F[i];
            if ((nums[i] == 0 && (f % 2 == 0)) || (nums[i] == 1 && (f % 2))) {
                if (i + k > n) return -1;
                F[i] += 1;
                F[i + k] -= 1;
                f += 1;
                ++res;
            }
        }
        return res;
    }
};
