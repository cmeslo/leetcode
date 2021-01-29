class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int l = 0, r = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            int l_square = nums[l] * nums[l];
            int r_square = nums[r] * nums[r];
            
            if (l_square < r_square) {
                ans[i] = r_square;
                --r;
            } else {
                ans[i] = l_square;
                ++l;
            }
        }
        
        return ans;
    }
};
