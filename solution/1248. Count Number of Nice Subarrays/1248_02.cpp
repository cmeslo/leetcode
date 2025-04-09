class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
    int atMost(vector<int>& nums, int k) {
        const int n = nums.size();
        int res = 0;
        for (int j = 0, i = 0; i < n; ++i) {
            k -= nums[i] & 1;
            while (k < 0)
                k += nums[j++] & 1;
            res += i - j + 1;
        }
        return res;
    }
};
