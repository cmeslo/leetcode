class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = count(nums.begin(), nums.end(), 1), n = nums.size(), res = nums.size();
        for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
            while (j - i < ones)
                cnt += nums[j++ % n];
            res = min(res, ones - cnt);
            cnt -= nums[i];
        }
        return res;
    }
};


// x x [1 0 1] x x
// [x x x] x x x x
