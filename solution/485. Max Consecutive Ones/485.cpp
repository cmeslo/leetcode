class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cur = 0;
        for (int x : nums) {
            cur = x ? cur + 1 : 0;
            ans = max(ans, cur);
        }
        return ans;
    }
};
