# 1657. Determine if Two Strings Are Close

## 解釋

兩個字符串close的條件：

1. 兩個字符串是否有同樣pattern
2. 同樣的組成元素

## Code

```cpp
// Your runtime beats 94.60 % of cpp submissions.
// Your memory usage beats 95.95 % of cpp submissions.

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) return false;

    vector<int> w1(26), w2(26);
    for (char& c : word1)
        ++w1[c - 'a'];
    for (char& c : word2) {
        if (w1[c - 'a'] == 0) return false;
        ++w2[c - 'a'];
    }

    sort(begin(w1), end(w1));
    sort(begin(w2), end(w2));

    return w1 == w2;
}
```

- Time complexity: O(N)
- Space complexity: O(1)
