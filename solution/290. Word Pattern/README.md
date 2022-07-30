# 290. Word Pattern

## Solution: Hashmap

```cpp
bool wordPattern(string pattern, string str) {
    unordered_map<char, int> m1;
    unordered_map<string, int> m2;
    istringstream iss(str);

    int i = 0, n = pattern.length();
    for (string word; iss >> word; ++i) {
        if (i == n || m1[pattern[i]] != m2[word])
            return false;
        m1[pattern[i]] = m2[word] = i + 1; // i + 1 to avoid default 0
    }

    return i == n;
}
```
