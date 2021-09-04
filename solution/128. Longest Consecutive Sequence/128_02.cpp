class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int ans = 0;
        for (int x : nums) {
            if (s.count(x - 1)) continue;
            int cnt = 0;
            while (s.count(x++)) ++cnt;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
