class Solution {
public:
    //sliding windows
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        int n = nums.size();
        if (n < 2) return false;
        for (int i = 0; i < n; ++i) {
            if (k < i) s.erase(nums[i - k - 1]);
            if (!s.insert(nums[i]).second) return true;
        }
        return false;
    }
};
