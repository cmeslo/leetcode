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

## 409_02.cpp

```cpp
int longestPalindrome(string s) {
    unordered_set<char> odds;
    for (char c : s) {
        if (!odds.count(c)) odds.insert(c);
        else odds.erase(c);
    }
    return s.size() - max(0, (int)odds.size() - 1);
}
```

## 409_03.cpp

```cpp
int longestPalindrome(string s) {
    int odds = 0;
    for (char c = 'A'; c <= 'z'; ++c) {
        odds += count(s.begin(), s.end(), c) & 1;
    }
    return s.size() - max(0, odds - 1);
}
```
