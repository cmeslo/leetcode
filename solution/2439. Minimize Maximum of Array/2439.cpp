class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end()), m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (checkOK(nums, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
    
private:
    bool checkOK(vector<int>& nums, int limit) {
        long cap = 0;
        for (int x : nums) {
            cap -= x - limit;
            if (cap < 0)
                return false;
        }
        return true;
    }
};
