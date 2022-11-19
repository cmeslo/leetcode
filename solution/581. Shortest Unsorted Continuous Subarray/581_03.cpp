class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                mn = min(mn, nums[i + 1]);
                mx = max(mx, nums[i]);
            }
        }
        if (mn > mx) return 0;
        
        int l = -2, r = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > mn) {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < mx) {
                r = i;
                break;
            }
        }
        return r - l + 1;
    }
};
