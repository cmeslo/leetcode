class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans{{1}};

        for (int n = 2; n <= numRows; ++n) {
            vector<int> nums(n);
            for (int i = 0; i < n; ++i) {
                int left = i == 0 ? 0 : ans.back()[i - 1];
                int right = i == n - 1 ? 0 : ans.back()[i];
                nums[i] = left + right;
            }
            ans.push_back(nums);
        }
        return ans;
    }
};
