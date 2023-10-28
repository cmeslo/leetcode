class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        vector<int> seen(n);
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                dfs(seen, isConnected, i);
                ++res;
            }
        }
        return res;
    }
    
    void dfs(vector<int>& seen, vector<vector<int>>& isConnected, int i) {
        if (seen[i]++) return;
        for (int j = 0; j < isConnected[i].size(); ++j) {
            if (isConnected[i][j] == 1)
                dfs(seen, isConnected, j);
        }
    }
};
