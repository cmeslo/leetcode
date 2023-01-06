class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int x : nums)
            s.insert(x);
        
        int res = 0, len = 0;
        int pre = INT_MIN;
        for (int x : s) {
            len = pre + 1 == x ? len + 1 : 1;
            pre = x;
            res = max(res, len);
        }
        return res;
    }
};
