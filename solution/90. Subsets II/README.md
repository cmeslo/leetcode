# 90. Subsets II

## Solution 1:

不斷重用已有的集合

去重複：

```
1, 2, 2

    {}
1:  {},{1}
2:  {},{1},{2},{1,2}
            ^--> next time start from here.
2:  {},{1},{2},{1,2},{2,2},{1,2,2}
```

### 寫法一：
```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res{vector<int>{}};
    if (nums.empty()) return res;

    sort(nums.begin(), nums.end());

    int size = 1, last = nums[0];
    for (int i = 0; i < nums.size(); ++i)
    {
        if (last != nums[i]) {
            last = nums[i];
            size = res.size();
        }
        int realSize = res.size();
        for (int j = realSize - size; j < realSize; ++j) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}
```

### 寫法二：

```cpp
// Your runtime beats 100.00 % of cpp submissions.
// Your memory usage beats 96.31 % of cpp submissions.

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res{{}};
    sort(nums.begin(), nums.end());
    int pre_start = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        pre_start = res.size();
        if (i > 0 && nums[i - 1] != nums[i])
            start = 0;
        for (int j = res.size() - 1; j >= start; --j) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
        start = pre_start;
    }
    return res;
}
```

or

```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res{{}};
    sort(nums.begin(), nums.end());
    int pre_start = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        start = i > 0 && nums[i - 1] != nums[i] ? 0 : pre_start;
        pre_start = res.size();
        for (int j = res.size() - 1; j >= start; --j) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}
```

## Solution 2: DFS

### 寫法一：

用輔助數組 visited 去重複：相同的數字，如果要取 k 個，就只取前 k 個

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        visited.resize(n);
        
        sort(nums.begin(), nums.end());
        
        vector<int> cur;
        dfs(nums, 0, cur);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> visited;
    
    void dfs(vector<int>& nums, int start, vector<int>& cur) {
        res.push_back(cur);
        
        for (int i = start; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]) continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur);
            cur.pop_back();
            visited[i] = false;
        }
    }
};
```

### 寫法二：

去重複：同一樹層的連續相同元素，只取第一個

```cpp
// Your runtime beats 100.00 % of cpp submissions.
// Your memory usage beats 55.53 % of cpp submissions.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums, 0, path, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, int s, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for (int i = s; i < nums.size(); ++i) {
            if (i > s && nums[i - 1] == nums[i]) continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, ans);
            path.pop_back();
        }
    }
};
```
