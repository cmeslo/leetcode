class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            ans += extendPalindromic(s, i, i);
            ans += extendPalindromic(s, i, i + 1);
        }
        return ans;
    }

private:
    int extendPalindromic(const string& s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            ++cnt;
            --l, ++r;
        }
        return cnt;
    }
};
