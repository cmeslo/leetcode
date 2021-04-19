class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n); // 0: unknow, 1: red, -1: blue
        for (int i = 0; i < n; ++i)
            if (colors[i] == 0 && !dfs(graph, i, 1, colors))
                return false;
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& g, int i, int color, vector<int>& colors) {
        if (colors[i] != 0) return colors[i] == color;
        
        colors[i] = color;
        for (int next : g[i])
            if (!dfs(g, next, -color, colors))
                return false;
        
        return true;
    }
};
