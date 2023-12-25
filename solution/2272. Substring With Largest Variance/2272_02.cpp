class Solution {
public:
    int largestVariance(string s) {
        const int n = s.size();
        unordered_set<char> S(s.begin(), s.end());
        
        int res = 0;
        for (char a : S) {
            for (char b : S) {
                if (a == b) continue;
                int dp0 = 0, dp1 = INT_MIN / 2;
                for (int i = 0; i < n; ++i) {
                    if (s[i] == a) { // 1
                        dp0 = dp0 + 1;
                        dp1 = dp1 + 1;
                    } else if (s[i] == b) { // -1
                        dp1 = max(dp0, dp1) - 1;
                        dp0 = 0;
                    }
                    res = max(res, dp1);
                }
            }
        }
        return res;
    }
};
