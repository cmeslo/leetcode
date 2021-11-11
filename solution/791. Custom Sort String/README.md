# 791. Custom Sort String

## Solution 1: custom sort

```cpp
string customSortString(string order, string str) {
    vector<int> dict(128);
    for (int i = 0; i < order.size(); ++i)
        dict[order[i]] = i + 1;

    sort(str.begin(), str.end(), [&](char& a, char &b) {
        return dict[a] < dict[b];
    });
    return str;
}
```
