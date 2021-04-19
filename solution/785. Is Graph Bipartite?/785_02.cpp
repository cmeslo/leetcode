class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n); // 0: unknow, 1: red, -1: blue
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (colors[i] != 0) continue;
            colors[i] = 1;
            q.push(i);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int next : graph[cur]) {
                    if (colors[next] == colors[cur]) return false;
                    if (colors[next] != 0) continue;
                    colors[next] = -colors[cur];
                    q.push(next);
                }
            }
        }
        return true;
    }
};
