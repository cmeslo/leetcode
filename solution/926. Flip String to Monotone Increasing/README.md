# 926. Flip String to Monotone Increasing

## Solution

### 解釋

```
   0 0 1 1 0
0: 0 0 1 2 2 ,從左至右掃瞄，看看全部變成0要多少次flip
1: 3 2 1 1 1 ,從右至左掃瞄，看看全部變成1要多少次flip

f[i][0] := 把[0:i]變成0要多少次flip
f[i][1] := 把[i:]變成1要多少次flip

0 0 1 1 0
0 1 1 1 1 -> f[0][0] + f[1][1] = 2
0 0 1 1 1 -> f[1][0] + f[2][1] = 1
```

### Code

```cpp
int minFlipsMonoIncr(string s) {
    int n = s.size();
    vector<int> f0(n), f1(n);
    f0[0] = s[0] == '1';
    f1[n - 1] = s[n - 1] == '0';
    for (int i = 1; i < n; ++i) {
        f0[i] = f0[i - 1] + (s[i] == '1');
        f1[n - i - 1] = f1[n - i] + (s[n - i - 1] == '0');
    }

    int ans = min(f0[n - 1], f1[0]); // 全0 或者 全1
    for (int i = 0; i + 1 < n; ++i)
        ans = min(ans, f0[i] + f1[i + 1]);
    return ans;
}
```
