# 763. Partition Labels

## Solution 1 (推薦)

記錄下每個數字最後一次出現的位置 end。

從頭開始遍歷字符串 S，

在到達 end 之前、不斷延伸 end，

如果順利到達 end，代表找到了一組答案。

```cpp
vector<int> partitionLabels(string S) {
    if (S.empty()) return {};
    vector<int> last(26);
    int n = S.length();
    for (int i = 0; i < n; ++i)
        last[S[i] - 'a'] = i;

    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
        end = max(end, last[S[i] - 'a']);
        if (i == end) {
            ans.push_back(end - start + 1);
            start = end + 1;
        }
    }

    return ans;
}
```

## Solution 2: merge intervals

```cpp
vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<pair<int, int>> intervals(26, {n, -1});
    for (int i = 0; i < n; ++i) {
        auto& x = intervals[s[i] - 'a'];
        x.first = min(x.first, i);
        x.second = max(x.second, i);
    }

    vector<pair<int, int>> res;
    for (char& c : s) {
        auto& x = intervals[c - 'a'];
        if (res.empty() || res.back().second < x.first)
            res.push_back(x);
        else
            res.back().second = max(res.back().second, x.second);
    }
    vector<int> ans;
    for (auto [l, r] : res)
        ans.push_back(r - l + 1);
    return ans;
}
```
