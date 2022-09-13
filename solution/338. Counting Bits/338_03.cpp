class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i) {
            ans[i] = i % 2 ? ans[i - 1] + 1 : ans[i / 2];
        }
        return ans;
    }
};
