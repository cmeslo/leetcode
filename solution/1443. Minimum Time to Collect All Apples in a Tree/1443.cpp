class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<unordered_set<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        int apple_cnt = dfs(adj, hasApple, 0, -1);
        
        int res = 0;
        dfs2(adj, 0, -1, res);
        return res - 1;
    }

    int dfs(vector<unordered_set<int>>& adj, vector<bool>& hasApple, int node, int parent) {
        int cnt = hasApple[node];
        vector<int> del;
        for (int next : adj[node]) {
            if (next == parent) continue;
            int child_cnt = dfs(adj, hasApple, next, node);
            if (child_cnt == 0)
                del.push_back(next);
            cnt += child_cnt;
        }

        for (int next : del)
            adj[node].erase(next);

        return cnt;
    }

    void dfs2(vector<unordered_set<int>>& adj, int node, int parent, int& res) {
        ++res;
        for (int next : adj[node]) {
            if (next == parent) continue;
            dfs2(adj, next, node, res);
            ++res;
        }
    }
};
