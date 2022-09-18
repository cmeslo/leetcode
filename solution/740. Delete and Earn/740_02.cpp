class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> gain(n);
        for (int x : nums)
            gain[x] += x;
        
        int a = 0; // 取nums[i]所能獲得的最大收益
        int b = 0; // 不取nums[i]所能獲得的最大收益
        for (int i = 0; i < n; ++i) {
            int a2 = a, b2 = b;
            a = b2 + gain[i];
            b = max(a2, b2);
        }
        return max(a, b);
    }
};
