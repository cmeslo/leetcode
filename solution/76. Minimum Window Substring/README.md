# 76. Minimum Window Substring

## Solution 1: Sliding window + Brute force

```cpp
// Runtime: 172 ms / 403 ms

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dict;
        for (char& c : t) dict[c]++;
        
        int n = s.size();
        int start = 0, len = n + 1;
        unordered_map<char, int> window;
        for (int l = 0, r = 0; r < n; ++r) {
            window[s[r]]++;
            while (isOK(window, dict)) {
                if (r - l + 1 < len) {
                    start = l;
                    len = r - l + 1;
                }
                window[s[l++]]--;
            }
        }
        return len == n + 1 ? "" : s.substr(start, len);
    }
    
private:
    bool isOK(unordered_map<char, int>& window, unordered_map<char, int>& dict) {
        for (auto& [c, cnt] : dict) {
            if (!window.count(c)) return false;
            if (window[c] < cnt) return false;
        }
        return true;
    }
};
```
