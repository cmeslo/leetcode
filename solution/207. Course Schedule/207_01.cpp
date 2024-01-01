class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            adj[a].push_back(b);
            inDegree[b]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int next : adj[node]) {
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] != 0)
                return false;
        }
        return true;
    }
};
