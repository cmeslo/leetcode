class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long res = -1, sum = 0;
        for (int x : nums) {
            if (sum > x)
                res = sum + x;
            sum += x;
        }
        return res;
    }
};
