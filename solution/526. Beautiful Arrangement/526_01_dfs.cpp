class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        vector<int> visited(N + 1, 0);
        dfs(N, 1, visited, res);
        return res;
    }
    
    void dfs(int n, int pos, vector<int>& visited, int& res) {
        if (pos > n) {
            ++res;
            return;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == 1) continue;
            if (pos % i == 0 || i % pos == 0) {
                visited[i] = 1;
                dfs(n, pos + 1, visited, res);
                visited[i] = 0;
            }
        }
    }
};
