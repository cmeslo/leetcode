# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

```cpp
// Your runtime beats 95.03 % of cpp submissions.
// Your memory usage beats 90.46 % of cpp submissions.

int minPartitions(string n) {
    char ans = '0';
    for (char& c : n) {
        if (c > ans) ans = c;
        if (ans == '9') break;
    }
    return ans - '0';
}
```

or

```cpp
int minPartitions(string n) {
    int mx = 0;
    for (char& c : n) {
        mx = max(mx, c - '0');
    }
    return mx;
}
```

or

```cpp
int minPartitions(string n) {
    return *max_element(begin(n), end(n)) - '0';
}
```
