class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            if (!isAlphanumeric(s[left])) {
                left++; continue;
            } 
            if  (!isAlphanumeric(s[right])) {
                right--; continue;
            }
            if (toLower(s[left]) != toLower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool isAlphanumeric(char c) {
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    
    char toLower(char c) {
        return (c >= 'A' && c <= 'Z')? c + 32 : c;
    }
};
