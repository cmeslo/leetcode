# 899. Orderly Queue

## Solution:

要觀察到，當 k >= 2 時，其實順序是可以任意控制的

```cpp
string orderlyQueue(string s, int k) {
    if (k >= 2) {
        sort(s.begin(), s.end());
        return s;
    }

    string res = s;
    for (int i = 0; i < s.size(); ++i) {
        s = s.substr(1) + s.substr(0, 1);
        if (s < res)
            res = s;
    }
    return res;
}
```
