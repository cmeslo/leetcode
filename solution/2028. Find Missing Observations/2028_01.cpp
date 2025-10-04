class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int k = rolls.size() + n;
        int target = k * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (target < n) return {};
        if (target / n > 6) return {};
        if (target / n == 6 && target % n != 0) return {};
        vector<int> ans(n);
        int remainder = target % n;
        for (int i = 0; i < n; ++i) {
            ans[i] = target / n + (remainder-- > 0);
        }
        return ans;
    }
};
