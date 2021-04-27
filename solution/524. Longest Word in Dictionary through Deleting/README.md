# 524. Longest Word in Dictionary through Deleting

## 解釋

把 dictionary 排序，從最長試到最短，如果檢查途中有一個符合的 word，那就是最長的答案。

### Code

```cpp
// Your runtime beats 97.23 % of cpp submissions.
// Your memory usage beats 82.02 % of cpp submissions.

string findLongestWord(string s, vector<string>& d) {
    sort(begin(d), end(d), [&](const string& a, const string& b) {
        return (a.size() > b.size()) || (a.size() == b.size() && a < b);
    });

    for (const auto& word : d) {
        int i = 0;
        for (const char& c : s) {
            if (c == word[i]) ++i;
            if (i == word.size()) break;
        }
        if (i == word.size())
            return word;
    }

    return "";
}
```
