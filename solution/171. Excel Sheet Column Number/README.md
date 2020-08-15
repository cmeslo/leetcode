# 171. Excel Sheet Column Number

```cpp
int titleToNumber(string s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += pow(26, i) * (s[n - 1 - i] - 'A' + 1);

    return ans;
}
```

or

```cpp
int titleToNumber(string s) {
    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
        ans = ans * 26 + (s[i] - 'A' + 1);
    }

    return ans;
}
```
