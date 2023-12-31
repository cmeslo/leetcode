class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outDegree(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i])
                adj[j].push_back(i);
            outDegree[i] = graph[i].size();
            if (graph[i].empty())
                q.push(i);
        }
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int prev : adj[node]) {
                if (--outDegree[prev] == 0)
                    q.push(prev);
            }
        }
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (outDegree[i] == 0)
                res.push_back(i);
        return res;
    }
};
