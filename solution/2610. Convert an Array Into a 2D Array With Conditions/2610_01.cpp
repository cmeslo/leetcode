class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int len = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && nums[i] == nums[j]) ++j;
            len = max(len , j - i);
            i = j - 1;
        }
        
        vector<vector<int>> res(len);
        for (int i = 0; i < n; ++i) {
            int j = i, row = 0;
            while (j < n && nums[i] == nums[j])
                res[row++].push_back(nums[j++]);
            i = j - 1;
        }
        return res;
    }
};
