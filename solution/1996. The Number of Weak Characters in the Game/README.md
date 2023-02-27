# 1996. The Number of Weak Characters in the Game

## Solution 1

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

## Solution 2: Monotonic stack

```cpp
int numberOfWeakCharacters(vector<vector<int>>& P) {
    int n = P.size();
    sort(P.begin(), P.end(), [](auto& a, auto& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    int res = 0;
    stack<int> st;
    for (auto& p : P) {
        while (!st.empty() && st.top() < p[1]) {
            ++res;
            st.pop();
        }
        st.push(p[1]);
    }
    return res;
}
```
