class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        multiset<int> s;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > limit)
                s.erase(s.find(nums[i++]));
            res = max(res, (int)s.size());
        }
        return res;
    }
};
