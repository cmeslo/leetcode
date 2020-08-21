# 409. Longest Palindrome

## 409_01.cpp

```cpp
int longestPalindrome(string s) {
    unordered_map<char, int> freq;

    for (const char& c : s) freq[c]++;

    int ans = 0, odd = 0;
    for (auto& it : freq) {
        if (it.second % 2 == 0) {
            ans += it.second;
        } else {
            odd = 1;
            ans += it.second - 1;
        }
    }

    return ans + odd;
}
```

寫簡潔一點

```cpp
int longestPalindrome(string s) {
    unordered_map<char, int> freq;

    for (const char& c : s) freq[c]++;

    int ans = 0, odd = 0;
    for (auto& it : freq) {
        ans += (it.second % 2 == 0 ? it.second : it.second - 1);
        odd |= (it.second & 1);
    }

    return ans + odd;
}
```
