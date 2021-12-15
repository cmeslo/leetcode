class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        piles.insert(piles.begin(), 0);
        
        for (int i = 1; i <= n; ++i)
            presum[i] = presum[i - 1] + piles[i];
        
        int gain = solve(piles, 1, n);
        return gain > presum[n] - gain;
    }
    
private:
    int presum[501];
    int memo[501][501];
    
    int solve(vector<int>& piles, int i, int j) {
        if (i == j) return piles[i];
        if (memo[i][j]) return memo[i][j];
        memo[i][j] = max(presum[j] - presum[i-1] - solve(piles, i+1, j),
                         presum[j] - presum[i-1] - solve(piles, i, j-1));
        return memo[i][j];
    }
};
