class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
    
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int res = 0, i = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {
            goal -= nums[j];
            while (goal < 0)
                goal += nums[i++];
            res += j - i + 1;
        }
        return res;
    }
};
