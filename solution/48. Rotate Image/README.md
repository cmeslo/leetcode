# 48. Rotate Image

## 48_01.cpp
```cpp
for (int i = 0; i < n / 2; ++i) {
    for (int j = i; j < n - 1 - i; ++j) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = tmp;
    }
}
```

Example:
```
1 2 3       7 2 1      7 4 1
4 5 6  -->  4 5 6  --> 8 5 2
7 8 9       9 8 3      9 6 3
```

### Loop

we need to convert n/2 times
```cpp
for (int i = 0; i < n / 2; ++i)
```

from outside to inside, smaller and smaller
```cpp
for (int j = i; j < n - 1 - i; ++j)
```

### Position thinking
Take the example above, and convert it one by one:
```
(0, 0) --> (0, 2)
(0, 2) --> (2, 2)
(2, 2) --> (2, 0)
(2, 0) --> (0, 0)

matrix[i][j]                  --> matrix[j][n - 1 - i]
matrix[j][n - 1 - i]          --> matrix[n - 1 - i][n - 1 - j]
matrix[n - 1 - i][n - 1 - j]  --> matrix[n - 1 - j][i]
matrix[n - 1 - j][i]          --> matrix[i][j]
```
