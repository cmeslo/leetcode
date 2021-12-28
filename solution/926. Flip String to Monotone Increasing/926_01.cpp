class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> f0(n), f1(n);
        f0[0] = s[0] == '1';
        f1[n - 1] = s[n - 1] == '0';
        for (int i = 1; i < n; ++i) {
            f0[i] = f0[i - 1] + (s[i] == '1');
            f1[n - i - 1] = f1[n - i] + (s[n - i - 1] == '0');
        }
        
        int ans = min(f0[n - 1], f1[0]); // 全0 或者 全1
        for (int i = 0; i + 1 < n; ++i)
            ans = min(ans, f0[i] + f1[i + 1]);
        return ans;
    }
};
