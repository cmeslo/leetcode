# 763. Partition Labels

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
