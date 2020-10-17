# 39. Combination Sum

兩個解法都是 ```Your runtime beats 98.58 % of cpp submissions.```

## 沒有sort

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, int target, int start, vector<int>& cur, vector<vector<int>>& ans) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, target - nums[i], i, cur, ans);
            cur.pop_back();
        }
    }
};
```

## 有sort

區別在於，對於sort了的數組，可以及早停止循環 ```nums[i] <= target```

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, int target, int start, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = start; i < nums.size() && nums[i] <= target; ++i) {
            cur.push_back(nums[i]);
            dfs(nums, target - nums[i], i, cur, ans);
            cur.pop_back();
        }
    }
};
```
