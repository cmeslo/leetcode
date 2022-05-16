class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0, presum = 0;
        for (int& x : nums) {
            presum += x;
            mn = min(mn, presum);
        }
        return 1 - mn;
    }
};
