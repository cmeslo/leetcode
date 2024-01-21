class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (i == j)
                    dp[i][j] = nums[i];
                else
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};



// [x] {x x x x x x}


// {x x x x x x} [x]

// dp[i][j] = max(nums[i] - dp[i + 1][j],
//                nums[j] - dp[i][j - 1])

// if dp[i][j] >= 0:
//     player1 win
