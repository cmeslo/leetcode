class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        mem.resize(piles.size(), vector<int>(k + 1, -1));
        return dp(piles, k, 0);
    }
    
private:
    vector<vector<int>> mem;
    
    int dp(vector<vector<int>>& piles, int k, int i) {
        if (i == piles.size() || k == 0) return 0;
        if (mem[i][k] != -1) return mem[i][k];
        
        int res = dp(piles, k, i + 1);
        int sum = 0;
        int limit = min(k, (int)piles[i].size());
        for (int j = 0; j < limit; ++j) {
            sum += piles[i][j];
            res = max(res, sum + dp(piles, k - j - 1, i + 1));
        }
        return mem[i][k] = res;
    }
};
