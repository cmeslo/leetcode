# 78. Subsets

## Solution 1: dfs

### 寫法一
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    dfs(nums, 0, cur, res);
    return res;
}

void dfs(vector<int>& nums, int index, vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur);
    for (int i = index; i < nums.size(); ++i) {
        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur, res);
        cur.pop_back();
    }
}
```

### 寫法二
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); i++) {
            vector<int> cur;
            dfs(nums, i, 0, cur);
        }
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    
    void dfs(const vector<int>& nums, int size, int start, vector<int>& cur) {
        if (size == cur.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(nums, size, i+1, cur);
            cur.pop_back();
        }
    }
};
```

### 寫法三

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, 0, cur, res);
        return res;
    }
    
    void dfs(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(nums, i + 1, cur, res);
        cur.pop_back();
        dfs(nums, i + 1, cur, res);
    }
};
```

## Solution 2: bit操作

### 寫法一
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < 1<<n; i++) {
        vector<int> cur;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) cur.push_back(nums[j]);
        }
        ans.push_back(cur);
    }
    return ans;
}
```

### 寫法二
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    int len = 1 << nums.size();// we have 2^n subsets
    vector<vector<int>> res;

    for (int i = 0; i < len; ++i) {
        res.push_back(convertIntToSet(nums, i));
    }
    return res;
}

vector<int> convertIntToSet(vector<int>& nums, int subInt) {
    vector<int> sub;
    int index = 0;
    for (int i = subInt; i > 0; i >>= 1) {
        if (i & 1 == 1) sub.push_back(nums[index]);
        ++index;
    }
    return sub;
}
```
