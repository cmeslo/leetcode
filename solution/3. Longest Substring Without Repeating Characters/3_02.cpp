class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> seen(256);
        for (int i = 0, j = 0; j < s.size(); ++j) {
            while (seen[s[j]])
                seen[s[i++]]--;
            
            seen[s[j]]++;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
