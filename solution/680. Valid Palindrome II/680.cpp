class Solution {
public:
    bool validPalindrome(string s) {
        int left = -1, right = s.size();
        while (++left < --right) {
            if (s[left] != s[right]) {
                return validPalindrome(s, left+1, right) || validPalindrome(s, left, right-1);
            }
        }
        return true;
    }
    
    bool validPalindrome(string s, int left, int right) {
        while(left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
