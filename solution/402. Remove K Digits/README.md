# 402. Remove K Digits

## Solution: Monotonic Stack

```cpp
string removeKdigits(string num, int k) {
    int n = num.size();
    int targetSize = n - k;

    string res;
    for (int i = 0; i < n; ++i) {
        while (!res.empty() && res.back() > num[i] && n - i + res.size() > targetSize)
            res.pop_back();
        if (res.size() < targetSize)
            res.push_back(num[i]);
    }

    int i = 0;
    while (i < res.size() && res[i] == '0') i++;
    return i == res.size() ? "0" : res.substr(i);
}
```
