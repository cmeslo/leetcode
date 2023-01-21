# 118. Pascal's Triangle

## Solution

### Example

```
n = 5
```

```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

### Code

#### 寫法一

```cpp
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans{{1}};

    for (int n = 2; n <= numRows; ++n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            int left = i == 0 ? 0 : ans.back()[i - 1];
            int right = i == n - 1 ? 0 : ans.back()[i];
            nums[i] = left + right;
        }
        ans.push_back(nums);
    }
    return ans;
}
```

#### 寫法二

```cpp
res[i][j] = res[i - 1][j - 1] + res[i - 1][j]
```

```cpp
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);

    for (int i = 0; i < numRows; ++i) {
        vector<int> cur(i + 1);
        cur[0] = cur[i] = 1;
        for (int j = 1; j < i; ++j) {
            cur[j] += res[i - 1][j - 1] + res[i - 1][j];
        }
        res[i] = cur;
    }

    return res;
}
```
