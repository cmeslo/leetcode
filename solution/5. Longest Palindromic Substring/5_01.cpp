class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        
        pair<int, int> ans = {0, 1}; // {start, len}
        for (int i = 0; i < s.length(); ++i) {
            auto str1 = getPalindrome(s, i, i + 1);
            auto str2 = getPalindrome(s, i - 1, i + 1);
            ans = str1.second > ans.second ? str1 : ans;
            ans = str2.second > ans.second ? str2 : ans;
        }

        return s.substr(ans.first, ans.second);
    }

private:
    pair<int, int> getPalindrome(string& s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l, ++r;
        }
        return {l + 1, r - l - 1};
    }
};
