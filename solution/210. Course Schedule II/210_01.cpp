class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (inDegree[i] == 0)
                q.push(i);
        
        vector<int> res;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            res.push_back(node);
            for (int next : adj[node]) {
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }
        
        for (int i = 0; i < n; ++i)
            if (inDegree[i] != 0)
                return {};
        
        return res;
    }
};
