# 1640. Check Array Formation Through Concatenation

## Solution 1 - 記錄 arr[i] 對應的 index

```cpp
bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> index(101, -1);
    for (int i = 0; i < arr.size(); ++i)
        index[arr[i]] = i;

    for (int i = 0; i < pieces.size(); ++i) {
        int start = index[pieces[i][0]];
        if (start == -1 || arr[start++] == 0) return false;
        for (int j = 1; j < pieces[i].size(); ++j, ++start) {
            if (start >= arr.size() || pieces[i][j] != arr[start])
                return false;
        }
    }

    return true;
}
```

## Solution 2 - 更簡潔，記錄 pieces[i][0] 對應的 index

```cpp
bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    vector<int> m(101, -1);
    for (int i = 0; i < pieces.size(); ++i)
        m[pieces[i][0]] = i;

    for (int i = 0; i < arr.size();) {
        int p = m[arr[i]], j = 0;
        if (p == -1)
            return false;
        while (j < pieces[p].size()) {
            if (arr[i++] != pieces[p][j++])
                return false;
        }
    }

    return true;
}
```
