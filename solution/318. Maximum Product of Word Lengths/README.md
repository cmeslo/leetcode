# 318. Maximum Product of Word Lengths

## 解釋

把每個 string 映射到一個 int，比如考慮 "ab" 和 "cd"
```
0011 <--ab
1100 <--cd
0000 <--ab & cd = 0，代表沒有重覆字母
```
計算好每個 string 對應的 int 後，再兩兩取出，如果符合條件，就相乘並更新答案。

## Code

```cpp
// Your runtime beats 91.99 % of cpp submissions.
// Your memory usage beats 83.74 % of cpp submissions.

int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        int code = 0;
        for (char& c : words[i])
            code |= (1 << (c - 'a'));
        A[i] = code;
    }

    size_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((A[i] & A[j]) == 0)
                ans = max(ans, words[i].size() * words[j].size());
        }
    }
    return ans;
}
```

or

```cpp
// Your runtime beats 91.99 % of cpp submissions.
// Your memory usage beats 42.88 % of cpp submissions.

int maxProduct(vector<string>& words) {
    unordered_map<int, int> m;
    for (string& w : words) {
        int code = 0;
        for (char& c : w) code |= 1 << (c - 'a');
        m[code] = max(m[code], (int) w.size());
    }

    int ans = 0;
    for (auto [code1, len1] : m)
        for (auto [code2, len2] : m)
            if ((code1 & code2) == 0)
                ans = max(ans, len1 * len2);
    return ans;
}
```
