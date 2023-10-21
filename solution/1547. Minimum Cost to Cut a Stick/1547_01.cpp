class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        memo.resize(m, vector<int>(m, INF));
        
        return dfs(0, m - 1, cuts);
    }
    
private:
    vector<vector<int>> memo;
    const int INF = 1e9;
    
    int dfs(int i, int j, vector<int>& cuts) {
        if (i >= j) return 0;
        if (i + 1 == j) return 0;
        if (memo[i][j] != INF) return memo[i][j];
        
        for (int k = i + 1; k < j; ++k) {
            memo[i][j] = min(memo[i][j], cuts[j] - cuts[i] + dfs(i, k, cuts) + dfs(k, j, cuts));
        }
        return memo[i][j];
    }
};


// x x x | x x x x x
// i   k           j

// (j - i) + dfs(i, k) + dfs(k, j)

