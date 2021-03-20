class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < n; ++i) {
            while (!ans.empty() && ans.size() - 1 + n - i >= k && ans.back() > nums[i])
                ans.pop_back();
            if (ans.size() < k)
                ans.push_back(nums[i]);
        }
        
        return ans;
    }
};
