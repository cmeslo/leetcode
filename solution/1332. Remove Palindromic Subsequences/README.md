# 1332. Remove Palindromic Subsequences

```cpp
class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        return isPalindrome(s) ? 1 : 2;
    }
    
private:
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};
```
