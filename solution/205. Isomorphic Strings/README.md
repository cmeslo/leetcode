# 205. Isomorphic Strings

## Solution 1: map

### 寫法一：用 character 做 mapping
```cpp
bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> dict1(128, -1), dict2(128, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (dict1[s[i]] != -1 && dict2[t[i]] != -1) {
            if (dict1[s[i]] != t[i] || s[i] != dict2[t[i]])
                return false;
        } else if (dict1[s[i]] == -1 && dict2[t[i]] == -1) {
            dict1[s[i]] = t[i];
            dict2[t[i]] = s[i];
        } else {
            return false;
        }
    }

    return true;
}
```

### 寫法二（推薦）：用 index 做 mapping

```cpp
bool isIsomorphic(string s, string t) {
    vector<int> m1(128, -1), m2(128, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = i;
        m2[t[i]] = i;
    }
    return true;
}
```
