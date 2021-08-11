class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [&](string& a, string& b) {
            return a.size() < b.size();
        });
        
        int ans = 0;
        unordered_map<string, int> dp;
        for (string& w : words) {
            for (int i = 0; i < w.size(); ++i) {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};
