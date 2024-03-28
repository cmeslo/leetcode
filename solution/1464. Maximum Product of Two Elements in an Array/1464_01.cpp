class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mx = max(mx, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        return mx;
    }
};
