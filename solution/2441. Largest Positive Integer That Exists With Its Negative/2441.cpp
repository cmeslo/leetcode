class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = -1;
        for (int x : nums) {
            if (s.count(-x))
                res = max(res, abs(x));
        }
        return res;
    }
};
