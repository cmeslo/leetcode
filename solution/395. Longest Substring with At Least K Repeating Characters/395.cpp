class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n < k) return 0;
        if (k <= 1) return n;
        
        vector<int> f(26, 0);
        for (const char& c : s)
            ++f[c - 'a'];
        
        int l = 0;
        while (l < n && f[s[l] - 'a'] >= k) ++l;
        if (l >= n) return n;
        int len1 = longestSubstring(s.substr(0, l), k);
        
        while (l < n && f[s[l] - 'a'] < k) ++l;
        int len2 = longestSubstring(s.substr(l), k);
        
        return max(len1, len2);
    }
};
