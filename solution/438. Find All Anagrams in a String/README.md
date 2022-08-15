# 438. Find All Anagrams in a String

## 438_01.cpp
Use array to count letters of string p, and then check every p.size().

```cpp
vector<int> findAnagrams(string s, string p) {
    vector<int> f(26);
    for (char& c : p)
        f[c - 'a']++;

    vector<int> res;
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i >= p.size()) {
            if (++f[s[i - p.size()] - 'a'] > 0)
                count--;
        }
        if (f[s[i] - 'a']-- > 0) {
            if (++count == p.size())
                res.push_back(i - p.size() + 1);
        }
    }
    return res;
}
```

## 438_02.cpp

```cpp
vector<int> findAnagrams(string s, string p) {
    if (s.empty()) return {};
    vector<int> res;
    vector<int> m1(26, 0), m2(26, 0);
    for (int i = 0; i < p.size(); ++i) {
        m1[s[i] - 'a']++;
        m2[p[i] - 'a']++;
    }
    if (m1 == m2) res.push_back(0);

    for (int i = p.size(); i < s.size(); ++i) {
        --m1[s[i - p.size()] - 'a'];
        ++m1[s[i] - 'a'];
        if (m1 == m2) res.push_back(i - p.size() + 1);
    }

    return res;
}
```
Make m1 a fixed window of string s, move char by char.

## 438_03.cpp

Sliding window with left and right pointer

```cpp
vector<int> findAnagrams(string s, string p) {
    if (s.empty()) return {};
    
    vector<int> m(26, 0);
    for (char c : p) m[c - 'a']++;
    
    vector<int> res;
    int left = 0, right = 0, cnt = p.size();
    while (right < s.size()) {
        // if m[right] > 0 after subtract, it means we got one char (cnt--). And right pointer move forward.
        if (m[s[right++] - 'a']-- > 0) cnt--;
        // if cnt == 0, got all char in p
        if (cnt == 0) res.push_back(left);
        // if m[left] >= 0 after subtract, means s[left] is one of the char in p (abandon it, we make cnt++). And left pointer move forward
        if (right - left == p.size() && m[s[left++] - 'a']++ >= 0) cnt++;
    }
    return res;
}
```
