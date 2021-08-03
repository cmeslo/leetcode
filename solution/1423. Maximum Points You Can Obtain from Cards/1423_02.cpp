class Solution {
public:
    int maxScore(vector<int>& p, int k) {
        int n = p.size();
        int cur = accumulate(begin(p), begin(p) + k, 0);
        int ans = cur;
        for (int i = 0; i < k; ++i) {
            cur = cur - p[k - i - 1] + p[n - i - 1];
            ans = max(ans, cur);
        }
        return ans;
    }
};
