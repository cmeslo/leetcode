# 1996. The Number of Weak Characters in the Game

```cpp
    int numberOfWeakCharacters(vector<vector<int>>& P) {
        int n = P.size();
        sort(P.begin(), P.end(), [](auto& a, auto& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        int res = 0;
        int mx = INT_MIN;
        for (auto& p : P) {
            if (mx > p[1])
                ++res;
            mx = max(mx, p[1]);
        }
        return res;
    }
```
