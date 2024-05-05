class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int n = nums.size();
        vector<int> count(n + 1); // nums[i] <= nums.length
        
        vector<vector<int>> res;
        for (int x : nums) {
            if (count[x] >= res.size())
                res.push_back({});
            res[count[x]++].push_back(x);
        }
        
        return res;
    }
};
