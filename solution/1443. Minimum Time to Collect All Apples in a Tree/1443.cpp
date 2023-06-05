class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        dfs(adj, hasApple, 0, -1, res);
        return res - 1; // 第一次進入 0 節點不算
    }

    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int node, int parent, int& res) {
        ++res; // 第一次踩這個節點
        int apple_cnt = hasApple[node];
        for (int next : adj[node]) {
            if (next == parent) continue;
            int old_res = res;
            int cnt = dfs(adj, hasApple, next, node, res);
            ++res; // dfs完回來, 再踩一次這個點
            if (cnt == 0) { // 這棵子樹沒有蘋果
                res = old_res; // 所以這棵子樹下走過的步數都作廢
            }
            apple_cnt += cnt;
        }
        return apple_cnt;
    }
};
