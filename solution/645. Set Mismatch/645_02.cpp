class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> m(n + 1);
        for (int x : nums)
            ++m[x];
        
        vector<int> ans(2);
        for (int x = 1; x <= n; ++x) {
            if (m[x] == 2)
                ans[0] = x;
            if (m[x] == 0)
                ans[1] = x;
            if (ans[0] && ans[1])
                return ans;
        }
        return ans;
    }
};
