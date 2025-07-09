class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<int>> inc(n, vector<int>(4)), dec(n, vector<int>(4));
        for (int i = 0; i < n; ++i) {
            inc[i][1] = dec[i][1] = 1;
            for (int j = 0; j < i; ++j) {
                for (int t = 2; t <= 3; ++t) {
                    if (rating[j] < rating[i]) {
                        if (inc[j][t - 1])
                            inc[i][t] += inc[j][t - 1];
                    } else if (rating[j] > rating[i]) {
                        if (dec[j][t - 1])
                            dec[i][t] += dec[j][t - 1];
                    }
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += inc[i][3] + dec[i][3];
        }
        return res;
    }
};

// . . x . . . x
//     j       i

// dp[i][3] = dp[j][2] + 1

// inc[i] = 
