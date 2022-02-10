# 565. Array Nesting

## Solution 1: 565_01.cpp

增加一個 visited 數組去記錄是否被訪問過。

```cpp
int arrayNesting(vector<int>& nums) {
    int n = nums.size();
    int max_group_size = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int group_size = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = nums[j];
                ++group_size;
            }
            max_group_size = max(max_group_size, group_size);
        }
    }
    return max_group_size;
}
```

## Solution 2: 565_02.cpp

可以不使用額外的 visited 數組，用替換的方法，關鍵是 <strong>使數字出現在正確的位置上</strong>。

```cpp
int arrayNesting(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int group_size = 1;
        while (nums[i] != i) {
            swap(nums[i], nums[nums[i]]);
            ++group_size;
        }
        res = max(res, group_size);
    }
    return res;
}
```

### 例子

```
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2
```

比如第一個while循環的過程：

```
A[0] = 6, A[5] = 5
A[0] = 2, A[6] = 6
A[0] = 0, A[2] = 2
```

使到 0, 5, 6, 2 都出現在正確的位置上，不會再被遍歷，略過使用額外的 visited 數組。


## Solution 3: Union Find

因為有分組，所以也可以用 Union Find 解，

不過不及 Solution 1 和 Solution 2(最快) 兩個方法快

```cpp
class UFS {
public:
    vector<int> parent;
    UFS(int n): parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    };
    
    void merge(int i, int j) {
        i = find(i), j = find(j);
        if (i < j)
            parent[j] = i;
        else
            parent[i] = j;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        UFS ufs(n);
        for (int i = 0; i < n; ++i) {
            if (ufs.find(i) != ufs.find(nums[i]))
                ufs.merge(i, nums[i]);
        }
        int res = 0;
        unordered_map<int, int> m;
        for (int x : nums) {
            int parent_x = ufs.find(x);
            res = max(res, ++m[parent_x]);
        }
        return res;
    }
};
```
