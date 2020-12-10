# 47. Permutations II

## 47_01.cpp
Use set to remove duplicate.

## 47_02.cpp
Sort and check previous num.

8 ms

Your runtime beats 81.74 % of cpp submissions.

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size());
        sort(begin(nums), end(nums));
        dfs(nums, used, cur, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, used, cur, ans);
            cur.pop_back();
            used[i] = false;
        }
    }
};
```

## 47_03.cpp

swap

4 ms

Your runtime beats 98.92 % of cpp submissions.

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        backtrack(nums, 0, ans);
        return ans;
    }
    
private:
    void backtrack(vector<int>& nums, int len, vector<vector<int>>& ans) {
        if (len == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        backtrack(nums, len + 1, ans);
        for (int i = 0; i < len; ++i) {
            if (nums[i] == nums[len])
                break;
            swap(nums[i], nums[len]);
            backtrack(nums, len + 1, ans);
            swap(nums[i], nums[len]);
        }
    }
};
```
