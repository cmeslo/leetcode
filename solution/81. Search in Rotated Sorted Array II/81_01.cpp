class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        rotate(nums);

        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        
        return false;
    }
    
private:
    void rotate(vector<int>& nums) {
        int i;
        for (i = 1; i < nums.size(); ++i)
            if (nums[i - 1] > nums[i]) break;
        
        if (i == nums.size()) return;
        
        reverse(begin(nums), begin(nums) + i);
        reverse(begin(nums) + i, end(nums));
        reverse(begin(nums), end(nums));
    }
};
