# 387. First Unique Character in a String

## Solution: HashMap

```cpp
int firstUniqChar(string s) {
    vector<int> f(26);

    for (char& c : s)
        ++f[c - 'a'];

    for (int i = 0; i < s.size(); ++i)
        if (f[s[i] - 'a'] == 1)
            return i;

    return -1;
}
```
