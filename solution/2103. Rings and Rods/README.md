# 2103. Rings and Rods

```cpp
int countPoints(string rings) {
    int n = 0;
    for (int i = 1; i < rings.size(); i += 2)
        n = max(n, rings[i] - '0');
    n += 1;

    vector<vector<bool>> A(n, vector<bool>(3));
    for (int i = 0; i < rings.size(); i += 2) {
        int index = rings[i + 1] - '0';
        int color = 0;
        if (rings[i] == 'R')
            color = 0;
        else if (rings[i] == 'G')
            color = 1;
        else
            color = 2;
        A[index][color] = true;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i][0] && A[i][1] && A[i][2])
            ++res;
    }
    return res;
}
```
