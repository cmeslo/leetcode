# 1915. Number of Wonderful Substrings

## C++

```cpp
long long wonderfulSubstrings(string word) {
    long long res = 0;
    unordered_map<int, int> prefix;
    int mask = 0;
    prefix[0] = 1;
    for (char& c : word) {
        mask ^= (1 << (c - 'a'));
        res += prefix[mask];
        for (int i = 0; i < 10; ++i) {
            if (prefix.count(mask ^ (1 << i)))
                res += prefix[mask ^ (1 << i)];
        }
        ++prefix[mask];
    }
    return res;
}
```

or

```cpp
long long wonderfulSubstrings(string word) {
    long long res = 0;
    vector<int> cnt(1 << 10);
    cnt[0] = 1;
    int state = 0;
    for (char& c : word) {
        state ^= (1 << (c - 'a'));
        res += cnt[state];
        for (int i = 0; i < 10; ++i) {
            res += cnt[state ^ (1 << i)];
        }
        ++cnt[state];
    }
    return res;
}
```
