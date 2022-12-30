# 1647. Minimum Deletions to Make Character Frequencies Unique

## Solution 1: Set

```cpp
int minDeletions(string s) {
    vector<int> cnt(26);
    for (char& c : s)
        cnt[c - 'a']++;

    int res = 0;
    unordered_set<int> used;
    for (int i = 0; i < 26; ++i) {
        while (cnt[i] > 0 && !used.insert(cnt[i]).second) {
            --cnt[i];
            res++;
        }
    }
    return res;
}

// aaabbbcc
// 3 3 2
```

## Solution 2: Sort

```cpp
int minDeletions(string s) {
    vector<int> freq(26);
    for (char& c : s)
        freq[c - 'a']++;

    int keep = 0, mn = INT_MAX;
    sort(freq.rbegin(), freq.rend());
    for (int f : freq) {
        if (f == 0 || mn == 0) break;
        mn = min(f, mn - 1);
        keep += mn;
    }
    return s.size() - keep;
}

// aaabbbccde
// 3 3 2 1 1
// 3 2 1 0 0
```
