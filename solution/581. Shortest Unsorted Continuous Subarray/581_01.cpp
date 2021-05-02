class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copies(nums);
        sort(begin(copies), end(copies));
        
        int n = nums.size();
        int l = n - 1, r = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != copies[i]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        return l < r ? r - l + 1 : 0;
    }
};
