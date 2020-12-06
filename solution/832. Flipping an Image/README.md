# 832. Flipping an Image

## 832_01.cpp

```cpp
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    if (A.empty()) return {};

    int h = A.size(), w = A[0].size();
    vector<vector<int>> B(h, vector<int>(w));

    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            B[y][w - 1 - x] = 1 - A[y][x];

    return B;
}
```

## 832_02.cpp

```cpp
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    if (A.empty()) return {};

    int h = A.size(), w = A[0].size();

    for (int y = 0; y < h; ++y)
        for (int x = 0; x * 2 < w; ++x)
            if (A[y][x] == A[y][w - 1 - x])
                A[y][x] = A[y][w - 1 - x] ^= 1;

    return A;
}
```

## 832_03.cpp

```cpp
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    for (auto& row : A)
        reverse(begin(row), end(row));

    for (auto& row : A)
        for (int& i : row)
            i ^= 1;

    return A;
}
```
