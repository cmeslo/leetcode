class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mn = 0, sum = 0, res = nums[0];
        for (int x : nums) {
            sum += x;
            res = max(res, sum - mn);
            mn = min(mn, sum);
        }
        return res;
    }
};


// [x x x] [x x x x] x x x
//      ^         ^
//      min_sum   sum
