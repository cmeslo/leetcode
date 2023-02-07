# 1329. Sort the Matrix Diagonally

## Solution 1: sort

沿着邊緣遊走，左下->左上->右上，

把對角線元素放到臨時數組裡，排序，再填回去。

```cpp
// Your runtime beats 93.22 % of cpp submissions.

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int h = mat.size(), w = mat[0].size();
    int y = h - 1, x = 0;

    while (y >= 0 || x <= w - 1) {
        if (y < 0) {
            ++x;
            y = 0;
        }

        vector<int> tmp;
        for (int i = y, j = x; i < h && j < w; ++i, ++j)
            tmp.push_back(mat[i][j]);

        sort(begin(tmp), end(tmp));

        for (int i = y, j = x, cnt = 0; i < h && j < w && cnt < tmp.size(); ++i, ++j)
            mat[i][j] = tmp[cnt++];

        --y;
    }
    return mat;
}
```

or

```cpp
vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    for (int j = 0; j < n; ++j) {
        vector<int> tmp;
        for (int y = 0, x = j; y < m && x < n; ++y, ++x)
            tmp.push_back(mat[y][x]);
        sort(tmp.begin(), tmp.end());
        for (int y = 0, x = j, k = 0; y < m && x < n; ++y, ++x, ++k)
            mat[y][x] = tmp[k];
    }

    for (int i = 1; i < m; ++i) {
        vector<int> tmp;
        for (int y = i, x = 0; y < m && x < n; ++y, ++x)
            tmp.push_back(mat[y][x]);
        sort(tmp.begin(), tmp.end());
        for (int y = i, x = 0, k = 0; y < m && x < n; ++y, ++x, ++k)
            mat[y][x] = tmp[k];
    }
    return mat;
}
```

## Solution 2: map + heap

利用 ```同一條對角線上的元素，i - j 是相等的``` 這個特性，

把每條對角線的 key 值 ```i - j```，映射到對應的容器上（這裡容器選擇了 min heap、方便排序），

```unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;```

代碼較簡潔，但 runtime 沒有 Solution 1 快。

```cpp
// Your runtime beats 32.28 % of cpp submissions.

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int h = mat.size(), w = mat[0].size();

    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            m[i - j].push(mat[i][j]);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            mat[i][j] = m[i - j].top(); m[i - j].pop();
        }
    }

    return mat;
}
```
