# 76. Minimum Window Substring

## Solution 1: Sliding window + Brute force

```cpp
// Runtime: 172ms or 403ms

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

## Solution 2: Sliding window + Counting

```cpp
// Runtime: 3ms or 4ms
// Your runtime beats 98.80 % of cpp submissions.
// Your memory usage beats 83.13 % of cpp submissions.

string minWindow(string s, string t) {
    vector<int> need(128);
    for (char& c : t) need[c]++;

    int n = s.size();
    int cnt = 0, l = 0, len = n + 1;
    for (int i = 0, j = 0; j < n; ++j) {
        if (need[s[j]]-- > 0) ++cnt;
        while (cnt == t.size()) {
            if (j - i + 1 < len) {
                l = i;
                len = j - i + 1;
            }
            if (++need[s[i++]] > 0) --cnt;
        }
    }
    return len == n + 1 ? "" : s.substr(l, len);
}
```
