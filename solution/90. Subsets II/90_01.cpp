class Solution {
public:
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
};
