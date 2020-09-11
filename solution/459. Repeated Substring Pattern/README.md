# 459. Repeated Substring Pattern

## Stupid solution:

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 0; i < s.length() / 2; ++i) {
            string sub = s.substr(0, i + 1);
            if (backtrack(s, sub)) return true;
        }
        
        return false;
    }
    
private:
    bool backtrack(const string& s, string sub) {
        if (s.length() % sub.length() != 0) return false;
        if (s == sub) return true;
        
        if (s.substr(0, sub.length()) != sub)
            return false;
        else
            return backtrack(s.substr(sub.length()), sub);
    }
};
```

## 459.cpp

```cpp
bool repeatedSubstringPattern(string s) {
    int n = s.length();

    for (int k = n / 2; k > 0; --k) {
        if (n % k != 0) continue;
        string sub = s.substr(0, k);

        int i;
        for (i = 0; i < n; i += k)
            if (sub != s.substr(i, k)) break;

        if (i >= n) return true;
    }

    return false;
}
```
