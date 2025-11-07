class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        const int n = s.size();
        
        string r = s;
        reverse(r.begin(), r.end());

        vector<int> suffix = preprocess(s);
        
        vector<int> dp(n);
        dp[0] = r[0] == s[0];
        for (int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while (j > 0 && r[i] != s[j])
                j = suffix[j - 1];
            dp[i] = j + (r[i] == s[j]);
        }
        
        string res = s.substr(dp[n - 1]);
        reverse(res.begin(), res.end());
        return res + s;
    }
    
    vector<int> preprocess(const string& s) {
        const int n = s.size();
        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            int j = dp[i - 1];
            while (j > 0 && s[i] != s[j])
                j = dp[j - 1];
            dp[i] = j + (s[i] == s[j]);
        }
        return dp;
    }
};

// 找到中間最長的 palindrome

// s = [A A] B
// r = B [A A]
