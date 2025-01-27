class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, k, 0);
        return res - 1;
    }
    
private:
    int n, res = 0;
    int count[1001];
    
    void dfs(vector<int>& nums, int k, int i) {
        if (i == n) {
            res++;
            return;
        }
        
        dfs(nums, k, i + 1);
        
        int pre = nums[i] - k;
        if (pre <= 0 || count[pre] == 0) {
            count[nums[i]]++;
            dfs(nums, k, i + 1);
            count[nums[i]]--;
        }
    }
};


// _ x _ x _ _ x _
