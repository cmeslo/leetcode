# 2100. Find Good Days to Rob the Bank

```
5,3,3,3,5,6,2
0 1 2 3 0 0 1 <--left
0 4 3 2 1 0 0 <--right
```

```cpp
vector<int> goodDaysToRobBank(vector<int>& S, int time) {
    int n = S.size();
    vector<int> left(n), right(n);
    for (int i = 1; i < n; ++i) {
        if (S[i - 1] >= S[i])
            left[i] = left[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (S[i] <= S[i + 1])
            right[i] = right[i + 1] + 1;
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (left[i] >= time && right[i] >= time)
            res.push_back(i);
    }
    return res;
}
```
