class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1 = 0, mx2 = 0, mn1 = 1e5, mn2 = 1e5;
        for (int x : nums) {
            if (x > mx1) {
                mx2 = mx1;
                mx1 = x;
            } else if (x > mx2) {
                mx2 = x;
            }
            
            if (x < mn1) {
                mn2 = mn1;
                mn1 = x;
            } else if (x < mn2) {
                mn2 = x;
            }
        }
        return mx1 * mx2 - mn1 * mn2;
    }
};
