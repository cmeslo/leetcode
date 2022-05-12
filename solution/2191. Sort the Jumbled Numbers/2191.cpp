class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = {helper(mapping, nums[i]), i};
        }
        sort(A.begin(), A.end());
        vector<int> ans;
        for (auto [x, i] : A)
            ans.push_back(nums[i]);
        return ans;
    }
    
    int helper(vector<int>& m, int x) {
        int res = 0;
        string s = to_string(x);
        for (int i = 0; i < s.size(); ++i) {
            res = res * 10 + m[s[i] - '0'];
        }
        return res;
    }
};
