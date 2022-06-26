# 2194. Cells in a Range on an Excel Sheet

```cpp
vector<string> cellsInRange(string s) {
    vector<string> ans;
    for (int i = s[0] - 'A'; i <= s[3] - 'A'; ++i) {
        for (int j = s[1] - '0'; j <= s[4] - '0'; ++j) {
            ans.push_back(string(1, (i + 'A')) + string(1, (j + '0')));
        }
    }
    return ans;
}
```
