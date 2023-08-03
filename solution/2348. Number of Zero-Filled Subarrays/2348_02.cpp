class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int i = -1;
        for (int j = 0; j <= n; ++j) {
            if (j == n || nums[j] != 0) {
                long len = j - i - 1;
                res += len * (1 + len) / 2;
                i = j;
            }
        }
        return res;
    }
};

// x 0 0 0 x
// 0 1 2 3 4    

// 3 * (1 + 3) / 2 = 6

// 3
// 2
// 1
