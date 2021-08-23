class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, sum = 0;
        unordered_set<int> window;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            while (window.count(nums[j])) {
                window.erase(nums[i]);
                sum -= nums[i++];
            }
            window.insert(nums[j]);
            sum += nums[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};
