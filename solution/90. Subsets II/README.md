# 90. Subsets II

## Solution 1:

不斷重用已有的集合

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

## Solution 2: DFS

去重：相同的數字，如果要取 k 個，就只取前 k 個

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

or

去重：同一樹層的連續相同元素，只取第一個

```cpp
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
