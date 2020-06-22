class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int n : nums)
                sum += (n >> i) & 1;
            ans |= (sum % 3) << i;
        }
        return ans;
    }
};
