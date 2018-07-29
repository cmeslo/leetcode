class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        
        for (auto &a : nums) {
            sum += a;
        }
        
        return 0.5 * n * (1 + n) - sum;
    }
};
