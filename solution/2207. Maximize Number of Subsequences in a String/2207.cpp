class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        using ll = long long;
        int n = text.size();
        ll ans = 0;
        
        vector<int> a(n), b(n);
        int cnt_a = 0, cnt_b = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = (i > 0 ? a[i - 1] : 0) + (text[i] == pattern[0]);
            b[i] = (i > 0 ? b[i - 1] : 0) + (text[i] == pattern[1]);

            cnt_a += text[i] == pattern[0];
            cnt_b += text[i] == pattern[1];
        }
        for (int i = 0; i < n; ++i) {
            if (text[i] == pattern[0])
                ans += b[n - 1] - b[i];
        }
        return ans + max(cnt_a, cnt_b);
    }
};
