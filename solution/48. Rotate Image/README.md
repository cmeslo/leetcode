# 48. Rotate Image

## Solution 1: 48_01.cpp

### Explanation
Example:
```
1 2 3       7 2 1      7 4 1
4 5 6  -->  4 5 6  --> 8 5 2
7 8 9       9 8 3      9 6 3
```

#### Loop
we need to convert n/2 times
```cpp
for (int i = 0; i < n / 2; ++i)
```

from outside to inside, smaller and smaller
```cpp
for (int j = i; j < n - 1 - i; ++j)
```

#### Thinking processes
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

### Code

```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - 1 - i; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}
```

## Solution 2: 48_02.cpp

### Explanation
First, rotate by diagonal, then upside down by x-axis to get the result.

```
1 2 3       9 6 3      7 4 1
4 5 6  -->  8 5 2  --> 8 5 2
7 8 9       7 4 1      9 6 3
```

#### 1. Rotate by diagonal
```
(0, 0) --> (2, 2)
(0, 1) --> (1, 2)
(0, 2) --> (0, 2)

(1, 0) --> (2, 1)
(1, 1) --> (1, 1)

(2, 0) --> (2, 0)
```

#### 2. Upside down
```
(0, 0) --> (2, 0)
(0, 1) --> (2, 1)
(0, 2) --> (2, 2)
```

### Code
```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // 1. Rotate by diagonal
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i; ++j) {
            swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        }
    }

    // 2. Upside down
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}
```

or

```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
        for (int k = i + 1; k < n; ++k)
            swap(matrix[i][k], matrix[k][i]);

    for (int i = 0; i < n; ++i)
        for (int l = 0, r = n - 1; l < r; ++l, --r)
            swap(matrix[i][l], matrix[i][r]);
}
```

## Solution 3: 48_03.cpp
Get transpose, then reverse left and right sides.

```
1 2 3       1 4 7      7 4 1
4 5 6  -->  2 5 8  --> 8 5 2
7 8 9       3 6 9      9 6 3
```

### Code
```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}
```
