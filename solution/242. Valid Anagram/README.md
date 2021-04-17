# 242. Valid Anagram

## 242.cpp

```cpp
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> cnt(26, 0);

    for (char c : s) cnt[c - 'a']++;
    for (char c : t) {
        if (--cnt[c - 'a'] < 0) return false;
    }
    return true;
}
```

Similar problem: [438. Find All Anagrams in a String](https://github.com/cmeslo/leetcode/tree/master/solution/438.%20Find%20All%20Anagrams%20in%20a%20String)
