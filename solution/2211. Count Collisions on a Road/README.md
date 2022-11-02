# 2211. Count Collisions on a Road

```cpp
int countCollisions(string D) {
    int n = D.size();
    for (int i = 1; i < n; ++i) {
        if (D[i - 1] == 'R' && D[i] == 'L')
            D[i - 1] = D[i] = 'X';
        else if (D[i - 1] == 'R' && D[i] == 'S')
            D[i - 1] = 'X';
        else if (D[i - 1] == 'S' && D[i] == 'L')
            D[i] = 'X';
    }
    for (int i = n - 1; i >= 1; --i) {
        if (D[i - 1] == 'R' && D[i] == 'X')
            D[i - 1] = 'X';
    }
    for (int i = 1; i < n; ++i) {
        if (D[i - 1] == 'X' && D[i] == 'L')
            D[i] = 'X';
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (D[i] == 'X')
            ++ans;
    return ans;
}
```
