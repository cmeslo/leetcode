class Solution {
public:
    string longestPalindrome(string s) {
        int startIndex = 0, maxLen = 1;

        for (int i = 0; i < s.size() - 1; ++i)
        {
            if(s[i] == s[i + 1]) {
                palindrome(s, i, i + 1, startIndex, maxLen); //"aaaa"
            }
            palindrome(s, i, i, startIndex, maxLen); // "aaa", "bab", "sooos"
        }
        return s.substr(startIndex, maxLen);
    }

    void palindrome(string& s, int left, int right, int& startIndex, int& maxLen) {
        int step = 1;
        while (left - step >= 0 && right + step < s.size()) {
            if (s[left - step] != s[right + step]) break;
            ++step;
        }
        
        int len = step * 2 - 1 + (right - left);

        if (maxLen < len) {
            startIndex = left - step + 1;
            maxLen = len;
        }
    }
};
