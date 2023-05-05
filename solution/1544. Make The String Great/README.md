# 1544. Make The String Great

## Solution 1

```cpp
string makeGood(string s) {
    string res;
    for (char& c : s) {
        if (!res.empty() && ((res.back() ^ 32) == c || res.back() == (c ^ 32)))
            res.pop_back();
        else
            res.push_back(c);
    }
    return res;
}
```
