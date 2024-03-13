class Solution {
public:
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            count(s, i, i);
            count(s, i, i + 1);
        }
        return s.substr(start, len);
    }

private:
    int start = 0, len = 0;

    void count(string& s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l, ++r;
        }
        ++l, --r;
        if (r - l + 1 > len) {
            start = l;
            len = r - l + 1;
        }
    }
};
