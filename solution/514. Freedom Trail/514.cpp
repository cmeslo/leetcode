class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int m = ring.size(), n = key.size();
        
        unordered_map<char, vector<int>> letter2pos;
        for (int i = 0; i < m; ++i)
            letter2pos[ring[i]].push_back(i);
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        for (int pos : letter2pos[key[0]])
            dp[0][pos] = min(dp[0][pos], min(pos, m - pos));
        
        for (int i = 1; i < n; ++i) {
            for (int pos : letter2pos[key[i]]) {
                for (int pre_pos : letter2pos[key[i - 1]]) {
                    int diff = abs(pos - pre_pos);
                    dp[i][pos] = min(dp[i][pos], dp[i - 1][pre_pos] + min(diff, m - diff));
                }
            }
        }
        
        int res = INT_MAX;
        for (int pos : letter2pos[key[n - 1]])
            res = min(res, dp[n - 1][pos]);
        return res + n;
    }
};


// gd

// dp[i][d1] = dp[i-1][g1] + step(g1->d1)
//             dp[i-1][g2] + step(g2->d1)
    
// dp[i][d2] = dp[i-1][g1] + step(g1->d2)
//             dp[i-1][g2] + step(g2->d2)
