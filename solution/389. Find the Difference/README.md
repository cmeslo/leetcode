# 389. Find the Difference

## Solution 1: XOR

```cpp
char findTheDifference(string s, string t) {
    int ans = 0;
    for (char c : s) ans ^= (c - 'a');
    for (char c : t) ans ^= (c - 'a');
    return ans + 'a';
}
```

or

```cpp
char findTheDifference(string s, string t) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans ^= (s[i] - 'a');
        ans ^= (t[i] - 'a');
    }
    ans ^= t[t.length() - 1] - 'a';
    return ans + 'a';
}
```

## Solution 2: Counter

```cpp
char findTheDifference(string s, string t) {
    vector<int> f(26);
    for (char& c : s)
        f[c - 'a']++;
    for (char& c : t)
        if (--f[c - 'a'] < 0)
            return c;
    return '0';
}
```
