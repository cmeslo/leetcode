# 473. Matchsticks to Square

## Solution: Brute force - DFS

```cpp
// Your runtime beats 82.39 % of cpp submissions.

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        if (sum % 4) return false;
        
        target_ = sum / 4;
        return dfs(matchsticks, 0, 0, 4);
    }
    
private:
    bool visited_[15];
    int target_;
    
    bool dfs(vector<int>& nums, int start, int cur, int group) {
        if (group == 0) return true;
        
        if (cur == target_)
            return dfs(nums, 0, 0, group - 1);
        
        for (int i = start; i < nums.size(); ++i) {
            if (visited_[i] || cur + nums[i] > target_) continue;
            visited_[i] = true;
            if (dfs(nums, i + 1, cur + nums[i], group))
                return true;
            visited_[i] = false;
        }
        
        return false;
    }
};
```

or

```cpp
// Your runtime beats 41.35 % of cpp submissions.

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        return dfs(matchsticks, 0, sides, sum / 4);
    }
    
private:
    bool dfs(vector<int>& nums, int index, vector<int>& sides, int target) {
        if (index == nums.size())
            return sides[0] == sides[1] && sides[1] == sides[2];
        
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + nums[index] > target) continue;
            sides[i] += nums[index];
            if (dfs(nums, index + 1, sides, target))
                return true;
            sides[i] -= nums[index];
        }
        return false;
    }
};
```

or

```cpp
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4) return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        visited.resize(matchsticks.size());
        
        return dfs(matchsticks, 0, 4, total / 4, 0);
    }
    
private:
    vector<int> visited;
    
    bool dfs(vector<int>& M, int start, int sides, int target, int sum) {
        if (sides == 0) return true;
        if (sum > target) return false;
        if (sum == target) return dfs(M, 0, sides - 1, target, 0);
        
        unordered_set<int> seen; // 加速方法，在DFS搜索樹的同一層、已經用過相同長度的火柴而又沒有成功的、可以跳過了
        for (int i = start; i < M.size(); ++i) {
            if (visited[i] || seen.count(M[i])) continue;
            visited[i] = 1;
            seen.insert(M[i]);
            if (dfs(M, i + 1, sides, target, sum + M[i]))
                return true;
            visited[i] = 0;
        }
        return false;
    }
};
```
