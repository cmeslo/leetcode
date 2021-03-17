class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        sort(begin(nums), end(nums));
        
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                ++i; --j;
                ++ans;
            } else if (sum < k) {
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};
