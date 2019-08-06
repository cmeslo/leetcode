class Solution {
public:
    bool isPalindrome(string s) {
        
        string new_s;
        for (char c : s) {
            if (isAlphanumeric(c)) new_s += toLower(c);
        }
        
        string reversed_new_s;
        for (int i = new_s.size() - 1; i >= 0; i--) {
            reversed_new_s += new_s[i];
        }
        
        return new_s == reversed_new_s;
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
