# 1446. Consecutive Characters

```cpp
int maxPower(string s) {
    int res = 1, cur = 1;
    for (int i = 1; i < s.size(); ++i) {
        cur = s[i - 1] == s[i] ? cur + 1 : 1;
        res = max(res, cur);
    }
    return res;
}
```
