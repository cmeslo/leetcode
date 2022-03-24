# 2185. Counting Words With a Given Prefix

```cpp
int prefixCount(vector<string>& words, string pref) {
    int ans = 0;
    for (string& w : words) {
        if (w.size() >= pref.size() && w.substr(0, pref.size()) == pref)
            ++ans;
    }
    return ans;
}
```
