class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int n = nums.size();
        
        vector<int> diff(n + 1);
        int res = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((sum + diff[i] + nums[i]) % 2 == 0) {
                if (i + k > n) return -1;
                diff[i] += 1;
                diff[i + k] -= 1;
                ++res;
            }
            sum += diff[i];
        }
        return res;
    }
};
