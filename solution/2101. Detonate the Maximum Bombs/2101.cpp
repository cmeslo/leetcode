class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long x2 = bombs[j][0], y2 = bombs[j][1];
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, bfs(adj, i));
        return res;
    }
    
    int bfs(vector<vector<int>>& adj, int src) {
        queue<int> q;
        vector<int> seen(adj.size());
        seen[src] = 1;
        q.push(src);
        int res = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            res++;
            for (int next : adj[node]) {
                if (seen[next]++) continue;
                q.push(next);
            }
        }
        return res;
    }
};
