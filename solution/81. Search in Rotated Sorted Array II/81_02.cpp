class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return true;
            
            // 前半段有序：
            if (nums[l] < nums[m]) {
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            // 後半段有序：
            } else if (nums[m] < nums[r]) {
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            // 不知道 前半 還是 後半 有序，一點點縮小範圍：
            } else {
                if (nums[l] == nums[m])
                    ++l;
                else
                    --r;
            }
        }
        
        return false;
    }
};
