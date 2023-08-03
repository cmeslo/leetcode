class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long res = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) continue;
            int j = i;
            while (j < n && nums[j] == 0)
                ++j;
            int len = j - i;
            res += 1L * len * (1 + len) / 2;
            i = j - 1;
        }
        return res;
    }
};
