# 1647. Minimum Deletions to Make Character Frequencies Unique

## Solution 1: set

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
