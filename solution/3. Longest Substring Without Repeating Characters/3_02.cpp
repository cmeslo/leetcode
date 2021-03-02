class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        vector<int> seen(256);
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            while (seen[s[i]] > 0) {
                --seen[s[start++]];
            }
            ++seen[s[i]];
            ans = max(ans, i - start + 1);
        }
        return ans;
    }
};
