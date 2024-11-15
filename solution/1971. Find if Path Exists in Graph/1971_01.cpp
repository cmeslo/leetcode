class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> seen(n);
        return dfs(adj, seen, source, destination);
    }
    
    bool dfs(vector<vector<int>>& adj, vector<int>& seen, int node, int dest) {
        if (node == dest) return true;
        if (seen[node]++) return false;
        for (int next : adj[node]) {
            if (dfs(adj, seen, next, dest))
                return true;
        }
        return false;
    }
};
