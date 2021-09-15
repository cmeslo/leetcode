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
