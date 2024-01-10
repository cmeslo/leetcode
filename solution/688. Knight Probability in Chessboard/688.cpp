class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        const vector<pair<int, int>> dirs = {
            {1, 2}, {1, -2}, {2, 1}, {2, -1},
            {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}
        };
        vector<vector<double>> dp1(n, vector<double>(n));
        dp1[row][column] = 1;
        
        while (k--) {
            vector<vector<double>> dp2(n, vector<double>(n));
            // 方法一: 拉dp
            // for (int i = 0; i < n; ++i) {
            //     for (int j = 0; j < n; ++j) {
            //         for (int t = 0; t < 8; ++t) {
            //             int y = i + dirs[t].first;
            //             int x = j + dirs[t].second;
            //             if (y < 0 || y >= n || x < 0 || x >= n) continue;
            //             dp2[i][j] += dp1[y][x] * 1/8;
            //         }
            //     }
            // }
            //
            // 方法二: 推dp, 代碼一模一樣的, 只換了 i,j 和 y,x
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < n; ++x) {
                    for (int t = 0; t < 8; ++t) {
                        int i = y + dirs[t].first;
                        int j = x + dirs[t].second;
                        if (i < 0 || i >= n || j < 0 || j >= n) continue;
                        dp2[i][j] += dp1[y][x] * 1/8;
                    }
                }
            }
            dp1 = dp2;
        }
        
        double res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += dp1[i][j];
            }
        }
        return res;
    }
};

// A => B1, B2
// 	 B1 -> C1, C2
// 	 B2 => C1, C2

// f(A->C1) = f(A->B1)*f(B1->C1) + f(A->B2)*f(B2->C1)

// dp[C1] = dp[B1]*f(B1->C1) + dp[B2]*f(B2->C1)


// 方法一: 拉dp
// dp2[i][j] = sum(dp1[y][x] * 1/8) for 8*{y, x} 

// 方法二: 推dp
// dp2[i][j] += dp1[y][x] * 1/8 for 8*{i,j}
