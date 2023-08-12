class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> D(n);
        for (int x : edges)
            if (x != -1)
                D[x]++;
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (D[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            int next = edges[node];
            if (next != -1 && --D[next] == 0)
                q.push(next);
        }
        
        int res = -1;
        vector<int> colors(n);
        int color = 1;
        for (int i = 0; i < n; ++i) {
            if (D[i] == 0 || colors[i]) continue;
            res = max(res, dfs(edges, colors, i, color));
        }
        return res;
    }
    
private:
    int  dfs(vector<int>& edges, vector<int>& colors, int node, int color) {
        if (colors[node] == color) return 0;
        colors[node] = color;
        int next = edges[node];
        return 1 + dfs(edges, colors, next, color);
    }
};
