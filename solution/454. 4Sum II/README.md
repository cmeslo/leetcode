# 454. 4Sum II

```cpp
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> m;
    for (int a : A)
        for (int b : B)
            ++m[a + b];

    int ans = 0;
    for (int c : C)
        for (int d : D) {
            auto it = m.find(- c - d);
            if (it != m.end())
                ans += it->second;
        }

    return ans;
}
```
