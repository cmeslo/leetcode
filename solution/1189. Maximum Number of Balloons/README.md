# 1189. Maximum Number of Balloons

```cpp
int maxNumberOfBalloons(string text) {
    vector<int> f(26);
    for (char& c : text)
        ++f[c - 'a'];

    int ans = 0;
    int b = 1;
    int a = 0;
    int l = 'l' - 'a';
    int o = 'o' - 'a';
    int n = 'n' - 'a';
    while (f[b] && f[a] && f[l] >= 2 && f[o] >= 2 && f[n]) {
        ++ans;
        f[b]--;
        f[a]--;
        f[l] -= 2;
        f[o] -= 2;
        f[n]--;
    }
    return ans;
}
```
