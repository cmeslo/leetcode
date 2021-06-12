class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        m = matrix.size(), n = matrix[0].size();
        colors.resize(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i)
            dfs(matrix, i, 0, 1);
        for (int j = 0; j < n; ++j)
            dfs(matrix, 0, j, 1);
        for (int i = 0; i < m; ++i)
            dfs(matrix, i, n - 1, -1);
        for (int j = 0; j < n; ++j)
            dfs(matrix, m - 1, j, -1);
            
        return ans;
    }
    
private:
    int m, n;
    const vector<int> dirs {0, -1, 0, 1, 0};
    vector<vector<int>> colors; // 0: unknow, 1: red, -1: blue
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& matrix, int y, int x, int color) {
        if (colors[y][x] == color) return;
        if (colors[y][x] == - color) ans.push_back({y, x});
        
        colors[y][x] = color;
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i];
            int nx = x + dirs[i + 1];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (matrix[y][x] > matrix[ny][nx]) continue;
            dfs(matrix, ny, nx, color);
        }
    }
};
