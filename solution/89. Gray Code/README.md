# 89. Gray Code

## Solution: mirror

```
0   00   000
1   01   001
    11   011
    10   010
         110
         111
         101
         100
```

```cpp
vector<int> grayCode(int n) {
    vector<int> ans{0};

    for (int i = 0; i < n; ++i) {
        for (int j = ans.size() - 1; j >= 0; --j) {
            ans.push_back(ans[j] | (1 << i));
        }
    }

    return ans;
}
```
