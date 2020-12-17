class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return true;
            
            // 前半段有序：
            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            // 後半段有序：
            } else if (nums[mid] < nums[r]) {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            // 不知道 前半 還是 後半 有序，一點點縮小範圍：
            } else {
                if (nums[l] == nums[mid])
                    ++l;
                else
                    --r;
            }
        }
        
        return false;
    }
};
