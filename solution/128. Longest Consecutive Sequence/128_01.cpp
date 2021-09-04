class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        set<int> s;
        for (int x : nums) s.insert(x);
        
        int ans = 1, cnt = 1;
        auto it = s.begin(); ++it;
        for (; it != s.end(); ++it) {
            if (*prev(it) + 1 == *it) ++cnt;
            else cnt = 1;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
