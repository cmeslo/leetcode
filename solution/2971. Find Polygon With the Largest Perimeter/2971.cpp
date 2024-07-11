class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long res = -1, sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i - 1] <= nums[i]) {
                if (++cnt >= 3 && sum > nums[i])
                    res = max(res, sum + nums[i]);
                sum += nums[i];
            } else {
                sum = nums[i];
                cnt = 1;
            }
        }
        return res;
    }
};
