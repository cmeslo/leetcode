class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j)
            ans += nums[j--] - nums[i++];
        return ans;
    }
};
