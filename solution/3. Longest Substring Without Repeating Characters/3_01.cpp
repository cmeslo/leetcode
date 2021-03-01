class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        
        unordered_set<char> window;
        int l = 0, r = 0;
        while (l <= r && r < n) {
            while (window.count(s[r]))
                window.erase(s[l++]);
            window.insert(s[r]);
            ans = max(ans, r - l + 1);
            ++r;
        }
        return ans;
    }
};
