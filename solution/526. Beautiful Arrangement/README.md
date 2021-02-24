# 526. Beautiful Arrangement #

## 解釋

排列加上條件 ```pos % i == 0 || i % pos == 0```，

## 526_01.cpp

使用 visited 數組實現排列

```cpp
class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        vector<int> visited(N + 1, 0);
        dfs(N, 1, visited, res);
        return res;
    }
    
    void dfs(int n, int pos, vector<int>& visited, int& res) {
        if (pos > n) {
            ++res;
            return;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 1) continue;
            if (pos % i == 0 || i % pos == 0) {
                visited[i] = 1;
                dfs(n, pos + 1, visited, res);
                visited[i] = 0;
            }
        }
    }
};
```

改成從右向左遍歷、runtime會快很多，因為從左向右時、前面的小數字容易成為別人的因子

```cpp
class Solution {
public:
    int countArrangement(int n) {
        vector<bool> used(n + 1);
        return dfs(n, n, used);
    }
    
private:
    int dfs(int n, int pos, vector<bool>& used) {
        if (pos <= 0) return 1;
        
        int ans = 0;
        for (int i = n; i >= 1; --i) {
            if (used[i]) continue;
            if (!(pos % i == 0 || i % pos == 0)) continue;
            used[i] = true;
            ans += dfs(n, pos - 1, used);
            used[i] = false;
        }
        return ans;
    }
};
```

## 526_02.cpp, 526_03.cpp

使用 swap 的方法實現排列

**right-to-left (526_02.cpp)**

```cpp
int countArrangement(int N) {
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) nums[i] = i + 1;
    return helper(N, nums);
}

int helper(int n, vector<int>& nums) {
    if (n <= 0) return 1;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (n % nums[i] == 0 || nums[i] % n == 0) {
            swap(nums[i], nums[n - 1]);
            res += helper(n - 1, nums);
            swap(nums[i], nums[n - 1]);
        }
    }
    return res;
}
```

**left-to-right (526_03.cpp)**

```cpp
int countArrangement(int N) {
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) nums[i] = i + 1;
    return helper(N, 0, nums);
}

int helper(int n, int pos, vector<int>& nums) {
    if (pos == n) return 1;

    int res = 0;
    for (int i = pos; i < n; ++i) {
        if ((pos + 1) % nums[i] == 0 || nums[i] % (pos + 1) == 0) {
            swap(nums[i], nums[pos]);
            res += helper(n, pos + 1, nums);
            swap(nums[i], nums[pos]);
        }
    }
    return res;
}
```
