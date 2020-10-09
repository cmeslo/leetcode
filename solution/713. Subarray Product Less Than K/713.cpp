class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        
        int i = 0, prod = 1;
        for (int j = 0; j < nums.size(); ++j) {
            prod *= nums[j];
            while (i <= j && prod >= k) {
                prod /= nums[i++];
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
