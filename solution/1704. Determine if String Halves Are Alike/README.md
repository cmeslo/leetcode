# 1704. Determine if String Halves Are Alike

```cpp
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        if (n & 1) return false;
        
        int len = n / 2;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < len; ++i) {
            if (isVowel(s[i])) ++cnt1;
            if (isVowel(s[i + len])) ++cnt2;
        }
        return cnt1 == cnt2;
    }
    
private:
    bool isVowel(const char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
```
