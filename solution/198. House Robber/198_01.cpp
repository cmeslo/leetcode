class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int pre2 = 0, pre1 = 0;
        for (const int n : nums) {
            ans = max(pre1, pre2 + n);
            pre2 = pre1;
            pre1 = ans;
        }
        
        return ans;
    }
};
