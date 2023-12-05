class Solution {
public:
    long dp[201][101];
    long M = 1e9 + 7;
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        dp[fuel][start] = 1;
        
        for (int f = fuel; f >= 0; --f) {
            for (int b = 0; b < n; ++b) {
                for (int a = 0; a < n; ++a) {
                    if (a == b) continue;
                    int gas = abs(locations[a] - locations[b]);
                    if (f + gas <= fuel)
                        dp[f][b] = (dp[f][b] + dp[f + gas][a]) % M;
                }
            }
        }
        
        long res = 0;
        for (int f = 0; f <= fuel; ++f)
            res = (res + dp[f][finish]) % M;
        return res;
    }
};
