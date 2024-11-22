class Solution {
public:
    int longestIdealString(string s, int k) {
        const int n = s.size();
        int res = 0;
        vector<int> A(26);
        for (int i = 0; i < n; ++i) {
            const int a = s[i] - 'a';
            int cnt = 0;
            for (int j = max(0, a - k); j <= min(25, a + k); ++j)
                cnt = max(cnt, A[j] + 1);
            A[a] = max(A[a], cnt);
            res = max(res, A[a]);
        }
        return res;
    }
};
